/// @file signals_slots.h
/// @brief Signal-slot system for event handling in UI widgets

#ifndef SIGNALS_SLOTS_H
#define SIGNALS_SLOTS_H

/*
------------------------------------------------------------------------------
Includes
------------------------------------------------------------------------------
*/
#include "SFML/Graphics.hpp"

#include <functional>
#include <map>
#include <string>

/*
------------------------------------------------------------------------------
Namespace signals_slots BEGIN
------------------------------------------------------------------------------
*/
namespace signals_slots {

    /// @brief Enumeration of all available signals for event handling
    ///
    /// @details This enum defines all possible signals that can be emitted
    ///          in response to various input events including window events,
    ///          mouse events, keyboard events, and widget-specific events.
    enum Signal {
        /*
        ------------------------------------------------------------------------------
        Non-keyboard events
        ------------------------------------------------------------------------------
        */
        SIGNAL__WINDOW_CLOSED,
        SIGNAL__WINDOW_RESIZED,
        SIGNAL__WINDOW_LOST_FOCUS,
        SIGNAL__WINDOW_GAINED_FOCUS,
        SIGNAL__WINDOW_TEXT_ENTERED,

        SIGNAL__MOUSE_MOVED,
        SIGNAL__MOUSE_BUTTON_LEFT_PRESS,
        SIGNAL__MOUSE_BUTTON_RIGHT_PRESS,
        SIGNAL__MOUSE_BUTTON_MIDDLE_PRESS,
        SIGNAL__MOUSE_BUTTON_EXTRA_1_PRESS,
        SIGNAL__MOUSE_BUTTON_EXTRA_2_PRESS,
        SIGNAL__MOUSE_BUTTON_LEFT_RELEASE,
        SIGNAL__MOUSE_BUTTON_RIGHT_RELEASE,
        SIGNAL__MOUSE_BUTTON_MIDDLE_RELEASE,
        SIGNAL__MOUSE_BUTTON_EXTRA_1_RELEASE,
        SIGNAL__MOUSE_BUTTON_EXTRA_2_RELEASE,
        SIGNAL__MOUSE_WHEEL_UP,
        SIGNAL__MOUSE_WHEEL_DOWN,
        SIGNAL__MOUSE_ENTER_WINDOW,
        SIGNAL__MOUSE_LEAVE_WINDOW,

        SIGNAL__JOYSTICK_BUTTON_PRESSED,
        SIGNAL__JOYSTICK_BUTTON_RELEASED,
        SIGNAL__JOYSTICK_MOVED,
        SIGNAL__JOYSTICK_CONNECTED,
        SIGNAL__JOYSTICK_DISCONNECTED,

        SIGNAL__TOUCH_BEGAN,
        SIGNAL__TOUCH_MOVED,
        SIGNAL__TOUCH_ENDED,

        SIGNAL__SENSOR_CHANGED,

        /*
        ------------------------------------------------------------------------------
        Keyboard pressed
        ------------------------------------------------------------------------------
        */
        SIGNAL__KEYPRESS_A,
        SIGNAL__KEYPRESS_B,
        SIGNAL__KEYPRESS_C,
        SIGNAL__KEYPRESS_D,
        SIGNAL__KEYPRESS_E,
        SIGNAL__KEYPRESS_F,
        SIGNAL__KEYPRESS_G,
        SIGNAL__KEYPRESS_H,
        SIGNAL__KEYPRESS_I,
        SIGNAL__KEYPRESS_J,
        SIGNAL__KEYPRESS_K,
        SIGNAL__KEYPRESS_L,
        SIGNAL__KEYPRESS_M,
        SIGNAL__KEYPRESS_N,
        SIGNAL__KEYPRESS_O,
        SIGNAL__KEYPRESS_P,
        SIGNAL__KEYPRESS_Q,
        SIGNAL__KEYPRESS_R,
        SIGNAL__KEYPRESS_S,
        SIGNAL__KEYPRESS_T,
        SIGNAL__KEYPRESS_U,
        SIGNAL__KEYPRESS_V,
        SIGNAL__KEYPRESS_W,
        SIGNAL__KEYPRESS_X,
        SIGNAL__KEYPRESS_Y,
        SIGNAL__KEYPRESS_Z,

        SIGNAL__KEYPRESS_NUM0,
        SIGNAL__KEYPRESS_NUM1,
        SIGNAL__KEYPRESS_NUM2,
        SIGNAL__KEYPRESS_NUM3,
        SIGNAL__KEYPRESS_NUM4,
        SIGNAL__KEYPRESS_NUM5,
        SIGNAL__KEYPRESS_NUM6,
        SIGNAL__KEYPRESS_NUM7,
        SIGNAL__KEYPRESS_NUM8,
        SIGNAL__KEYPRESS_NUM9,

