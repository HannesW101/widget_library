/*
------------------------------------------------------------------------------
Includes
------------------------------------------------------------------------------
*/
#include "widgets/log.h"
#include "widgets/resources.h"
#include "widgets/image.h"
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
    Image::Image(
        sf::RenderWindow&  parent_window,
        sf::Texture const& texture
        ) :
        Widget       (parent_window      ),
        Signals_slots(/*---------------*/),
        _sprite      (texture            )
    {

        _sprite.setPosition (DEFAULT_WIDGET_POS);
    }

    Image::Image(
        sf::RenderWindow&  parent_window,
        sf::Texture const& texture,
        sf::IntRect const  texture_rect
        ) :
        Widget       (parent_window      ),
        Signals_slots(/*---------------*/),
        _sprite      (texture            )
    {

        _sprite.setPosition   (DEFAULT_WIDGET_POS);
        _sprite.setTextureRect(texture_rect      );
    }
/*
------------------------------------------------------------------------------
Functionality
------------------------------------------------------------------------------
*/
    void Image::draw() {

        if (_current_state == STATE__HIDDEN) {

            // Dont draw since widget is hidden.
        } else {

            // Can call _update_widget() for final updating
            // of the widget before drawing to the window.
            _update_widget();

            _parent_window.draw(_sprite);
        }
    }

    void Image::move(
        sf::Vector2f const offset
        ) {

        _sprite.move(offset);
    }

    void Image::move(
        float const x,
        float const y
        ) {

        _sprite.move({x, y});
    }

    void Image::rotate(
        sf::Angle const angle
        ) {

        _sprite.rotate(angle);
    }

    void Image::_update_widget() {


    }
/*
------------------------------------------------------------------------------
Set Functions
------------------------------------------------------------------------------
*/
    void Image::set_scale(
        sf::Vector2f const scale
        ) {

        _sprite.setScale(scale);
    }

    void Image::set_scale(
        float const x,
        float const y
        ) {

        _sprite.setScale({x, y});
    }

    void Image::set_pos(
        sf::Vector2f const pos
        ) {

        _sprite.setPosition(pos);
    }

    void Image::set_pos(
        float const x,
        float const y
        ) {

        _sprite.setPosition({x, y});
    }

    void Image::set_origin(
        sf::Vector2f const origin
        ) {

        _sprite.setOrigin(origin);
    }

    void Image::set_origin(
        float const x,
        float const y
        ) {

        _sprite.setOrigin({x, y});
    }

    void Image::set_rotation(
        sf::Angle const angle
        ) {

        _sprite.setRotation(angle);
    }
/*
------------------------------------------------------------------------------
Get Functions
------------------------------------------------------------------------------
*/
    sf::Vector2f Image::get_scale() const {

        return _sprite.getScale();
    }

    float Image::get_scale_x() const {

        return _sprite.getScale().x;
    }

    float Image::get_scale_y() const {

        return _sprite.getScale().y;
    }

    sf::Vector2f Image::get_pos() const {

        return _sprite.getPosition();
    }

    float Image::get_pos_x() const {

        return _sprite.getPosition().x;
    }

    float Image::get_pos_y() const {

        return _sprite.getPosition().y;
    }

    sf::Vector2f Image::get_origin() const {

        return _sprite.getOrigin();
    }

    float Image::get_origin_x() const {

        return _sprite.getOrigin().x;
    }

    float Image::get_origin_y() const {

        return _sprite.getOrigin().y;
    }

    sf::Angle Image::get_rotation() const {

        return _sprite.getRotation();
    }
}
/*
------------------------------------------------------------------------------
Namespace widgets END
------------------------------------------------------------------------------
*/
