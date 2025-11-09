/// @file widgets.h
/// @brief SFML Widget Library - Complete UI Toolkit
/// @mainpage SFML Widget Library Documentation
///
/// A comprehensive, easy-to-use widget library for SFML applications.
/// Provides buttons, labels, text inputs, and more with full event handling.
///
/// @section quickstart_sec Quick Start
///
/// @code
/// #include <widgets/widgets.h>
/// #include <SFML/Graphics.hpp>
///
/// int main() {
///     sf::RenderWindow window(sf::VideoMode(800, 600), "My App");
///     widgets::Push_button button(window, "Click me!");
///     button.set_pos(100, 100);
///
///     button.connect(widgets::SIGNAL__MOUSE_BUTTON_LEFT_PRESS, [&]() {
///        std::cout << "Button clicked!" << std::endl;
///     });
///
///     while (window.isOpen()) {
///         sf::Event event;
///         while (window.pollEvent(event)) {
///             if (event.type == sf::Event::Closed) window.close();
///             button.handle_events(event);
///         }
///         window.clear();
///         button.draw();
///         window.display();
///     }
///     return 0;
/// }
/// @endcode
///
/// @see widgets::Widget
/// @see widgets::Push_button
/// @see widgets::Label
/// @see widgets::Line_edit
/// @see widgets::Sprite_button
/// @see widgets::Image

#ifndef WIDGETS_H
#define WIDGETS_H

// Include all widget headers
#include "widgets/log.h"
#include "widgets/resources.h"
#include "widgets/signals_slots.h"
#include "widgets/widget.h"
#include "widgets/sprite_button.h"
#include "widgets/push_button.h"
#include "widgets/line_edit.h"
#include "widgets/label.h"
#include "widgets/image.h"

namespace widgets {

/// @brief Get library version information
/// @return std::string containing version number
/// @ingroup Core
inline std::string get_version() {

    return "1.0.0";
}

} // namespace widgets

#endif // WIDGETS_H
