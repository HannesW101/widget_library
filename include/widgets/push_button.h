/// @file Push_button.h
/// @brief A button widget with rectangle shape and text label

#ifndef PUSH_BUTTON_H
#define PUSH_BUTTON_H

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

    /// @brief A button widget with rectangle shape and text label
    ///
    /// @details The Push_button class provides a rectangular button with
    ///          customizable appearance including colors, text, borders,
    ///          and event handling for hover and click interactions.
    ///
    /// @ingroup Widgets
    class Push_button final :
        public widgets::Widget,
        public signals_slots::Signals_slots {
        /*
        ------------------------------------------------------------------------------
        Construction / Destruction
        ------------------------------------------------------------------------------
        */
    public:
        /// @brief Default constructor is deleted - widgets require a parent window
        Push_button() = delete;

        /// @brief Construct a Push_button with default values
        /// @details This constructor initializes a Push_button with default values:
        ///          - Size: (0, 0)
        ///          - Position: (0, 0)
        ///          - Fill color: Magenta
        ///          - Text: No text
        ///          - Text Font: Default font defined in constants
        ///          - Text Character Size: 30 pixels
        ///          - Text color: Black
        ///          - Border thickness: 0.0f
        ///          - Border color: Black
        /// @param parent_window The parent window to draw the widget to
        explicit Push_button(std::shared_ptr<sf::RenderWindow> parent_window);

        /// @brief Default destructor
        ~Push_button() = default;

    private:
        /// @brief Rectangle shape representing the button
        sf::RectangleShape _btn_rect;

        /// @brief Text label displayed on the button
        sf::Text           _btn_text;

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
        Push_button           (Push_button const&) = delete; ///< Copy constructor deleted
        Push_button& operator=(Push_button const&) = delete; ///< Copy assignment deleted
        Push_button           (Push_button&&     ) = delete; ///< Move constructor deleted
        Push_button& operator=(Push_button&&     ) = delete; ///< Move assignment deleted

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

    private:
        /// @brief Final updates before drawing
        void _update_widget() override;

        /*
        ------------------------------------------------------------------------------
        Setter Functions
        ------------------------------------------------------------------------------
        */
    public:
        /// @brief Set the widget's size
        /// @warning This will not set the size of the text
        /// @param size Vector size for the widget
        void set_size(sf::Vector2f const size) override;

        /// @brief Set the widget's size
        /// @warning This will not set the size of the text
        /// @param x Width
        /// @param y Height
        void set_size(float const x, float const y) override;

        /// @brief Set the widget's text character size
        /// @warning If this new character size causes the widget's text to go out of bounds
        ///          of the widget, then it will default to the maximum character size
        ///          available for that size widget
        /// @param char_size Character size for the widget's text
        void set_char_size(std::uint32_t const char_size);

        /// @brief Set the widget's scale and all its associated components
        /// @param scale Vector scale for the widget
        void set_scale(sf::Vector2f const scale) override;

        /// @brief Set the widget's scale and all its associated components
        /// @param x X scale factor
        /// @param y Y scale factor
        void set_scale(float const x, float const y) override;

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

        /// @brief Set the widget's color
        /// @warning Does not set the color of the text
        /// @param color Color for the widget
        void set_color(sf::Color const color);

        /// @brief Set the widget's text color
        /// @param color Color for the widget's text
        void set_text_color(sf::Color const color);

        /// @brief Set the widget's text string
        /// @param string String for the widget's text
        void set_text_string(sf::String const string);

        /// @brief Set the widget's text style
        /// @warning If you pass an invalid sf style this function will leave the
        ///          text style as is and give a warning log
        /// @param style Style for the widget's text
        void set_text_style(std::uint32_t const& style);

        /// @brief Set the widget's border thickness
        /// @warning If you pass in negative values the border thickness will be
        ///          set to 0.0f and gives a warning log
        /// @param thickness Thickness for the widget's border
        void set_border_thickness(float const thickness);

        /// @brief Set the widget's border color
        /// @param color Color for the widget's border
        void set_border_color(sf::Color const color);

        /// @brief Set the widget's text border thickness
        /// @warning If you pass in negative values the border thickness will be
        ///          set to 0.0f and gives a warning log
        /// @param thickness Thickness for the widget's text border
        void set_text_border_thickness(float const thickness);

        /// @brief Set the widget's text border color
        /// @param color Color for the widget's text border
        void set_text_border_color(sf::Color const color);

        /*
        ------------------------------------------------------------------------------
        Getter Functions
        ------------------------------------------------------------------------------
        */
    public:
        /// @brief Get the widget's size
        /// @warning This will not get the size of the text
        /// @return Vector size for the widget
        sf::Vector2f get_size() const override;

        /// @brief Get the widget's width
        /// @warning This will not get the width of the text
        /// @return float Width for the widget
        float get_size_x() const override;

        /// @brief Get the widget's height
        /// @warning This will not get the height of the text
        /// @return float Height for the widget
        float get_size_y() const override;

        /// @brief Get the widget's text character size
        /// @return Character size for the widget's text
        std::uint32_t get_char_size() const;

        /// @brief Get the widget's scale
        /// @warning This will not get the scale of the text
        /// @return Vector scale for the widget
        sf::Vector2f get_scale() const override;

        /// @brief Get the widget's X scale
        /// @warning This will not get the X scale of the text
        /// @return float X scale factor for the widget
        float get_scale_x() const override;

        /// @brief Get the widget's Y scale
        /// @warning This will not get the Y scale of the text
        /// @return float Y scale factor for the widget
        float get_scale_y() const override;

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

        /// @brief Get the widget's color
        /// @warning This will not get the color of the text
        /// @return Color for the widget
        sf::Color get_color() const;

        /// @brief Get the widget's text color
        /// @return Color for the widget's text
        sf::Color get_text_color() const;

        /// @brief Get the widget's text string
        /// @return String for the widget's text
        sf::String get_text_string() const;

        /// @brief Get the widget's text style
        /// @return Style for the widget's text
        std::uint32_t get_text_style() const;

        /// @brief Get the widget's border thickness
        /// @return Thickness for the widget's border
        float get_border_thickness() const;

        /// @brief Get the widget's border color
        /// @return Color for the widget's border
        sf::Color get_border_color() const;

        /// @brief Get the widget's text border thickness
        /// @return Thickness for the widget's text border
        float get_text_border_thickness() const;

        /// @brief Get the widget's text border color
        /// @return Color for the widget's text border
        sf::Color get_text_border_color() const;

        /*
        ------------------------------------------------------------------------------
        Signals / Slots
        ------------------------------------------------------------------------------
        */
    private:
        /// @brief Handle hover events for the button
        /// @details Overrides base Signals_slots function for this specific widget.
        ///          Checks if the mouse is within the bounds of our button rectangle
        ///          and if it is then a hovering signal will be emitted.
        /// @param event The SFML event to process
        void _handle_hover(sf::Event const& event) override;

        /// @brief Handle mouse button press events for the button
        /// @details Overrides base Signals_slots function for this specific widget.
        ///          Checks if the mouse is within the bounds of our button rectangle
        ///          and if it is then a mouse pressed event from base class will be checked.
        /// @param event The SFML event to process
        void _handle_mouse_button_pressed_events(sf::Event const& event) override;

        /*
        ------------------------------------------------------------------------------
        Helper Functions
        ------------------------------------------------------------------------------
        */
    private:
        /// @brief Center the text on the button
        /// @details Should be called after every update to the button like setting
        ///          its size, positioning the button, scaling the button, etc.
        void _center_text_on_btn();

        /// @brief Fit text to button size
        /// @details Helper function used by `_center_text_on_btn()`. It checks if
        ///          the current character size fits for a button of this size and
        ///          if it does not, it will decrease the character size until either
        ///          it does fit or the character size reaches 1.
        void _fit_text_to_btn();

        /// @brief Check if the mouse is hovering over the button
        /// @details Helper function used by `_handle_hover(sf::Event const& event)`.
        ///          It checks if the mouse is within the bounds of our button rectangle
        ///          and if it is then a hovering signal will be emitted.
        /// @return true if hovering, false otherwise
        bool _is_hovering() const;

    }; // class Push_button

} // namespace widgets

#endif // PUSH_BUTTON_H
