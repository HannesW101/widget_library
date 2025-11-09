# SFML Widget Library

A comprehensive, easy-to-use widget library for SFML applications. Create professional UIs with buttons, text inputs, labels, and more in minutes.

## Features

- **Header-Only or Compiled** - Choose between easy inclusion or optimized compilation
- **Rich Widget Set** - Buttons, labels, text inputs, images with full customization
- **Advanced Event System** - Signal-slot system with 150+ predefined events
- **Built-in Logging** - Colored, thread-safe console logging
- **Resource Management** - Automatic font and resource loading
- **SFML Integration** - Seamless integration with SFML windows and events
- **Modern C++20** - Clean, modern codebase with full Doxygen documentation
- **Cross-Platform** - Works on Windows, Linux, and macOS

## Quick Start

### Method 1: CMake add_subdirectory (Recommended)

1. **Add the library to your project:**
```bash
git clone https://github.com/yourusername/widget-library
```

2. **Add just 2 lines to your CMakeLists.txt:**
```cmake
add_subdirectory(path/to/widget-library)
target_link_libraries(your_target widgets)
```

3. **Use in your code with one include:**
```cpp
#include <widgets/widgets.h>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "My App");

    widgets::Push_button button(window, "Click me!");
    button.set_pos(100, 100);
    button.set_color(sf::Color::Blue);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
            button.handle_events(event);
        }

        window.clear();
        button.draw();
        window.display();
    }
    return 0;
}
```

### Method 2: Manual Inclusion (No CMake)

```cpp
// Copy include/ and src/ folders to your project
#include "widgets/widgets.h"

// Compile all .cpp files from src/ with your project
// g++ -std=c++17 main.cpp src/*.cpp -lsfml-graphics -lsfml-window -lsfml-system
```

## Available Widgets

| Widget | Description | Key Features |
|--------|-------------|--------------|
| **Push_button** | Text-based button | Colors, hover effects, click handling, borders |
| **Sprite_button** | Image-based button | Textures, sprite sheets, scaling |
| **Line_edit** | Text input field | Character limits, placeholder text, typing events |
| **Label** | Text display | Custom fonts, colors, styles, text borders |
| **Image** | Image display | Textures, scaling, rotation, texture rectangles |

## Signal/Slot Event System

Connect widgets to functions with an intuitive event system:

```cpp
button.connect(widgets::SIGNAL__MOUSE_BUTTON_LEFT_PRESS, []() {
    std::cout << "Button clicked!" << std::endl;
});

button.connect(widgets::SIGNAL__HOVER, [&]() {
    button.set_color(sf::Color(100, 100, 255));
});

button.connect(widgets::SIGNAL__STOP_HOVER, [&]() {
    button.set_color(sf::Color::Blue);
});
```

### Available Signal Categories:
- Mouse Events: Click, release, movement, hover
- Keyboard Events: Key presses and releases for all keys
- Window Events: Focus, resize, close
- Text Input: Character entry, typing state
- Widget Specific: Hover, focus, state changes

## Complete Example

