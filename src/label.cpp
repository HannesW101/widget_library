/*
------------------------------------------------------------------------------
Includes
------------------------------------------------------------------------------
*/
#include "widgets/log.h"
#include "widgets/resources.h"
#include "widgets/label.h"
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
    Label::Label(
        sf::RenderWindow&  parent_window,
        sf::String const&  string
        ) :
        Widget       (parent_window      ),
        Signals_slots(/*---------------*/),
        _lbl_text    (DEFAULT_WIDGET_FONT)
    {

        _lbl_text.setPosition (DEFAULT_WIDGET_POS);
        _lbl_text.setString   (string            );
        _lbl_text.setFillColor(sf::Color::Black  );
    }
/*
------------------------------------------------------------------------------
Functionality
------------------------------------------------------------------------------
*/
    void Label::draw() {

        if (_current_state == STATE__HIDDEN) {

            // Dont draw since widget is hidden.
        } else {

            // Can call _update_widget() for final updating
            // of the widget before drawing to the window.
            _update_widget();

            _parent_window.draw(_lbl_text);
        }
    }

    void Label::move(
        sf::Vector2f const offset
        ) {

        _lbl_text.move(offset);
    }

    void Label::move(
        float const x,
        float const y
        ) {

        _lbl_text.move({x, y});
    }

    void Label::rotate(
        sf::Angle const angle
        ) {

        _lbl_text.rotate(angle);
    }

    void Label::_update_widget() {


    }
/*
------------------------------------------------------------------------------
Set Functions
------------------------------------------------------------------------------
*/
    void Label::set_scale(
        sf::Vector2f const scale
        ) {

        _lbl_text.setScale(scale);
    }

    void Label::set_scale(
        float const x,
        float const y
        ) {

        _lbl_text.setScale({x, y});
    }

    void Label::set_char_size(
        std::uint32_t const char_size
        ) {

        _lbl_text.setCharacterSize(char_size);
    }

    void Label::set_pos(
        sf::Vector2f const pos
        ) {

        _lbl_text.setPosition(pos);
    }

    void Label::set_pos(
        float const x,
        float const y
        ) {

        _lbl_text.setPosition({x, y});
    }

    void Label::set_origin(
        sf::Vector2f const origin
        ) {

        _lbl_text.setOrigin(origin);
    }

    void Label::set_origin(
        float const x,
        float const y
        ) {

        _lbl_text.setOrigin({x, y});
    }

    void Label::set_rotation(
        sf::Angle const angle
        ) {

        _lbl_text.setRotation(angle);
    }

    void Label::set_text_color(
        sf::Color const color
        ) {

        _lbl_text.setFillColor(color);
    }

    void Label::set_text_string(
        sf::String const string
        ) {

        _lbl_text.setString(string);
    }

    void Label::set_text_style(
        std::uint32_t const& style
        ) {

        using sf::Text::Style::Regular;
        using sf::Text::Style::Bold;
        using sf::Text::Style::Italic;
        using sf::Text::Style::Underlined;
        using sf::Text::Style::StrikeThrough;

        std::uint32_t const valid_style_mask =
        Regular | Bold | Italic | Underlined | StrikeThrough;

        // Is a valid style.
        if (style & valid_style_mask) {

            _lbl_text.setStyle(style);
        } else {

            LOG(WARNING)                            <<
            "Style for widget text is not set to [" <<
            style                                   <<
            "] as this is not a valid sf text style.";
        }
    }
/*
------------------------------------------------------------------------------
Get Functions
------------------------------------------------------------------------------
*/
    sf::Vector2f Label::get_scale() const {

        return _lbl_text.getScale();
    }

    float Label::get_scale_x() const {

        return _lbl_text.getScale().x;
    }

    float Label::get_scale_y() const {

        return _lbl_text.getScale().y;
    }

    sf::Vector2f Label::get_pos() const {

        return _lbl_text.getPosition();
    }

    float Label::get_pos_x() const {

        return _lbl_text.getPosition().x;
    }

    float Label::get_pos_y() const {

        return _lbl_text.getPosition().y;
    }

    sf::Vector2f Label::get_origin() const {

        return _lbl_text.getOrigin();
    }

    float Label::get_origin_x() const {

        return _lbl_text.getOrigin().x;
    }

    float Label::get_origin_y() const {

        return _lbl_text.getOrigin().y;
    }

    sf::Angle Label::get_rotation() const {

        return _lbl_text.getRotation();
    }

    sf::Color Label::get_text_color() const {

        return _lbl_text.getFillColor();
    }

    sf::String Label::get_text_string() const {

        return _lbl_text.getString();
    }

    std::uint32_t Label::get_text_style() const {

        return _lbl_text.getStyle();
    }

    void Label::set_text_border_thickness(
        float const thickness
        ) {

        _lbl_text.setOutlineThickness(thickness);
    }

    void Label::set_text_border_color(
        sf::Color const color
        ) {

        _lbl_text.setOutlineColor(color);
    }
/*
------------------------------------------------------------------------------
Signals / slots
------------------------------------------------------------------------------
*/
    void Label::_handle_hover(
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

    void Label::_handle_mouse_button_pressed_events(
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
    bool Label::_is_hovering() const {

        bool is_hovering = false;

        sf::Vector2i  const mouse_pos_pixels = sf::Mouse::getPosition         (_parent_window  );
        sf::Vector2f  const mouse_pos_coords = _parent_window.mapPixelToCoords(mouse_pos_pixels);
        sf::FloatRect const lbl_bounds       = _lbl_text.getGlobalBounds      (/*------------*/);

        if (lbl_bounds.contains(mouse_pos_coords)) {

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
