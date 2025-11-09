/// @file resources.h
/// @brief Resource management for widget system including fonts, colors, and constants

#ifndef RESOURCES_H
#define RESOURCES_H

/*
------------------------------------------------------------------------------
Includes
------------------------------------------------------------------------------
*/
#include "widgets/log.h"
#include "SFML/Graphics.hpp"

/*
------------------------------------------------------------------------------
Namespace resources BEGIN
------------------------------------------------------------------------------
*/
namespace resources {
/*
------------------------------------------------------------------------------
Object Constants
------------------------------------------------------------------------------
*/
    /// @brief Default widget size constant (0.0f, 0.0f)
    inline sf::Vector2f constexpr DEFAULT_WIDGET_SIZE = { 0.0f, 0.0f };

    /// @brief Default widget position constant (0.0f, 0.0f)
    inline sf::Vector2f constexpr DEFAULT_WIDGET_POS = { 0.0f, 0.0f };

    /// @brief Default widget color constant (Magenta)
    inline sf::Color constexpr DEFAULT_WIDGET_COLOR = sf::Color::Magenta;

    /// @brief Default text color constant (Black)
    inline sf::Color constexpr DEFAULT_TEXT_COLOR   = sf::Color::Black;

    /// @brief Default widget font
    inline sf::Font DEFAULT_WIDGET_FONT;

/*
------------------------------------------------------------------------------
Load all resources
------------------------------------------------------------------------------
*/
    /// @brief Load all required resources for the widget system
    /// @details If loading any resources fails it will throw an exception on the spot.
    ///          This function uses a static flag to ensure resources are only loaded once.
    inline void LOAD_RESOURCES() {

        static bool is_loaded = false;

        if (is_loaded) {

            // Resources are already loaded so dont load again.
        } else {

            if (!DEFAULT_WIDGET_FONT.openFromFile("assets/default_font.otf")) {

                LOG(ERROR) << "Error loading resource [DEFAULT_WIDGET_FONT].";
            }

            is_loaded = true;
        }
    }

    /// @brief Automatic resource loader
    /// @details Automatically load resources (if not already loaded) when header is included.
    ///          Uses an immediately-invoked lambda expression to load resources at startup.
    inline bool RESOURCES_LOADED = []() {

        LOG(INFO  )  << "Loading resources for widget library...";
        LOAD_RESOURCES();
        LOG(SUCCESS) << "Resources for widget library successfully loaded!";

        return true;
    }();

} // namespace resources

#endif // RESOURCES_H
