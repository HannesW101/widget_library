/// @file basic_example.cpp
/// @brief Clean demonstration of the SFML widget library
/// @example basic_example.cpp
///
/// This example shows the core functionality of each widget type
/// with proper event handling and interactive features.

#include "SFML/Graphics.hpp"
#include "widgets.h"

#include <iostream>
#include <memory>

using namespace widgets;
using namespace signals_slots;

int main() {

    // Context settings
    sf::ContextSettings ctx_settings{};
    ctx_settings.antiAliasingLevel = 8;

    // Create window
    auto window = std::make_shared<sf::RenderWindow>(
        sf::VideoMode({800, 600}),
        "SFML Widget Library - Basic Example",
        sf::State::Windowed,
        ctx_settings
    );

    // FPS limit
    window->setFramerateLimit(60);

    // ========== CREATE WIDGETS ==========

    // Title
    auto title = std::make_unique<Label>(window, "Widget Library Demo");
    title->set_pos(20.0f, 20.0f);
    title->set_char_size(32);
    title->set_text_color(sf::Color::White);

    // Push Button
    auto button = std::make_unique<Push_button>(window);
    button->set_pos(50.0f, 100.0f);
    button->set_size(150.0f, 50.0f);
    button->set_color(sf::Color(70, 130, 180));
    button->set_border_thickness(2.0f);
    button->set_border_color(sf::Color::White);
    // IMPORTANT!!!! Do text settings for a push button last so it can
    // correctly center and adjust its text size
    button->set_text_string("Click Me!");
    button->set_text_color(sf::Color::White);

    // Click counter
    int click_count = 0;
    auto counter_label = std::make_unique<Label>(window, "Clicks: 0");
    counter_label->set_pos(220.0f, 115.0f);
    counter_label->set_char_size(20);
    counter_label->set_text_color(sf::Color::Yellow);

    // Text Input
    auto text_input = std::make_unique<Line_edit>(window, "Enter text here...");
    text_input->set_pos(50.0f, 200.0f);
    text_input->set_char_size(20);
    text_input->set_max_chars(25);
    text_input->set_border_thickness(2.0f);
    text_input->set_border_color(sf::Color(100, 100, 100));

    // Echo label (shows what you type)
    auto echo_label = std::make_unique<Label>(window, "Your text will appear here");
    echo_label->set_pos(50.0f, 260.0f);
    echo_label->set_char_size(18);
    echo_label->set_text_color(sf::Color::Cyan);

    // Status label
    auto status_label = std::make_unique<Label>(window, "Status: Ready");
    status_label->set_pos(50.0f, 350.0f);
    status_label->set_char_size(16);
    status_label->set_text_color(sf::Color::Green);

    // Instructions
    auto instructions = std::make_unique<Label>(
        window,
        "Click button, type in field (Backspace to delete), ESC to quit"
    );
    instructions->set_pos(20.0f, 550.0f);
    instructions->set_char_size(14);
    instructions->set_text_color(sf::Color(150, 150, 150));

    // ========== CONNECT SIGNALS ==========

    // Button: Click handler
    button->connect(SIGNAL__MOUSE_BUTTON_LEFT_PRESS, [&]() {

        ++click_count;
        counter_label->set_text_string("Clicks: " + std::to_string(click_count));
        status_label->set_text_string("Status: Button clicked!");
        status_label->set_text_color(sf::Color::Yellow);
    });

    // Button: Hover effect
    button->connect(SIGNAL__HOVER, [&]() {

        button->set_color(sf::Color(100, 160, 210));
        status_label->set_text_string("Status: Hovering over button");
        status_label->set_text_color(sf::Color::Cyan);
        window->setMouseCursor(sf::Cursor(sf::Cursor::Type::Hand));
    });

    // Button: Stop hover effect
    button->connect(SIGNAL__STOP_HOVER, [&]() {

        button->set_color(sf::Color(70, 130, 180));
        status_label->set_text_string("Status: Ready");
        status_label->set_text_color(sf::Color::Green);
        window->setMouseCursor(sf::Cursor(sf::Cursor::Type::Arrow));
    });

    // Text Input: Character entry
    text_input->connect(SIGNAL__WINDOW_TEXT_ENTERED, [&]() {

        text_input->append_typed_char();
        sf::String const typed = text_input->get_typing_text_string();

        if (typed.isEmpty()) {

            echo_label->set_text_string("Your text will appear here");
        } else {

            echo_label->set_text_string("You typed: " + typed);
        }
    });

    // Text Input: Backspace
    text_input->connect(SIGNAL__KEYPRESS_BACKSPACE, [&]() {

        text_input->delete_char();
        sf::String const typed = text_input->get_typing_text_string();

        if (typed.isEmpty()) {

            echo_label->set_text_string("Your text will appear here");
        } else {

            echo_label->set_text_string("You typed: " + typed);
        }
    });

    // Text Input: Hover effect
    text_input->connect(SIGNAL__HOVER, [&]() {

        if (text_input->get_border_color() != sf::Color::Yellow) {

            text_input->set_border_color(sf::Color(150, 150, 150));
        }

        window->setMouseCursor(sf::Cursor(sf::Cursor::Type::Hand));
    });

    // Text Input: Stop hover effect
    text_input->connect(SIGNAL__STOP_HOVER, [&]() {

        if (text_input->get_border_color() != sf::Color::Yellow) {

            text_input->set_border_color(sf::Color(100, 100, 100));
        }

        window->setMouseCursor(sf::Cursor(sf::Cursor::Type::Arrow));
    });

    // ========== MAIN LOOP ==========

    while (window->isOpen()) {

        while (const std::optional event = window->pollEvent()) {

            // Close window: exit
            if (event->is<sf::Event::Closed>()) window->close();

            // ESC key to exit
            if (const auto* key_pressed = event->getIf<sf::Event::KeyPressed>()) {

                if (key_pressed->code == sf::Keyboard::Key::Escape) {

                    window->close();
                }
            }

            // Handle widget events
            button->handle_events(*event);
            text_input->handle_events(*event);
        }

        // ========== UPDATE ==========

        // Check if approaching character limit
        std::size_t const typed_length = text_input->get_typing_text_string().getSize();
        if (typed_length > 20u) {

            status_label->set_text_string(
                "Status: Character limit warning (" +
                std::to_string(typed_length) + "/25)"
            );

            status_label->set_text_color(sf::Color::Red);
        }

        // ========== RENDER ==========

        window->clear(sf::Color(30, 30, 30)); // Dark background

        // Draw all widgets
        title->draw();
        button->draw();
        counter_label->draw();
        text_input->draw();
        echo_label->draw();
        status_label->draw();
        instructions->draw();

        window->display();
    }

    return 0;
}