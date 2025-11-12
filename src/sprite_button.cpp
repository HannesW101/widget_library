/*
------------------------------------------------------------------------------
Includes
------------------------------------------------------------------------------
*/
#include "widgets/log.h"
#include "widgets/resources.h"
#include "widgets/sprite_button.h"
#include "widgets/widget.h"
/*
------------------------------------------------------------------------------
Using namespaces
------------------------------------------------------------------------------
*/
using namespace resources;
using namespace signals_slots;
using namespace widgets;
/*
------------------------------------------------------------------------------
Namespace widgets BEGIN
------------------------------------------------------------------------------
*/
namespace widgets {
/*
------------------------------------------------------------------------------
Construction / Destruction
------------------------------------------------------------------------------
*/
    Sprite_button::Sprite_button(
        std::shared_ptr<sf::RenderWindow> parent_window,
        sf::Texture const& texture
        ) :
        Widget       (std::move(parent_window)),
        Signals_slots(/*--------------------*/),
        _btn_sprite  (texture                 )
    {

        _btn_sprite.setPosition (DEFAULT_WIDGET_POS);
    }

    Sprite_button::Sprite_button(
        std::shared_ptr<sf::RenderWindow> parent_window,
        sf::Texture const& texture,
        sf::IntRect const  texture_rect
        ) :
        Widget       (std::move(parent_window)),
        Signals_slots(/*--------------------*/),
        _btn_sprite  (texture                 )
    {

        _btn_sprite.setPosition   (DEFAULT_WIDGET_POS);
        _btn_sprite.setTextureRect(texture_rect      );
    }
/*
------------------------------------------------------------------------------
Functionality
------------------------------------------------------------------------------
*/
    void Sprite_button::draw() {

        if (_current_state == STATE__HIDDEN) {

            // Dont draw since widget is hidden.
        } else {

            // Can call _update_widget() for final updating
            // of the widget before drawing to the window.
            _update_widget();

            if (!_is_parent_window_nullptr()) {

                auto temp_ptr = _parent_window.lock();
                temp_ptr->draw(_btn_sprite);
            }
        }
    }

    void Sprite_button::move(
        sf::Vector2f const offset
        ) {

        _btn_sprite.move(offset);
    }

    void Sprite_button::move(
        float const x,
        float const y
        ) {

        _btn_sprite.move({x, y});
    }

    void Sprite_button::rotate(
        sf::Angle const angle
        ) {

        _btn_sprite.rotate(angle);
    }

    void Sprite_button::_update_widget() {


    }
/*
------------------------------------------------------------------------------
Set Functions
------------------------------------------------------------------------------
*/
    void Sprite_button::set_scale(
        sf::Vector2f const scale
        ) {

        _btn_sprite.setScale(scale);
    }

    void Sprite_button::set_scale(
        float const x,
        float const y
        ) {

        _btn_sprite.setScale({x, y});
    }

    void Sprite_button::set_pos(
        sf::Vector2f const pos
        ) {

        _btn_sprite.setPosition(pos);
    }

    void Sprite_button::set_pos(
        float const x,
        float const y
        ) {

        _btn_sprite.setPosition({x, y});
    }

    void Sprite_button::set_origin(
        sf::Vector2f const origin
        ) {

        _btn_sprite.setOrigin(origin);
    }

    void Sprite_button::set_origin(
        float const x,
        float const y
        ) {

        _btn_sprite.setOrigin({x, y});
    }

    void Sprite_button::set_rotation(
        sf::Angle const angle
        ) {

        _btn_sprite.setRotation(angle);
    }
/*
------------------------------------------------------------------------------
Get Functions
------------------------------------------------------------------------------
*/
    sf::Vector2f Sprite_button::get_scale() const {

        return _btn_sprite.getScale();
    }

    float Sprite_button::get_scale_x() const {

        return _btn_sprite.getScale().x;
    }

    float Sprite_button::get_scale_y() const {

        return _btn_sprite.getScale().y;
    }

    sf::Vector2f Sprite_button::get_pos() const {

        return _btn_sprite.getPosition();
    }

    float Sprite_button::get_pos_x() const {

        return _btn_sprite.getPosition().x;
    }

    float Sprite_button::get_pos_y() const {

        return _btn_sprite.getPosition().y;
    }

    sf::Vector2f Sprite_button::get_origin() const {

        return _btn_sprite.getOrigin();
    }

    float Sprite_button::get_origin_x() const {

        return _btn_sprite.getOrigin().x;
    }

    float Sprite_button::get_origin_y() const {

        return _btn_sprite.getOrigin().y;
    }

    sf::Angle Sprite_button::get_rotation() const {

        return _btn_sprite.getRotation();
    }
/*
------------------------------------------------------------------------------
Signals / slots
------------------------------------------------------------------------------
*/
    void Sprite_button::_handle_hover(
        sf::Event const& event
        ) {

        static_cast<void>(event);

        // Check if we are hovering and not in a hovering state.
        if (_is_hovering() && _current_state != STATE__HOVERING) {

            change_state(STATE__HOVERING);
            _emit_signal (SIGNAL__HOVER  );
        }

        // Check if we are not hovering and in a hovering state.
        if (!_is_hovering() && _current_state == STATE__HOVERING) {

            change_state(STATE__DEFAULT    );
            _emit_signal (SIGNAL__STOP_HOVER);
        }
    }

    void Sprite_button::_handle_mouse_button_pressed_events(
        sf::Event const& event
        ) {

        if (_is_hovering()) {

            Signals_slots::_handle_mouse_button_pressed_events(event);
        }
    }
/*
------------------------------------------------------------------------------
Helper Functions
------------------------------------------------------------------------------
*/
    bool Sprite_button::_is_hovering() const {

        bool is_hovering = false;

         auto temp_ptr = _parent_window.lock();

        sf::Vector2i  const mouse_pos_pixels = sf::Mouse::getPosition     (*temp_ptr       );
        sf::Vector2f  const mouse_pos_coords = temp_ptr->mapPixelToCoords (mouse_pos_pixels);
        sf::FloatRect const btn_bounds       = _btn_sprite.getGlobalBounds(/*------------*/);

        if (btn_bounds.contains(mouse_pos_coords)) {

            is_hovering = true;
        } else {

            is_hovering = false;
        }

        return is_hovering;
    }
}
/*
------------------------------------------------------------------------------
Namespace widgets END
------------------------------------------------------------------------------
*/
