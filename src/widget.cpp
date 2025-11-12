/*
------------------------------------------------------------------------------
Includes
------------------------------------------------------------------------------
*/
#include "widgets/log.h"
#include "widgets/widget.h"

#include <string>
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
    Widget::Widget(
        std::shared_ptr<sf::RenderWindow> parent_window
        ) :
        _parent_window(std::move(parent_window)),
        _current_state(STATE__DEFAULT          )
    {}
/*
------------------------------------------------------------------------------
State management
------------------------------------------------------------------------------
*/
    std::string Widget::state_to_str(
        State const state
        ) const {

        std::string str = "UNDEFINED";

        switch (state) {

        case STATE__DEFAULT:  str = "STATE__DEFAULT";  break;
        case STATE__HIDDEN:   str = "STATE__HIDDEN";   break;
        case STATE__HOVERING: str = "STATE__HOVERING"; break;
        case STATE__TYPING:   str = "STATE__TYPING"; break;
        }

        return str;
    }

    void Widget::change_state(
        State const state_to_change_to
        ) {

        if (_current_state == state_to_change_to) {

            // Already in that state so no need to change.
        } else {

            LOG(TRACE)                        <<
            "Changing from state ["           <<
            state_to_str(_current_state)     <<
            "] to state ["                    <<
            state_to_str(state_to_change_to) <<
            "].";

            _current_state = state_to_change_to;
        }
    }
/*
------------------------------------------------------------------------------
Functionality
------------------------------------------------------------------------------
*/
    void Widget::draw() {

        if (_current_state == STATE__HIDDEN) {

            // Dont draw since widget is hidden.
        } else {

            // Can call _update_widget() for final updating
            // of the widget before drawing to the window.
            _update_widget();

            // Draw to window here.
            LOG(WARNING)                        <<
            "Widget is not drawn to screen, "   <<
            "draw() base class function needs " <<
            "to be overridden and this log removed.";
        }
    }

    void Widget::move(
        sf::Vector2f const offset
        ) {

        LOG(WARNING)               <<
        "Widget is not moved to [" <<
        offset.x                   <<
        ", "                       <<
        offset.y                   <<
        "] as this function is not implemented.";
    }

    void Widget::move(
        float const x,
        float const y
        ) {

        LOG(WARNING)               <<
        "Widget is not moved to [" <<
        x                          <<
        ", "                       <<
        y                          <<
        "] as this function is not implemented.";
    }

    void Widget::rotate(
        sf::Angle const angle
        ) {

        LOG(WARNING)                 <<
        "Widget is not rotated by [" <<
        angle.asDegrees()            <<
        "]-degrees or ["             <<
        angle.asRadians()            <<
        "]-radians, as this function is not implemented.";
    }

    void Widget::_update_widget() {

        LOG(WARNING)                                 <<
        "Widget is not updated before drawing, "     <<
        "update_widget() base class function needs " <<
        "to be overridden or removed and this log removed.";
    }
/*
------------------------------------------------------------------------------
Set Functions
------------------------------------------------------------------------------
*/
    void Widget::set_size(
        sf::Vector2f const size
        ) {

        LOG(WARNING)                  <<
        "Widget size is not set to [" <<
        size.x                        <<
        ", "                          <<
        size.y                        <<
        "] as this function is not implemented.";
    }

    void Widget::set_size(
        float const x,
        float const y
        ) {

        LOG(WARNING)                  <<
        "Widget size is not set to [" <<
        x                             <<
        ", "                          <<
        y                             <<
        "] as this function is not implemented.";
    }

    void Widget::set_scale(
        sf::Vector2f const scale
        ) {

        LOG(WARNING)                   <<
        "Widget scale is not set to [" <<
        scale.x                        <<
        ", "                           <<
        scale.y                        <<
        "] as this function is not implemented.";
    }

    void Widget::set_scale(
        float const x,
        float const y
        ) {

        LOG(WARNING)                   <<
        "Widget scale is not set to [" <<
        x                              <<
        ", "                           <<
        y                              <<
        "] as this function is not implemented.";
    }

    void Widget::set_pos(
        sf::Vector2f const pos
        ) {

        LOG(WARNING)                      <<
        "Widget position is not set to [" <<
        pos.x                             <<
        ", "                              <<
        pos.y                             <<
        "] as this function is not implemented.";
    }

    void Widget::set_pos(
        float const x,
        float const y
        ) {

        LOG(WARNING)                      <<
        "Widget position is not set to [" <<
        x                                 <<
        ", "                              <<
        y                                 <<
        "] as this function is not implemented.";
    }

    void Widget::set_origin(
        sf::Vector2f const origin
        ) {

        LOG(WARNING)                    <<
        "Widget origin is not set to [" <<
        origin.x                        <<
        ", "                            <<
        origin.y                        <<
        "] as this function is not implemented.";
    }

    void Widget::set_origin(
        float const x,
        float const y
        ) {

        LOG(WARNING)                    <<
        "Widget origin is not set to [" <<
        x                               <<
        ", "                            <<
        y                               <<
        "] as this function is not implemented.";
    }

    void Widget::set_rotation(
        sf::Angle const angle
        ) {

        LOG(WARNING)                      <<
        "Widget rotation is not set to [" <<
        angle.asDegrees()                 <<
        "]-degrees or ["                  <<
        angle.asRadians()                 <<
        "]-radians, as this function is not implemented.";
    }
