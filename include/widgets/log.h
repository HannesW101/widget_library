/// @file log.h
/// @brief Thread-safe console logger with colored output and source location

#ifndef LOG_H
#define LOG_H

/*
    Log class — header only, thread safe console logger.

    Quick usage:

    #include "log.h"
    LOG(INFO) << "message" << value;

    use LOG_LVL:: to see all available log levels.


    Key behavior:

    - LOG(...) creates a temporary Log that buffers operator<< inputs and
    flushes on destruction (end of statement). No need for std::endl.

    - Output includes: colored level, time (HH:MM:SS), filename, line,
    function, and the user message.


    Configuration:

    - ENABLED_LOG_LVLS: bitmask to enable/disable levels.

    - LOG_SPECIFIC_FILE_ONLY: "ALL" or a filename to restrict which files
    produce output.


    Thread safety & guarantees:

    - A static mutex (s_mutex) serializes console writes so entries
    are not interleaved between threads.

    - Copy/move constructors are deleted to ensure flush happens at
    end of statement (temporary object idiom).


    Notes / limitations:

    - Writes to std::cout only; no file logging.

    - Uses ostringstream + mutex on flush, suitable for diagnostics but
    not optimal for extremely high frequency logging.
*/

/*
------------------------------------------------------------------------------
Includes
------------------------------------------------------------------------------
*/
#include <ctime>
#include <iostream>
#include <mutex>
#include <source_location>
#include <sstream>
#include <string>
#include <chrono>
#include <iomanip>

/*
------------------------------------------------------------------------------
Enumerations
------------------------------------------------------------------------------
*/
/// @brief Log level enumeration with bitmask support
///
/// @details Each log level is represented by a unique bit in a bitmask,
/// allowing flexible enabling/disabling of specific log levels through
/// bitwise operations.
enum LOG_LVL {

    TRACE    = 1u << 0u,  // Gray         Bits: ...0 0 0 0 0 0 0 0  0 0 0 0 0 0 0 1
    DEBUG    = 1u << 1u,  // Cyan         Bits: ...0 0 0 0 0 0 0 0  0 0 0 0 0 0 1 0
    INFO     = 1u << 2u,  // Green        Bits: ...0 0 0 0 0 0 0 0  0 0 0 0 0 1 0 0
    WARNING  = 1u << 3u,  // Yellow       Bits: ...0 0 0 0 0 0 0 0  0 0 0 0 1 0 0 0
    ERROR    = 1u << 4u,  // Red          Bits: ...0 0 0 0 0 0 0 0  0 0 0 1 0 0 0 0
    CRITICAL = 1u << 5u,  // Bright red   Bits: ...0 0 0 0 0 0 0 0  0 0 1 0 0 0 0 0
    SUCCESS  = 1u << 6u,  // Bright green Bits: ...0 0 0 0 0 0 0 0  0 1 0 0 0 0 0 0
    UPDATE   = 1u << 7u,  // Blue         Bits: ...0 0 0 0 0 0 0 0  1 0 0 0 0 0 0 0
    FATAL    = 1u << 8u,  // Magenta      Bits: ...0 0 0 0 0 0 0 1  0 0 0 0 0 0 0 0

    ALL_LOG_LVLS = TRACE   | //           Bits: ...0 0 0 0 0 0 0 0  0 0 0 0 0 0 0 1
                   DEBUG   | //           Bits: ...0 0 0 0 0 0 0 0  0 0 0 0 0 0 1 1
                   INFO    | //           Bits: ...0 0 0 0 0 0 0 0  0 0 0 0 0 1 1 1
                   WARNING | //           Bits: ...0 0 0 0 0 0 0 0  0 0 0 0 1 1 1 1
                   ERROR   | //           Bits: ...0 0 0 0 0 0 0 0  0 0 0 1 1 1 1 1
                   CRITICAL| //           Bits: ...0 0 0 0 0 0 0 0  0 0 1 1 1 1 1 1
                   SUCCESS | //           Bits: ...0 0 0 0 0 0 0 0  0 1 1 1 1 1 1 1
                   UPDATE  | //           Bits: ...0 0 0 0 0 0 0 0  1 1 1 1 1 1 1 1
                   FATAL,    //           Bits: ...0 0 0 0 0 0 0 1  1 1 1 1 1 1 1 1

