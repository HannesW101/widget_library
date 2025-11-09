/// @file Sprite_button.h
/// @brief A button widget that uses SFML sprites for visual representation

#ifndef SPRITE_BUTTON_H
#define SPRITE_BUTTON_H

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

    /// @brief A button widget that uses SFML sprites for visual representation
    ///
    /// @details The Sprite_button class provides a button implementation using
    ///          SFML sprites with built-in hover detection and mouse click handling.
    ///          It inherits from both Widget for rendering capabilities and
    ///          Signals_slots for event handling.
    ///
    /// @ingroup Widgets
    class Sprite_button final :
        public widgets::Widget,
        public signals_slots::Signals_slots {
        // =========================================================================
        // Construction / Destruction
        // =========================================================================
    public:
        /// @brief Default constructor is deleted - widgets require a parent window
        Sprite_button() = delete;

        /// @brief Construct a Sprite_button with a texture
        /// @details This constructor initializes a Sprite_button with
        ///          your chosen texture and the default values:
        ///          - Scale: The scale of the texture passed in by `texture`
        ///          - Position: (0, 0)
        /// @param parent_window The parent window to draw the widget to
        /// @param texture The texture that will be applied to the sprite button
        Sprite_button(sf::RenderWindow& parent_window, sf::Texture const& texture);

        /// @brief Construct a Sprite_button with a texture and texture rectangle
        /// @details This constructor initializes a Sprite_button with
        ///          your chosen texture, texture rectangle, and the default values:
        ///          - Scale: The scale of the texture passed in by `texture`
        ///          - Position: (0, 0)
        /// @param parent_window The parent window to draw the widget to
        /// @param texture The texture that will be applied to the sprite button
        /// @param texture_rect This rectangle defines a section of `texture` that will be
        ///                     displayed as the texture of the sprite button
        Sprite_button(
            sf::RenderWindow&  parent_window,
            sf::Texture const& texture,
            sf::IntRect const  texture_rect
            );

        /// @brief Default destructor
        ~Sprite_button() = default;

    private:
        /// @brief SFML sprite used for rendering the button
        sf::Sprite _btn_sprite;

        // =========================================================================
        // Rule of 5 - Deleted Operations
        // =========================================================================
        // There is no need for any of these operations. Widgets should be
        // added using pointers and new, not copied or assigned as this can
        // get a bit confusing with more complicated widgets referencing
        // the same thing or containing pointers to other widgets etc.
    public:
        Sprite_button           (Sprite_button const&) = delete; ///< Copy constructor deleted
        Sprite_button& operator=(Sprite_button const&) = delete; ///< Copy assignment deleted
        Sprite_button           (Sprite_button&&     ) = delete; ///< Move constructor deleted
        Sprite_button& operator=(Sprite_button&&     ) = delete; ///< Move assignment deleted

        // =========================================================================
        // Core Functionality
        // =========================================================================
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

        // =========================================================================
        // Setter Functions
        // =========================================================================
    public:
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

        // =========================================================================
        // Getter Functions
        // =========================================================================
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
        /// @return sf::Angle Rotation angle for the widget
        sf::Angle get_rotation() const override;

        // =========================================================================
        // Signals / Slots
        // =========================================================================
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

        // =========================================================================
        // Helper Functions
        // =========================================================================
    private:
        /// @brief Check if the mouse is hovering over the button
        /// @details Helper function used by `_handle_hover(sf::Event const& event)`.
        ///          It checks if the mouse is within the bounds of our button rectangle
        ///          and if it is then a hovering signal will be emitted.
        /// @return true if hovering, false otherwise
        bool _is_hovering() const;

    }; // class Sprite_button

} // namespace widgets

#endif // SPRITE_BUTTON_H