        SIGNAL__KEYPRESS_ESCAPE,
        SIGNAL__KEYPRESS_LCONTROL,
        SIGNAL__KEYPRESS_LSHIFT,
        SIGNAL__KEYPRESS_LALT,
        SIGNAL__KEYPRESS_LSYSTEM,
        SIGNAL__KEYPRESS_RCONTROL,
        SIGNAL__KEYPRESS_RSHIFT,
        SIGNAL__KEYPRESS_RALT,
        SIGNAL__KEYPRESS_RSYSTEM,
        SIGNAL__KEYPRESS_MENU,
        SIGNAL__KEYPRESS_LBRACKET,
        SIGNAL__KEYPRESS_RBRACKET,
        SIGNAL__KEYPRESS_SEMICOLON,
        SIGNAL__KEYPRESS_COMMA,
        SIGNAL__KEYPRESS_PERIOD,
        SIGNAL__KEYPRESS_QUOTE,
        SIGNAL__KEYPRESS_SLASH,
        SIGNAL__KEYPRESS_BACKSLASH,
        SIGNAL__KEYPRESS_TILDE,
        SIGNAL__KEYPRESS_EQUAL,
        SIGNAL__KEYPRESS_DASH,
        SIGNAL__KEYPRESS_SPACE,
        SIGNAL__KEYPRESS_RETURN,
        SIGNAL__KEYPRESS_BACKSPACE,
        SIGNAL__KEYPRESS_TAB,
        SIGNAL__KEYPRESS_PAGEUP,
        SIGNAL__KEYPRESS_PAGEDOWN,
        SIGNAL__KEYPRESS_END,
        SIGNAL__KEYPRESS_HOME,
        SIGNAL__KEYPRESS_INSERT,
        SIGNAL__KEYPRESS_DELETE,
        SIGNAL__KEYPRESS_ADD,
        SIGNAL__KEYPRESS_SUBTRACT,
        SIGNAL__KEYPRESS_MULTIPLY,
        SIGNAL__KEYPRESS_DIVIDE,
        SIGNAL__KEYPRESS_LEFT,
        SIGNAL__KEYPRESS_RIGHT,
        SIGNAL__KEYPRESS_UP,
        SIGNAL__KEYPRESS_DOWN,
        SIGNAL__KEYPRESS_NUMPAD0,
        SIGNAL__KEYPRESS_NUMPAD1,
        SIGNAL__KEYPRESS_NUMPAD2,
        SIGNAL__KEYPRESS_NUMPAD3,
        SIGNAL__KEYPRESS_NUMPAD4,
        SIGNAL__KEYPRESS_NUMPAD5,
        SIGNAL__KEYPRESS_NUMPAD6,
        SIGNAL__KEYPRESS_NUMPAD7,
        SIGNAL__KEYPRESS_NUMPAD8,
        SIGNAL__KEYPRESS_NUMPAD9,
        SIGNAL__KEYPRESS_F1,
        SIGNAL__KEYPRESS_F2,
        SIGNAL__KEYPRESS_F3,
        SIGNAL__KEYPRESS_F4,
        SIGNAL__KEYPRESS_F5,
        SIGNAL__KEYPRESS_F6,
        SIGNAL__KEYPRESS_F7,
        SIGNAL__KEYPRESS_F8,
        SIGNAL__KEYPRESS_F9,
        SIGNAL__KEYPRESS_F10,
        SIGNAL__KEYPRESS_F11,
        SIGNAL__KEYPRESS_F12,
        SIGNAL__KEYPRESS_F13,
        SIGNAL__KEYPRESS_F14,
        SIGNAL__KEYPRESS_F15,
        SIGNAL__KEYPRESS_PAUSE,

        /*
        ------------------------------------------------------------------------------
        Keyboard released
        ------------------------------------------------------------------------------
        */
        SIGNAL__KEYRELEASE_A,
        SIGNAL__KEYRELEASE_B,
        SIGNAL__KEYRELEASE_C,
        SIGNAL__KEYRELEASE_D,
        SIGNAL__KEYRELEASE_E,
        SIGNAL__KEYRELEASE_F,
        SIGNAL__KEYRELEASE_G,
        SIGNAL__KEYRELEASE_H,
        SIGNAL__KEYRELEASE_I,
        SIGNAL__KEYRELEASE_J,
        SIGNAL__KEYRELEASE_K,
        SIGNAL__KEYRELEASE_L,
        SIGNAL__KEYRELEASE_M,
        SIGNAL__KEYRELEASE_N,
        SIGNAL__KEYRELEASE_O,
        SIGNAL__KEYRELEASE_P,
        SIGNAL__KEYRELEASE_Q,
        SIGNAL__KEYRELEASE_R,
        SIGNAL__KEYRELEASE_S,
        SIGNAL__KEYRELEASE_T,
        SIGNAL__KEYRELEASE_U,
        SIGNAL__KEYRELEASE_V,
        SIGNAL__KEYRELEASE_W,
        SIGNAL__KEYRELEASE_X,
        SIGNAL__KEYRELEASE_Y,
        SIGNAL__KEYRELEASE_Z,

