/// @file Label.h
/// @brief A text label widget for displaying static or dynamic text

#ifndef LABEL_H
#define LABEL_H

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

    /// @brief A text label widget for displaying static or dynamic text
    ///
    /// @details The Label class provides a simple text display widget with
    ///          customizable appearance including colors, styles, borders,
    ///          and basic event handling.
    ///
    /// @ingroup Widgets
    class Label final :
        public widgets::Widget,
        public signals_slots::Signals_slots {
        /*
        ------------------------------------------------------------------------------
        Construction / Destruction
        ------------------------------------------------------------------------------
        */
    public:
        /// @brief Default constructor is deleted - widgets require a parent window
        Label() = delete;

        /// @brief Construct a Label with default values
        /// @details This constructor initializes a Label with the default values:
        ///          - Position: (0, 0)
        ///          - Text: Either `string` parameter or "" if parameter is omitted
        ///          - Text Font: Default font defined in constants
        ///          - Text Character Size: 30 pixels
        ///          - Text color: Black
        /// @param parent_window The parent window to draw the widget to
        /// @param string The text string for label
        explicit Label(sf::RenderWindow& parent_window, sf::String const& string = "");

        /// @brief Default destructor
        ~Label() = default;

    private:
        /// @brief SFML text object for displaying the label content
        sf::Text _lbl_text;

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
        Label           (Label const&) = delete; ///< Copy constructor deleted
        Label& operator=(Label const&) = delete; ///< Copy assignment deleted
        Label           (Label&&     ) = delete; ///< Move constructor deleted
        Label& operator=(Label&&     ) = delete; ///< Move assignment deleted

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
        /// @brief Set the widget's scale and all its associated components
        /// @param scale Vector scale for the widget
        void set_scale(sf::Vector2f const scale) override;

        /// @brief Set the widget's scale and all its associated components
        /// @param x X scale factor
        /// @param y Y scale factor
        void set_scale(float const x, float const y) override;

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
        /// @brief Get the widget's scale
        /// @return Vector scale for the widget
        sf::Vector2f get_scale() const override;

        /// @brief Get the widget's X scale
        /// @return float X scale factor for the widget
        float get_scale_x() const override;

        /// @brief Get the widget's Y scale
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

        /// @brief Get the widget's text color
        /// @return Color for the widget's text
        sf::Color get_text_color() const;

        /// @brief Get the widget's text string
        /// @return String for the widget's text
        sf::String get_text_string() const;

        /// @brief Get the widget's text style
        /// @return Style for the widget's text
        std::uint32_t get_text_style() const;

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
        /// @brief Handle hover events for the label
        /// @details Overrides base Signals_slots function for this specific widget.
        ///          Checks if the mouse is within the bounds of our text rectangle
        ///          and if it is then a hovering signal will be emitted.
        /// @param event The SFML event to process
        void _handle_hover(sf::Event const& event) override;

        /// @brief Handle mouse button press events for the label
        /// @details Overrides base Signals_slots function for this specific widget.
        ///          Checks if the mouse is within the bounds of our text rectangle
        ///          and if it is then a mouse pressed event from base class will be checked.
        /// @param event The SFML event to process
        void _handle_mouse_button_pressed_events(sf::Event const& event) override;

        /*
        ------------------------------------------------------------------------------
        Helper Functions
        ------------------------------------------------------------------------------
        */
    private:
        /// @brief Check if the mouse is hovering over the label
        /// @details Helper function used by `_handle_hover(sf::Event const& event)`.
        ///          It checks if the mouse is within the bounds of our text rectangle
        ///          and if it is then a hovering signal will be emitted.
        /// @return true if hovering, false otherwise
        bool _is_hovering() const;

    }; // class Label

} // namespace widgets

#endif // LABEL_H