    NO_LOG_LVLS = 0u         //           Bits: ...0 0 0 0 0 0 0 0  0 0 0 0 0 0 0 0

/*
    With these bitmasks we can do things like if:

    ENABLED_LOG_LVLS = (TRACE | WARNING)

    The binary of that will be ENABLED_LOG_LVLS = 0 0 0 0 1 0 0 1

    Then we can check for each log level before logging and see if
    their mask is allowed as follows:

    current_log_level = ERROR = 0 0 0 1 0 0 0 0

    ENABLED_LOG_LVLS = 0 0 0 0 1 0 0 1

    (ENABLED_LOG_LVLS & current_log_level) = 0 0 0 0 0 0 0 0

    (ENABLED_LOG_LVLS & current_log_level) != current_log_level
    therefore not allowed

    Another example:

    current_log_level = WARNING = 0 0 0 0 1 0 0 0

    ENABLED_LOG_LVLS = 0 0 0 0 1 0 0 1

    (ENABLED_LOG_LVLS & current_log_level) = 0 0 0 0 1 0 0 0

    (ENABLED_LOG_LVLS & current_log_level) == current_log_level
    therefore allowed
*/
};

/*
------------------------------------------------------------------------------
Global logging parameters
------------------------------------------------------------------------------
*/
/// @brief Bitmask defining which log levels are enabled
/// @details Use bitwise OR of LOG_LVL values to enable multiple levels
inline int ENABLED_LOG_LVLS = ALL_LOG_LVLS;

/// @brief Filter to restrict logging to specific files
/// @details Use "ALL" to log from all files, or specify a filename like "main.cpp"
inline std::string_view LOG_SPECIFIC_FILE_ONLY = "ALL";

/*
------------------------------------------------------------------------------
Logger BEGIN
------------------------------------------------------------------------------
*/
/// @brief Thread-safe logging class with colored output and source location
///
/// @details The Log class provides a RAII-based logging mechanism that buffers
///          messages and flushes them to the console upon destruction. It
///          includes colored output, timestamping, and source location information.
class Log final {
    /*
    ------------------------------------------------------------------------------
    Construction
    ------------------------------------------------------------------------------
    */
public:
    /// @brief Construct a Log instance with specified level and location
    /// @param level The log level for this message
    /// @param loc Source location information (automatically captured)
    Log(
        LOG_LVL              const level,
        std::source_location const loc
        ) :

        _level    (level),
        _location (loc  )
    {}

private:
    /// @brief Log level for this message
    LOG_LVL              _level;

    /// @brief Source location where the log was created
    std::source_location _location;

    /// @brief Internal buffer to hold full input string
    std::ostringstream _buffer;

    /// @brief Static mutex for thread-safe console output
    static std::mutex s_mutex;

    /*
    ------------------------------------------------------------------------------
    Destruction
    ------------------------------------------------------------------------------
    */
public:
    /// @brief Destructor - flushes buffered message to console
    ~Log() {

        bool const is_buffer_empty = _buffer.str().empty();
        if (is_buffer_empty) {

            // No need to flush since buffer is empty.
        } else {

            _flush();
        }
    }

    /*
    ------------------------------------------------------------------------------
    Rule of 5
    ------------------------------------------------------------------------------
    */
public:
    /// @brief Copy constructor deleted - Log instances should not be copied
    Log(Log const&) = delete;

    /// @brief Copy assignment deleted - Log instances should not be copied
    Log& operator=(Log const&) = delete;

    /// @brief Move constructor deleted - Log instances should not be moved
    Log(Log&&) = delete;

    /// @brief Move assignment deleted - Log instances should not be moved
    Log& operator=(Log&&) = delete;

    /*
    ------------------------------------------------------------------------------
    Functionality
    ------------------------------------------------------------------------------
    */
public:
    /// @brief Stream insertion operator for building log messages
    /// @tparam Input_type Type of the value to log
    /// @param value The value to append to the log message
    /// @return Reference to this Log for chaining
    template<typename Input_type>
    Log& operator<<(Input_type const& value) {

        // Write this value to the internal buffer for flushing later.
        _buffer << value;

        // Allows chaining << ... << ... << ...etc.
        return *this;
    }

    /*
    ------------------------------------------------------------------------------
    Helper Methods
    ------------------------------------------------------------------------------
    */
private:
    /// @brief Flush the buffered message to console
    /// @details Thread-safe method that formats and outputs the log message
    ///          with colors, timestamp, and source location information
    void _flush() {

        // Lock the mutex so no other Log objects can log till this is finished.
        // Unlocks automatically when this function is out of scope.
        std::lock_guard<std::mutex> lock(s_mutex);

        // Only flush if the log level is enabled right now.
        if (_is_log_lvl_enabled(_level)) {

            // Only show logs for allowed files.
            if (_is_file_allowed()) {

                char const* const reset_color = "\033[0m"; // Reset color

                // Output the buffer log to the console.
                std::cout << _get_color()   << /*---------------------*/     '\n'
                          << '['            << _level_to_str(_level)     << "]\n"
                          << "[Time: "      << _curr_time()              << "]\n"
                          << "[File: "      << _get_file()               << "]\n"
                          << "[Line: "      << _location.line()          << "]\n"
                          << "[Function: "  << _location.function_name() << "]\n"
                          << "[Log: "       << _buffer.str()             << "]\n"
                          << reset_color    << std::endl;

                // Reset the buffer (not really needed since object gets deleted).
                _buffer.str("");
                _buffer.clear();
            }
        }
    }