/*
------------------------------------------------------------------------------
Get Functions
------------------------------------------------------------------------------
*/
    sf::Vector2f Widget::get_size() const {

        LOG(WARNING)                    <<
        "Cannot get the size as this "  <<
        "function is not implemented. " <<
        "returning {0.0f, 0.0f}.";

        return {0.0f, 0.0f};
    }

    float Widget::get_size_x() const {

        LOG(WARNING)                     <<
        "Cannot get the x-size as this " <<
        "function is not implemented. "  <<
        "returning 0.0f.";

        return 0.0f;
    }

    float Widget::get_size_y() const {

        LOG(WARNING)                     <<
        "Cannot get the y-size as this " <<
        "function is not implemented. "  <<
        "returning 0.0f.";

        return 0.0f;
    }

    sf::Vector2f Widget::get_scale() const {

        LOG(WARNING)                    <<
        "Cannot get the scale as this " <<
        "function is not implemented. " <<
        "returning {0.0f, 0.0f}.";

        return {0.0f, 0.0f};
    }

    float Widget::get_scale_x() const {

        LOG(WARNING)                      <<
        "Cannot get the x-scale as this " <<
        "function is not implemented. "   <<
        "returning 0.0f.";

        return 0.0f;
    }

    float Widget::get_scale_y() const {

        LOG(WARNING)                      <<
        "Cannot get the y-scale as this " <<
        "function is not implemented. "   <<
        "returning 0.0f.";

        return 0.0f;
    }

    sf::Vector2f Widget::get_pos() const {

        LOG(WARNING)                       <<
        "Cannot get the position as this " <<
        "function is not implemented. "    <<
        "returning {0.0f, 0.0f}.";

        return {0.0f, 0.0f};
    }

    float Widget::get_pos_x() const {

        LOG(WARNING)                         <<
        "Cannot get the x-position as this " <<
        "function is not implemented. "      <<
        "returning 0.0f.";

        return 0.0f;
    }

    float Widget::get_pos_y() const {

        LOG(WARNING)                         <<
        "Cannot get the y-position as this " <<
        "function is not implemented. "      <<
        "returning 0.0f.";

        return 0.0f;
    }

    sf::Vector2f Widget::get_origin() const {

        LOG(WARNING)                     <<
        "Cannot get the origin as this " <<
        "function is not implemented. "  <<
        "returning {0.0f, 0.0f}.";

        return {0.0f, 0.0f};
    }

    float Widget::get_origin_x() const {

        LOG(WARNING)                       <<
        "Cannot get the x-origin as this " <<
        "function is not implemented. "    <<
        "returning 0.0f.";

        return 0.0f;
    }

    float Widget::get_origin_y() const {

        LOG(WARNING)                       <<
        "Cannot get the y-origin as this " <<
        "function is not implemented. "    <<
        "returning 0.0f.";

        return 0.0f;
    }

    sf::Angle Widget::get_rotation() const {

        LOG(WARNING)                       <<
        "Cannot get the rotation as this " <<
        "function is not implemented. "    <<
        "returning 0.0f degrees/radians.";

        return sf::degrees(0.0f);
    }
/*
------------------------------------------------------------------------------
Helper Functions
------------------------------------------------------------------------------
*/
    bool Widget::_is_parent_window_nullptr() const {

        if (_parent_window.expired()) {

            LOG(WARNING) << "_parent_window is nullptr";
            return true;
        } else {

            return false;
        }
    }
}
/*
------------------------------------------------------------------------------
Namespace widgets END
------------------------------------------------------------------------------
*/
