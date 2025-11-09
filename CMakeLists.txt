cmake_minimum_required(VERSION 3.28)
project(WidgetLibrary VERSION 1.0.0 LANGUAGES CXX DESCRIPTION "SFML Widget Library")

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ========== FIND OR FETCH SFML ==========
find_package(SFML 2.5 COMPONENTS Graphics System Window QUIET)

if(NOT SFML_FOUND)
    message(STATUS "SFML not found. Fetching from GitHub...")

    include(FetchContent)
    FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 3.0.2
        GIT_SHALLOW ON
        EXCLUDE_FROM_ALL
        SYSTEM
    )

    # Configure SFML options before fetching
    set(SFML_BUILD_AUDIO FALSE CACHE BOOL "" FORCE)
    set(SFML_BUILD_NETWORK FALSE CACHE BOOL "" FORCE)
    set(BUILD_SHARED_LIBS FALSE CACHE BOOL "" FORCE)

    FetchContent_MakeAvailable(SFML)

    message(STATUS "SFML fetched successfully")
else()
    message(STATUS "SFML found: ${SFML_VERSION}")
endif()

# Print configuration info
message(STATUS "Building SFML Widget Library ${PROJECT_VERSION}")
message(STATUS "C++ standard: ${CMAKE_CXX_STANDARD}")

# ========== CREATE WIDGET LIBRARY ==========

# Collect all source files that exist
file(GLOB_RECURSE WIDGET_SOURCES
    "src/*.cpp"
)

# Check if we have any sources
if(NOT WIDGET_SOURCES)
    message(FATAL_ERROR "No source files found in src/ directory!")
endif()

add_library(widgets ${WIDGET_SOURCES})

# Include directories
target_include_directories(widgets PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/widgets>
    $<INSTALL_INTERFACE:include>
    $<INSTALL_INTERFACE:include/widgets>
)

# Dependencies
if(SFML_FOUND)
    target_link_libraries(widgets PUBLIC
        sfml-graphics
        sfml-system
        sfml-window
    )
else()
    # SFML was fetched, link privately to avoid export issues
    target_link_libraries(widgets PRIVATE
        sfml-graphics
        sfml-system
        sfml-window
    )
endif()

# Compiler features
target_compile_features(widgets PUBLIC cxx_std_20)

# ========== EXAMPLES ==========
if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/examples/basic_example.cpp)
    add_executable(widgets_example examples/basic_example.cpp)
    target_link_libraries(widgets_example
        widgets
        sfml-graphics
        sfml-system
        sfml-window
    )
    set_target_properties(widgets_example PROPERTIES
        OUTPUT_NAME "widgets_demo"
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    )

    # Copy assets for examples
    if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/assets)
        file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/assets DESTINATION ${CMAKE_BINARY_DIR}/bin)
    endif()
endif()

# ========== INSTALLATION ==========
include(GNUInstallDirs)

# Install library targets
install(TARGETS widgets
    EXPORT WidgetsTargets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

# Install headers
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

# Install export target for find_package
install(EXPORT WidgetsTargets
    FILE WidgetsTargets.cmake
    NAMESPACE Widgets::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Widgets
)

# ========== PACKAGE CONFIG ==========
include(CMakePackageConfigHelpers)

# Generate the config file that includes the exports
configure_package_config_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/WidgetsConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/WidgetsConfig.cmake
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Widgets
)

# Generate version file
write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/WidgetsConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)

# Install config files
install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/WidgetsConfig.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/WidgetsConfigVersion.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Widgets
)

# ========== EXPORT FOR USE FROM BUILD TREE ==========
# Only export if SFML was found (not fetched)
if(SFML_FOUND)
    export(EXPORT WidgetsTargets
        FILE ${CMAKE_CURRENT_BINARY_DIR}/WidgetsTargets.cmake
        NAMESPACE Widgets::
    )
endif()

# ========== PACKAGE INFO ==========
message(STATUS "")
message(STATUS "SFML Widget Library configured successfully!")
message(STATUS "  Version: ${PROJECT_VERSION}")
message(STATUS "  Install prefix: ${CMAKE_INSTALL_PREFIX}")
message(STATUS "  Build examples: ${CMAKE_CURRENT_SOURCE_DIR}/examples/basic_example.cpp")
message(STATUS "")
message(STATUS "To use this library in your project:")
message(STATUS "  add_subdirectory(path/to/widget-library)")
message(STATUS "  target_link_libraries(your_target widgets)")
message(STATUS "")