    /// @brief Get ANSI color code for current log level
    /// @return ANSI escape code for the appropriate color
    std::string _get_color() const {

        switch (_level) {

        case LOG_LVL::TRACE:    return "\033[90m"; // Gray
        case LOG_LVL::DEBUG:    return "\033[36m"; // Cyan
        case LOG_LVL::INFO:     return "\033[32m"; // Green
        case LOG_LVL::WARNING:  return "\033[33m"; // Yellow
        case LOG_LVL::ERROR:    return "\033[31m"; // Red
        case LOG_LVL::CRITICAL: return "\033[91m"; // Bright red
        case LOG_LVL::SUCCESS:  return "\033[92m"; // Bright green
        case LOG_LVL::UPDATE:   return "\033[34m"; // Blue
        case LOG_LVL::FATAL:    return "\033[35m"; // Magenta
        default:                return "\033[0m";  // Reset color
        }
    }

    /// @brief Extract filename from full file path
    /// @return Base filename without directory path
    std::string _get_file() const {

        std::string const full_filepath = _location.file_name();

        // Find the last slash (handles both Windows and Unix paths)
        size_t last_slash = full_filepath.find_last_of("/\\");

        // If no slash found, use the entire path as filename
        if (last_slash == std::string::npos) {

            last_slash = 0u;
        } else {

            // Move past the slash
            ++last_slash;
        }

        std::string const file = full_filepath.substr(last_slash);

        return file;
    }

    /// @brief Convert log level enum to string
    /// @param level The log level to convert
    /// @return String representation of the log level
    std::string _level_to_str(LOG_LVL const level) const {

        switch (level) {

        case LOG_LVL::TRACE:    return "TRACE";
        case LOG_LVL::DEBUG:    return "DEBUG";
        case LOG_LVL::INFO:     return "INFO";
        case LOG_LVL::WARNING:  return "WARNING";
        case LOG_LVL::ERROR:    return "ERROR";
        case LOG_LVL::CRITICAL: return "CRITICAL";
        case LOG_LVL::SUCCESS:  return "SUCCESS";
        case LOG_LVL::UPDATE:   return "UPDATE";
        case LOG_LVL::FATAL:    return "FATAL";
        default:                return "UNDEFINED";
        }
    }

    /// @brief Get current time as formatted string
    /// @return Current time in HH:MM:SS format
    std::string _curr_time() const {

        auto const time_point_now  = std::chrono::system_clock::now();
        auto const time_now        = std::chrono::system_clock::to_time_t(time_point_now);
        std::ostringstream time_stream;

        // If we are using windows then use the non standard windows safer localtime_s function.
        #ifdef _WIN32

            std::tm tm_info;
            localtime_s(&tm_info, &time_now);
            time_stream << std::put_time(&tm_info, "%H:%M:%S");

        // Otherwise use the standard localtime function.
        #else

            time_stream << std::put_time(std::localtime(&time_now), "%H:%M:%S");
        #endif

        return time_stream.str();
    }

    /// @brief Check if current log level is enabled
    /// @param log_lvl The log level to check
    /// @return true if the log level is enabled, false otherwise
    bool _is_log_lvl_enabled(LOG_LVL const log_lvl) const {

        bool const is_enabled = (ENABLED_LOG_LVLS & log_lvl) == log_lvl;
        return     is_enabled;
    }

    /// @brief Check if current file is allowed to log
    /// @return true if file is allowed, false otherwise
    bool _is_file_allowed() const {

        std::string const file            = _get_file();
        bool              is_file_allowed = true;

        if (LOG_SPECIFIC_FILE_ONLY == "ALL") {

            is_file_allowed = true;
        } else {

            is_file_allowed = (file == LOG_SPECIFIC_FILE_ONLY);
        }

        return is_file_allowed;
    }

}; // class Log

/*
------------------------------------------------------------------------------
Definitions
------------------------------------------------------------------------------
*/
/// @brief Macro to create a Log instance with current source location
/// @param level The log level for the message
#define LOG(level) Log(level, std::source_location::current())

/*
------------------------------------------------------------------------------
Definition of static members
------------------------------------------------------------------------------
*/
/// @brief Static mutex for thread-safe logging
inline std::mutex Log::s_mutex;

#endif // LOG_H