```cpp
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
    sf::RenderWindow window(
        sf::VideoMode({800, 600}),
        "SFML Widget Library - Basic Example",
        sf::State::Windowed,
        ctx_settings
    );

    // FPS limit
    window.setFramerateLimit(60);

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
        window.setMouseCursor(sf::Cursor(sf::Cursor::Type::Hand));
    });

    // Button: Stop hover effect
    button->connect(SIGNAL__STOP_HOVER, [&]() {

        button->set_color(sf::Color(70, 130, 180));
        status_label->set_text_string("Status: Ready");
        status_label->set_text_color(sf::Color::Green);
        window.setMouseCursor(sf::Cursor(sf::Cursor::Type::Arrow));
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

        window.setMouseCursor(sf::Cursor(sf::Cursor::Type::Hand));
    });

    // Text Input: Stop hover effect
    text_input->connect(SIGNAL__STOP_HOVER, [&]() {

        if (text_input->get_border_color() != sf::Color::Yellow) {

            text_input->set_border_color(sf::Color(100, 100, 100));
        }

        window.setMouseCursor(sf::Cursor(sf::Cursor::Type::Arrow));
    });

    // ========== MAIN LOOP ==========

    while (window.isOpen()) {

        while (const std::optional event = window.pollEvent()) {

            // Close window: exit
            if (event->is<sf::Event::Closed>()) window.close();

            // ESC key to exit
            if (const auto* key_pressed = event->getIf<sf::Event::KeyPressed>()) {

                if (key_pressed->code == sf::Keyboard::Key::Escape) {

                    window.close();
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

        window.clear(sf::Color(30, 30, 30)); // Dark background

        // Draw all widgets
        title->draw();
        button->draw();
        counter_label->draw();
        text_input->draw();
        echo_label->draw();
        status_label->draw();
        instructions->draw();

        window.display();
    }

    return 0;
}
```

## Building from Source

### Prerequisites
- SFML 2.5+ (Graphics, System, Window components)
- C++20 compatible compiler (GCC 7+, Clang 5+, MSVC 2017+)
- CMake 3.28+

### Build Steps
```bash
# Clone the repository
git clone https://github.com/yourusername/widget-library
cd widget-library

# Configure with CMake
cmake -B build

# Build the library
cmake --build build

# Run the example application
./build/bin/widgets_demo  # Linux/macOS
# build\bin\widgets_demo.exe  # Windows
```

### Build Options
- BUILD_EXAMPLES=ON/OFF - Build example applications (default: ON)
- BUILD_TESTS=ON/OFF - Build test suite (default: OFF)

## Documentation

### Full API Reference
The library includes comprehensive Doxygen documentation. To generate:

```bash
# Generate documentation
doxygen Doxyfile

# Open in browser
open docs/html/index.html  # macOS
xdg-open docs/html/index.html  # Linux
start docs/html/index.html  # Windows
```

### Key Documentation Sections:
- Class Reference - Complete API for all widgets
- Examples - Working code examples for each widget type
- Signal Reference - Complete list of all available events
- Tutorials - Step-by-step guides for common tasks

## Requirements

### Required Dependencies
- SFML 2.5+ - Simple and Fast Multimedia Library
  - Graphics module
  - System module
  - Window module

### Compiler Support
- GCC 7.0 or newer
- Clang 5.0 or newer
- MSVC 2017 or newer
- Any C++20 compliant compiler

### Platform Support
- Windows 7 or newer
- Linux (Ubuntu 18.04+, CentOS 8+, etc.)
- macOS 10.14 or newer

## Contributing

We welcome contributions! Here's how you can help:

### Reporting Issues
- Check existing issues before creating new ones
- Provide detailed description, steps to reproduce, and system information
- Include code examples if possible

### Submitting Pull Requests
1. Fork the repository
2. Create a feature branch: `git checkout -b feature/amazing-feature`
3. Commit your changes: `git commit -m 'Add amazing feature'`
4. Push to the branch: `git push origin feature/amazing-feature`
5. Open a Pull Request

### Development Setup
```bash
git clone https://github.com/yourusername/widget-library
cd widget-library
cmake -B build -DBUILD_EXAMPLES=ON -DBUILD_TESTS=ON
cmake --build build
```

## License

This project is licensed under the MIT License - see the LICENSE file for details.

## Getting Help

### Documentation Resources
- Full API Reference: Check header files or generated Doxygen docs
- Examples: See examples/ folder for complete working code

### Common Solutions
- Widgets not appearing: Ensure you call draw() in your render loop
- Events not working: Make sure to call handle_events() for each widget
- Textures not loading: Check file paths and SFML texture loading

## Credits

SFML Widget Library is developed and maintained by Hannes Wagenaar.

### Special Thanks
- The SFML team for an amazing multimedia library
- Contributors and testers who help improve the library
- The open source community for inspiration and support