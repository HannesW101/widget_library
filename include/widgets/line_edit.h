/// @file Line_edit.h
/// @brief A text input widget for single-line text entry

#ifndef LINE_EDIT_H
#define LINE_EDIT_H

/*
------------------------------------------------------------------------------
Includes
------------------------------------------------------------------------------
*/
#include "widgets/signals_slots.h"
#include "widgets/widget.h"
#include "SFML/Graphics.hpp"

/*
------------------------------------------------------------------------------
Namespace widgets BEGIN
------------------------------------------------------------------------------
*/
namespace widgets {

    /// @brief A text input widget for single-line text entry
    ///
    /// @details The Line_edit class provides a text input field with placeholder text,
    ///          character limits, and typing state management. It supports text entry,
    ///          deletion, and various styling options.
    ///
    /// @ingroup Widgets
    class Line_edit final :
        public widgets::Widget,
        public signals_slots::Signals_slots {
        /*
        ------------------------------------------------------------------------------
        Construction / Destruction
        ------------------------------------------------------------------------------
        */
    public:
        /// @brief Default constructor is deleted - widgets require a parent window
        Line_edit() = delete;

        /// @brief Construct a Line_edit with default values
        /// @details This constructor initializes a Line_edit with the default values:
        ///          - Position: (0, 0)
        ///          - Placeholder text: Either `placeholder_string` parameter or
        ///            "placeholder string" if parameter is omitted
        ///          - Placeholder text color: Black (50% opacity)
        ///          - Text Font: Default font defined in constants
        ///          - Text Character Size: 30 pixels
        ///          - Text color: Black
        ///          - Max characters: 18
        ///          - Fill color: Magenta
        ///          - Border: No border
        /// @param parent_window The parent window to draw the widget to
        /// @param placeholder_string The text placeholder string for Line_edit
        explicit Line_edit(
            sf::RenderWindow& parent_window,
            sf::String const& placeholder_string = "placeholder string"
            );

        /// @brief Default destructor
        ~Line_edit() = default;

    private:
        /// @brief Text object for displaying typed characters
        sf::Text _le_typing_text;

        /// @brief Text object for displaying placeholder text when empty
        sf::Text _le_placeholder_text;

        /// @brief Rectangle shape representing the input field background
        sf::RectangleShape _le_rect;

        /// @brief Maximum number of characters allowed in the input field
        std::uint32_t _max_chars;

        /// @brief Currently typed character to be appended
        sf::String _typed_char;

        /*
        ------------------------------------------------------------------------------
        Rule of 5
        ------------------------------------------------------------------------------
        */
        // There is no need for any of these operations. Widgets should be
        // added using pointers and new, not copied or assigned as this can
        // get a bit confusing with more complicated widgets referencing
        // the same thing or containing pointers to other widgets etc.
    public:
        Line_edit           (Line_edit const&) = delete; ///< Copy constructor deleted
        Line_edit& operator=(Line_edit const&) = delete; ///< Copy assignment deleted
        Line_edit           (Line_edit&&     ) = delete; ///< Move constructor deleted
        Line_edit& operator=(Line_edit&&     ) = delete; ///< Move assignment deleted

        /*
        ------------------------------------------------------------------------------
        Core Functionality
        ------------------------------------------------------------------------------
        */
    public:
        /// @brief Draws the widget to the parent window
        void draw() override;

        /// @brief Moves the widget and all its associated components
        /// @param offset Vector offset to move the widget by
        void move(sf::Vector2f const offset) override;

        /// @brief Moves the widget and all its associated components
        /// @param x X coordinate offset
        /// @param y Y coordinate offset
        void move(float const x, float const y) override;

        /// @brief Rotates the widget and all its associated components
        /// @param angle Rotation angle that will be added to current rotation angle
        void rotate(sf::Angle const angle) override;

        /// @brief Append the current typed character to the input field
        /// @warning This will only append if we are in the typing state and we have
        ///          not yet reached our maximum number of characters
        void append_typed_char();

        /// @brief Delete the last character from the input field
        /// @warning This will only delete if we are in the typing state and the
        ///          typing text string size is greater than 0
        void delete_char();

    private:
        /// @brief Final updates before drawing
        void _update_widget() override;

        /*
        ------------------------------------------------------------------------------
        Setter Functions
        ------------------------------------------------------------------------------
        */
    public:
        /// @brief Set the widget's maximum number of characters
        /// @param max_chars Maximum number of characters for the widget's text
        void set_max_chars(std::uint32_t const max_chars);

        /// @brief Set the widget's text character size
        /// @param char_size Character size for the widget's text
        void set_char_size(std::uint32_t const char_size);

        /// @brief Set the widget's position and all its associated components
        /// @param pos Vector position for the widget
        void set_pos(sf::Vector2f const pos) override;

        /// @brief Set the widget's position and all its associated components
        /// @param x X coordinate
        /// @param y Y coordinate
        void set_pos(float const x, float const y) override;

        /// @brief Set the widget's origin and all its associated components
        /// @param origin Vector origin for the widget
        void set_origin(sf::Vector2f const origin) override;

        /// @brief Set the widget's origin and all its associated components
        /// @param x X origin
        /// @param y Y origin
        void set_origin(float const x, float const y) override;

        /// @brief Set the widget's rotation and all its associated components
        /// @param angle Angle for the rotation of the widget
        void set_rotation(sf::Angle const angle) override;

        /// @brief Set the widget's typing text color
        /// @param color Color for the widget's typing text
        /// @warning If you desire a certain opacity then make sure to set it for
        ///          the sf::Color that you pass
        void set_typing_text_color(sf::Color const color);

        /// @brief Set the widget's placeholder text color
        /// @param color Color for the widget's placeholder text
        /// @warning If you desire a certain opacity then make sure to set it for
        ///          the sf::Color that you pass
        void set_placeholder_text_color(sf::Color const color);

        /// @brief Set the widget's typing text style
        /// @warning If you pass an invalid sf style this function will leave the
        ///          typing text style as is and give a warning log
        /// @param style Style for the widget's typing text
        void set_typing_text_style(std::uint32_t const& style);

        /// @brief Set the widget's placeholder text style
        /// @warning If you pass an invalid sf style this function will leave the
        ///          placeholder text style as is and give a warning log
        /// @param style Style for the widget's placeholder text
        void set_placeholder_text_style(std::uint32_t const& style);

        /// @brief Set the widget's border thickness
        /// @warning If you pass in negative values the border thickness will be
        ///          set to 0.0f and gives a warning log
        /// @param thickness Thickness for the widget's border
        void set_border_thickness(float const thickness);

        /// @brief Set the widget's border color
        /// @param color Color for the widget's border
        void set_border_color(sf::Color const color);

        /*
        ------------------------------------------------------------------------------
        Getter Functions
        ------------------------------------------------------------------------------
        */
    public:
        /// @brief Get the widget's text character size
        /// @return Character size for the widget's text
        std::uint32_t get_char_size() const;

        /// @brief Get the widget's position
        /// @return Vector position for the widget
        sf::Vector2f get_pos() const override;

        /// @brief Get the widget's X position
        /// @return float X coordinate for the widget
        float get_pos_x() const override;

        /// @brief Get the widget's Y position
        /// @return float Y coordinate for the widget
        float get_pos_y() const override;

        /// @brief Get the widget's origin
        /// @return Vector origin for the widget
        sf::Vector2f get_origin() const override;

        /// @brief Get the widget's X origin
        /// @return float X origin for the widget
        float get_origin_x() const override;

        /// @brief Get the widget's Y origin
        /// @return float Y origin for the widget
        float get_origin_y() const override;

        /// @brief Get the widget's rotation angle
        /// @return Rotation angle for the widget
        sf::Angle get_rotation() const override;

        /// @brief Get the widget's typing text string
        /// @return String for the widget's typing text
        sf::String get_typing_text_string() const;

        /// @brief Get the widget's typing text color
        /// @return Color for the widget's typing text
        sf::Color get_typing_text_color() const;

        /// @brief Get the widget's placeholder text color
        /// @return Color for the widget's placeholder text
        sf::Color get_placeholder_text_color() const;

        /// @brief Get the widget's typing text style
        /// @return Style for the widget's typing text
        std::uint32_t get_typing_text_style() const;

        /// @brief Get the widget's placeholder text style
        /// @return Style for the widget's placeholder text
        std::uint32_t get_placeholder_text_style() const;

        /// @brief Get the widget's border thickness
        /// @return Thickness for the widget's border
        float get_border_thickness() const;

        /// @brief Get the widget's border color
        /// @return Color for the widget's border
        sf::Color get_border_color() const;

        /*
        ------------------------------------------------------------------------------
        Signals / Slots
        ------------------------------------------------------------------------------
        */
    private:
        /// @brief Handle hover events for the line edit
        /// @details Overrides base Signals_slots function for this specific widget.
        ///          Checks if the mouse is within the bounds of our rectangle and
        ///          if it is then a hovering signal will be emitted.
        /// @param event The SFML event to process
        void _handle_hover(sf::Event const& event) override;

        /// @brief Handle text entered events for the line edit
        /// @details Overrides base Signals_slots function for this specific widget.
        ///          When text is entered and we are in the typing state, then the
        ///          text will be appended to the line edit.
        /// @param event The SFML event to process
        void _handle_text_entered_events(sf::Event const& event) override;

        /// @brief Handle mouse button press events for the line edit
        /// @details Overrides base Signals_slots function for this specific widget.
        ///          Checks if the mouse is within the bounds of our widget rectangle
        ///          and if it is then a mouse pressed event from base class will be checked.
        /// @param event The SFML event to process
        void _handle_mouse_button_pressed_events(sf::Event const& event) override;

        /*
        ------------------------------------------------------------------------------
        Helper Functions
        ------------------------------------------------------------------------------
        */
    private:
        /// @brief Check if the mouse is hovering over the line edit
        /// @details Helper function used by `_handle_hover(sf::Event const& event)`.
        ///          It checks if the mouse is within the bounds of our rectangle.
        /// @return true if hovering, false otherwise
        bool _is_hovering() const;

        /// @brief Resize the rectangle to fit the text content
        /// @details Helper function used to resize the rectangle of the line edit
        ///          to always fit the maximum amount of characters measured at the
        ///          widest character for most fonts "W".
        /// @param curr_text The text that `_resize_rect` will use as a reference
        ///                  for resizing based on the number of characters of `curr_text`
        void _resize_rect(sf::Text const& curr_text);

    }; // class Line_edit

} // namespace widgets

#endif // LINE_EDIT_H
