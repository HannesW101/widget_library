/// @file Image.h
/// @brief An image display widget using SFML sprites

#ifndef IMAGE_H
#define IMAGE_H

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

    /// @brief An image display widget using SFML sprites
    ///
    /// @details The Image class provides a widget for displaying textures and sprites
    ///          with support for texture rectangles, scaling, positioning, and rotation.
    ///
    /// @ingroup Widgets
    class Image final :
        public widgets::Widget,
        public signals_slots::Signals_slots {
        /*
        ------------------------------------------------------------------------------
        Construction / Destruction
        ------------------------------------------------------------------------------
        */
    public:
        /// @brief Default constructor is deleted - widgets require a parent window
        Image() = delete;

        /// @brief Construct an Image with a texture
        /// @details This constructor initializes an Image with your chosen texture
        ///          and the default values:
        ///          - Scale: The scale of the texture passed in by `texture`
        ///          - Position: (0, 0)
        /// @param parent_window The parent window to draw the widget to
        /// @param texture The texture that will be applied to the Image
        Image(sf::RenderWindow& parent_window, sf::Texture const& texture);

        /// @brief Construct an Image with a texture and texture rectangle
        /// @details This constructor initializes an Image with your chosen texture,
        ///          texture rectangle, and the default values:
        ///          - Scale: The scale of the texture passed in by `texture`
        ///          - Position: (0, 0)
        /// @param parent_window The parent window to draw the widget to
        /// @param texture The texture that will be applied to the Image
        /// @param texture_rect This rectangle defines a section of `texture` that will be
        ///                     displayed as the texture of the Image
        Image(
            sf::RenderWindow&  parent_window,
            sf::Texture const& texture,
            sf::IntRect const  texture_rect
            );

        /// @brief Default destructor
        ~Image() = default;

    private:
        /// @brief SFML sprite for rendering the image
        sf::Sprite _sprite;

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
        Image           (Image const&) = delete; ///< Copy constructor deleted
        Image& operator=(Image const&) = delete; ///< Copy assignment deleted
        Image           (Image&&     ) = delete; ///< Move constructor deleted
        Image& operator=(Image&&     ) = delete; ///< Move assignment deleted

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

    }; // class Image

} // namespace widgets

#endif // IMAGE_H