        SIGNAL__KEYRELEASE_NUM0,
        SIGNAL__KEYRELEASE_NUM1,
        SIGNAL__KEYRELEASE_NUM2,
        SIGNAL__KEYRELEASE_NUM3,
        SIGNAL__KEYRELEASE_NUM4,
        SIGNAL__KEYRELEASE_NUM5,
        SIGNAL__KEYRELEASE_NUM6,
        SIGNAL__KEYRELEASE_NUM7,
        SIGNAL__KEYRELEASE_NUM8,
        SIGNAL__KEYRELEASE_NUM9,

        SIGNAL__KEYRELEASE_ESCAPE,
        SIGNAL__KEYRELEASE_LCONTROL,
        SIGNAL__KEYRELEASE_LSHIFT,
        SIGNAL__KEYRELEASE_LALT,
        SIGNAL__KEYRELEASE_LSYSTEM,
        SIGNAL__KEYRELEASE_RCONTROL,
        SIGNAL__KEYRELEASE_RSHIFT,
        SIGNAL__KEYRELEASE_RALT,
        SIGNAL__KEYRELEASE_RSYSTEM,
        SIGNAL__KEYRELEASE_MENU,
        SIGNAL__KEYRELEASE_LBRACKET,
        SIGNAL__KEYRELEASE_RBRACKET,
        SIGNAL__KEYRELEASE_SEMICOLON,
        SIGNAL__KEYRELEASE_COMMA,
        SIGNAL__KEYRELEASE_PERIOD,
        SIGNAL__KEYRELEASE_QUOTE,
        SIGNAL__KEYRELEASE_SLASH,
        SIGNAL__KEYRELEASE_BACKSLASH,
        SIGNAL__KEYRELEASE_TILDE,
        SIGNAL__KEYRELEASE_EQUAL,
        SIGNAL__KEYRELEASE_DASH,
        SIGNAL__KEYRELEASE_SPACE,
        SIGNAL__KEYRELEASE_RETURN,
        SIGNAL__KEYRELEASE_BACKSPACE,
        SIGNAL__KEYRELEASE_TAB,
        SIGNAL__KEYRELEASE_PAGEUP,
        SIGNAL__KEYRELEASE_PAGEDOWN,
        SIGNAL__KEYRELEASE_END,
        SIGNAL__KEYRELEASE_HOME,
        SIGNAL__KEYRELEASE_INSERT,
        SIGNAL__KEYRELEASE_DELETE,
        SIGNAL__KEYRELEASE_ADD,
        SIGNAL__KEYRELEASE_SUBTRACT,
        SIGNAL__KEYRELEASE_MULTIPLY,
        SIGNAL__KEYRELEASE_DIVIDE,
        SIGNAL__KEYRELEASE_LEFT,
        SIGNAL__KEYRELEASE_RIGHT,
        SIGNAL__KEYRELEASE_UP,
        SIGNAL__KEYRELEASE_DOWN,
        SIGNAL__KEYRELEASE_NUMPAD0,
        SIGNAL__KEYRELEASE_NUMPAD1,
        SIGNAL__KEYRELEASE_NUMPAD2,
        SIGNAL__KEYRELEASE_NUMPAD3,
        SIGNAL__KEYRELEASE_NUMPAD4,
        SIGNAL__KEYRELEASE_NUMPAD5,
        SIGNAL__KEYRELEASE_NUMPAD6,
        SIGNAL__KEYRELEASE_NUMPAD7,
        SIGNAL__KEYRELEASE_NUMPAD8,
        SIGNAL__KEYRELEASE_NUMPAD9,
        SIGNAL__KEYRELEASE_F1,
        SIGNAL__KEYRELEASE_F2,
        SIGNAL__KEYRELEASE_F3,
        SIGNAL__KEYRELEASE_F4,
        SIGNAL__KEYRELEASE_F5,
        SIGNAL__KEYRELEASE_F6,
        SIGNAL__KEYRELEASE_F7,
        SIGNAL__KEYRELEASE_F8,
        SIGNAL__KEYRELEASE_F9,
        SIGNAL__KEYRELEASE_F10,
        SIGNAL__KEYRELEASE_F11,
        SIGNAL__KEYRELEASE_F12,
        SIGNAL__KEYRELEASE_F13,
        SIGNAL__KEYRELEASE_F14,
        SIGNAL__KEYRELEASE_F15,
        SIGNAL__KEYRELEASE_PAUSE,
        /*
        ------------------------------------------------------------------------------
        Widget specific
        ------------------------------------------------------------------------------
        */
        SIGNAL__HOVER,
        SIGNAL__STOP_HOVER
    };

