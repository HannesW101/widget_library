/*
------------------------------------------------------------------------------
Includes
------------------------------------------------------------------------------
*/
#include "widgets/log.h"
#include "widgets/push_button.h"
#include "widgets/resources.h"
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
    Push_button::Push_button(
        sf::RenderWindow& parent_window
        ) :
        Widget       (parent_window      ),
        Signals_slots(/*---------------*/),
        _btn_rect    (DEFAULT_WIDGET_SIZE),
        _btn_text    (DEFAULT_WIDGET_FONT)  // string = "", characterSize = 30
    {

        _btn_rect.setPosition (DEFAULT_WIDGET_POS  );
        _btn_rect.setFillColor(DEFAULT_WIDGET_COLOR);

        _btn_text.setFillColor(DEFAULT_TEXT_COLOR);
    }
/*
------------------------------------------------------------------------------
Functionality
------------------------------------------------------------------------------
*/
    void Push_button::draw() {

        if (_current_state == STATE__HIDDEN) {

            // Dont draw since widget is hidden.
        } else {

            // Can call _update_widget() for final updating
            // of the widget before drawing to the window.
            _update_widget();

            _parent_window.draw(_btn_rect);
            _parent_window.draw(_btn_text);
        }
    }

    void Push_button::move(
        sf::Vector2f const offset
        ) {

        _btn_rect.move(offset);
        _btn_text.move(offset);
    }

    void Push_button::move(
        float const x,
        float const y
        ) {

        _btn_rect.move({x, y});
        _btn_text.move({x, y});
    }

    void Push_button::rotate(
        sf::Angle const angle
        ) {

        _btn_rect.rotate(angle);
        _btn_text.rotate(angle);
    }

    void Push_button::_update_widget() {

        _center_text_on_btn();
    }
/*
------------------------------------------------------------------------------
Set Functions
------------------------------------------------------------------------------
*/
    void Push_button::set_size(
        sf::Vector2f const size
        ) {

        _btn_rect.setSize(size);
        _center_text_on_btn();
    }

    void Push_button::set_size(
        float const x,
        float const y
        ) {

        _btn_rect.setSize({x, y});
        _center_text_on_btn();
    }

    void Push_button::set_char_size(
        std::uint32_t const char_size
        ) {

        _btn_text.setCharacterSize(char_size);
        _center_text_on_btn();
    }

    void Push_button::set_scale(
        sf::Vector2f const scale
        ) {

        _btn_rect.setScale(scale);
        _btn_text.setScale(scale);
        _center_text_on_btn();
    }

    void Push_button::set_scale(
        float const x,
        float const y
        ) {

        _btn_rect.setScale({x, y});
        _btn_text.setScale({x, y});
        _center_text_on_btn();
    }

    void Push_button::set_pos(
        sf::Vector2f const pos
        ) {

        _btn_rect.setPosition(pos);
        _center_text_on_btn();
    }

    void Push_button::set_pos(
        float const x,
        float const y
        ) {

        _btn_rect.setPosition({x, y});
        _center_text_on_btn();
    }

    void Push_button::set_origin(
        sf::Vector2f const origin
        ) {

        _btn_rect.setOrigin(origin);
        _btn_text.setOrigin(origin);
    }

    void Push_button::set_origin(
        float const x,
        float const y
        ) {

        _btn_rect.setOrigin({x, y});
        _btn_text.setOrigin({x, y});
    }

    void Push_button::set_rotation(
        sf::Angle const angle
        ) {

        _btn_rect.setRotation(angle);
        _btn_text.setRotation(angle);
    }

    void Push_button::set_color(
        sf::Color const color
        ) {

        _btn_rect.setFillColor(color);
    }

    void Push_button::set_text_color(
        sf::Color const color
        ) {

        _btn_text.setFillColor(color);
    }

    void Push_button::set_text_string(
        sf::String const string
        ) {

        _btn_text.setString(string);
        _center_text_on_btn();
    }

    void Push_button::set_text_style(
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

            _btn_text.setStyle(style);
            _center_text_on_btn();
        } else {

            LOG(WARNING)                            <<
            "Style for widget text is not set to [" <<
            style                                   <<
            "] as this is not a valid sf text style.";
        }
    }

    void Push_button::set_border_thickness(
        float const thickness
        ) {

        if (thickness < 0.0f) {

            _btn_rect.setOutlineThickness(0.0f);

            LOG(WARNING)                                  <<
            "Border thickness for widget is not set to [" <<
            thickness                                     <<
            "] as only positive values are allowed.";
        } else {

            _btn_rect.setOutlineThickness(thickness);
        }
    }

    void Push_button::set_border_color(
        sf::Color const color
        ) {

        _btn_rect.setOutlineColor(color);
    }

    void Push_button::set_text_border_thickness(
        float const thickness
        ) {

        _btn_text.setOutlineThickness(thickness);
    }

    void Push_button::set_text_border_color(
        sf::Color const color
        ) {

        _btn_text.setOutlineColor(color);
    }