    /// @brief Convert signal enum to string representation
    /// @param signal The signal to convert
    /// @return std::string String representation of the signal
    std::string signal_to_str(Signal const signal);

    /*
    ------------------------------------------------------------------------------
    Class Signals_slots BEGIN
    ------------------------------------------------------------------------------
    */
    /// @brief Base class for implementing signal-slot event handling
    ///
    /// @details This class provides a comprehensive event handling system using
    ///          signals and slots. It processes SFML events and emits corresponding
    ///          signals that can be connected to callback functions (slots).
    ///          Only ever inherit from this class - do not instantiate directly.
    class Signals_slots {
        /*
        ------------------------------------------------------------------------------
        Construction / Destruction
        ------------------------------------------------------------------------------
        */
        protected:
            /// @brief Default constructor
            Signals_slots();

            /// @brief Virtual destructor for proper polymorphic destruction
            virtual ~Signals_slots() = default;
        /*
        ------------------------------------------------------------------------------
        Rule of 5
        ------------------------------------------------------------------------------
        */
        protected:
            Signals_slots           (Signals_slots const& ) = delete;
            Signals_slots& operator=(Signals_slots const& ) = delete;
            Signals_slots           (Signals_slots      &&) = delete;
            Signals_slots& operator=(Signals_slots      &&) = delete;
        /*
        ------------------------------------------------------------------------------
        Functionality
        ------------------------------------------------------------------------------
        */
        public:
            /// @brief Connect a slot function to a signal
            /// @param signal The signal to connect to
            /// @param slot The callback function to execute when signal is emitted
            virtual void connect(Signal const signal, std::function<void()> const& slot);

            /// @brief Disconnect all slots from a signal
            /// @param signal The signal to disconnect slots from
            virtual void disconnect(Signal const signal);

            /// @brief Disconnect all slots from all signals
            virtual void disconnect_all_signals();

            /// @brief Process SFML events and emit corresponding signals
            /// @param event The SFML event to process
            virtual void handle_events(sf::Event const& event);

        protected:
            /// @brief Emit a signal, executing all connected slots
            /// @param signal The signal to emit
            virtual void _emit_signal(Signal const signal) const;

            virtual void _handle_window_closed_events           (sf::Event const& event);
            virtual void _handle_window_resized_events          (sf::Event const& event);
            virtual void _handle_window_lost_focus_events       (sf::Event const& event);
            virtual void _handle_window_gained_focus_events     (sf::Event const& event);
            virtual void _handle_text_entered_events            (sf::Event const& event);
            virtual void _handle_mouse_moved_events             (sf::Event const& event);
            virtual void _handle_mouse_button_pressed_events    (sf::Event const& event);
            virtual void _handle_mouse_button_release_events    (sf::Event const& event);
            virtual void _handle_mouse_wheel_events             (sf::Event const& event);
            virtual void _handle_mouse_enter_window_events      (sf::Event const& event);
            virtual void _handle_mouse_left_window_events       (sf::Event const& event);
            virtual void _handle_joystick_button_pressed_events (sf::Event const& event);
            virtual void _handle_joystick_button_released_events(sf::Event const& event);
            virtual void _handle_joystick_moved_events          (sf::Event const& event);
            virtual void _handle_joystick_connected_events      (sf::Event const& event);
            virtual void _handle_joystick_disconnected_events   (sf::Event const& event);
            virtual void _handle_touch_began_events             (sf::Event const& event);
            virtual void _handle_touch_moved_events             (sf::Event const& event);
            virtual void _handle_touch_ended_events             (sf::Event const& event);
            virtual void _handle_sensor_changed_events          (sf::Event const& event);
            virtual void _handle_key_pressed_events             (sf::Event const& event);
            virtual void _handle_key_released_events            (sf::Event const& event);

            // Widget specific
            virtual void _handle_hover(sf::Event const& event);

            std::map<Signal, std::vector<std::function<void()>>> _signal_slot_map;

    }; // class Signals_slots

} // namespace signals_slots

#endif