/*
------------------------------------------------------------------------------
Get Functions
------------------------------------------------------------------------------
*/
    sf::Vector2f Push_button::get_size() const {

        return _btn_rect.getSize();
    }

    float Push_button::get_size_x() const {

        return _btn_rect.getSize().x;
    }

    float Push_button::get_size_y() const {

        return _btn_rect.getSize().y;
    }

    std::uint32_t Push_button::get_char_size() const {

        return _btn_text.getCharacterSize();
    }

    sf::Vector2f Push_button::get_scale() const {

        return _btn_rect.getScale();
    }

    float Push_button::get_scale_x() const {

        return _btn_rect.getScale().x;
    }

    float Push_button::get_scale_y() const {

        return _btn_rect.getScale().y;
    }

    sf::Vector2f Push_button::get_pos() const {

        return _btn_rect.getPosition();
    }

    float Push_button::get_pos_x() const {

        return _btn_rect.getPosition().x;
    }

    float Push_button::get_pos_y() const {

        return _btn_rect.getPosition().y;
    }

    sf::Vector2f Push_button::get_origin() const {

        return _btn_rect.getOrigin();
    }

    float Push_button::get_origin_x() const {

        return _btn_rect.getOrigin().x;
    }

    float Push_button::get_origin_y() const {

        return _btn_rect.getOrigin().y;
    }

    sf::Angle Push_button::get_rotation() const {

        return _btn_rect.getRotation();
    }

    sf::Color Push_button::get_color() const {

        return _btn_rect.getFillColor();
    }

    sf::Color Push_button::get_text_color() const {

        return _btn_text.getFillColor();
    }

    sf::String Push_button::get_text_string() const {

        return _btn_text.getString();
    }

    std::uint32_t Push_button::get_text_style() const {

        return _btn_text.getStyle();
    }

    float Push_button::get_border_thickness() const {

        return _btn_rect.getOutlineThickness();
    }

    sf::Color Push_button::get_border_color() const {

        return _btn_rect.getOutlineColor();
    }

    float Push_button::get_text_border_thickness() const {

        return _btn_text.getOutlineThickness();
    }

    sf::Color Push_button::get_text_border_color() const {

        return _btn_text.getOutlineColor();
    }
/*
------------------------------------------------------------------------------
Signals / slots
------------------------------------------------------------------------------
*/
    void Push_button::_handle_hover(
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

    void Push_button::_handle_mouse_button_pressed_events(
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
    void Push_button::_center_text_on_btn() {

        _fit_text_to_btn();

        sf::FloatRect const btn_bounds  = _btn_rect.getGlobalBounds ();
        sf::FloatRect const text_bounds = _btn_text.getGlobalBounds ();

        // Center the text on the button.
        sf::Vector2f const btn_center  = btn_bounds.getCenter();
        sf::Vector2f const text_center = text_bounds.getCenter();

        float const offset_x = btn_center.x - text_center.x;
        float const offset_y = btn_center.y - text_center.y;

        _btn_text.move({offset_x, offset_y});
    }

    void Push_button::_fit_text_to_btn() {

        // Variables relating to the widget.
        sf::FloatRect btn_bounds  = _btn_rect.getGlobalBounds ();
        sf::FloatRect text_bounds = _btn_text.getGlobalBounds ();
        std::uint32_t char_size   = _btn_text.getCharacterSize();

        // Flags for if the texts bounding rectangle is greater than
        // the buttons bounding rectangle.
        bool is_out_of_bounds_x = text_bounds.size.x > btn_bounds.size.x;
        bool is_out_of_bounds_y = text_bounds.size.y > btn_bounds.size.y;
        bool is_out_of_bounds   = is_out_of_bounds_x || is_out_of_bounds_y;

        // Flag for if the current text character size is still a valid size.
        bool is_valid_char_size = char_size >= 1u;

        // While the text bounds is greater than the buttons bounding rectangle
        // and the texts character size is still valid (we can decrease it).
        while (is_out_of_bounds && is_valid_char_size) {

            // Decrease the text character size.
            _btn_text.setCharacterSize(char_size - 1u);

            // Update variables.
            btn_bounds  = _btn_rect.getGlobalBounds ();
            text_bounds = _btn_text.getGlobalBounds ();
            char_size   = _btn_text.getCharacterSize();

            // Update flags.
            is_out_of_bounds_x = text_bounds.size.x > btn_bounds.size.x;
            is_out_of_bounds_y = text_bounds.size.y > btn_bounds.size.y;
            is_out_of_bounds   = is_out_of_bounds_x || is_out_of_bounds_y;
            is_valid_char_size = char_size >= 1u;
        }
    }

    bool Push_button::_is_hovering() const {

        bool is_hovering = false;

        sf::Vector2i  const mouse_pos_pixels = sf::Mouse::getPosition         (_parent_window  );
        sf::Vector2f  const mouse_pos_coords = _parent_window.mapPixelToCoords(mouse_pos_pixels);
        sf::FloatRect const btn_bounds       = _btn_rect.getGlobalBounds      (/*------------*/);

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
