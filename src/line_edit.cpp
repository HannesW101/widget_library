/*
------------------------------------------------------------------------------
Includes
------------------------------------------------------------------------------
*/
#include "widgets/log.h"
#include "widgets/resources.h"
#include "widgets/line_edit.h"
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
    Line_edit::Line_edit(
        std::shared_ptr<sf::RenderWindow> parent_window,
        sf::String const&  placeholder_string
        ) :
        Widget              (std::move(parent_window)),
        Signals_slots       (/*--------------------*/),
        _le_placeholder_text(DEFAULT_WIDGET_FONT     ),
        _le_typing_text     (DEFAULT_WIDGET_FONT     ),
        _le_rect            (DEFAULT_WIDGET_SIZE     ),
        _max_chars          (18u                     ),
        _typed_char         (""                      )
    {

        _le_placeholder_text.setPosition (DEFAULT_WIDGET_POS         );
        _le_placeholder_text.setString   (placeholder_string         );
        _le_placeholder_text.setStyle    (sf::Text::Italic           );
        _le_placeholder_text.setFillColor(sf::Color(0u, 0u, 0u, 127u));

        _le_rect.setPosition (DEFAULT_WIDGET_POS  );
        _le_rect.setFillColor(DEFAULT_WIDGET_COLOR);
    }
/*
------------------------------------------------------------------------------
Functionality
------------------------------------------------------------------------------
*/
    void Line_edit::draw() {

        if (_current_state == STATE__HIDDEN) {

            // Dont draw since widget is hidden.
        } else {

            // Can call _update_widget() for final updating
            // of the widget before drawing to the window.
            _update_widget();

            if (_le_typing_text.getString().isEmpty() && !(_current_state == STATE__TYPING)) {

                _resize_rect(_le_placeholder_text);

                if (!_is_parent_window_nullptr()) {

                    _parent_window->draw(_le_rect);
                    _parent_window->draw(_le_placeholder_text);
                }
            } else {

                _resize_rect(_le_typing_text);

                if (!_is_parent_window_nullptr()) {

                    _parent_window->draw(_le_rect);
                    _parent_window->draw(_le_typing_text);
                }
            }
        }
    }

    void Line_edit::move(
        sf::Vector2f const offset
        ) {

        _le_typing_text.move     (offset);
        _le_placeholder_text.move(offset);
        _le_rect.move            (offset);
    }

    void Line_edit::move(
        float const x,
        float const y
        ) {

        _le_typing_text.move     ({x, y});
        _le_placeholder_text.move({x, y});
        _le_rect.move            ({x, y});
    }

    void Line_edit::rotate(
        sf::Angle const angle
        ) {

        _le_typing_text.rotate     (angle);
        _le_placeholder_text.rotate(angle);
        _le_rect.rotate            (angle);
    }

    void Line_edit::_update_widget() {

    }

    void Line_edit::append_typed_char() {

        sf::String const typing_text = _le_typing_text.getString();
        size_t     const num_chars   = typing_text.getSize();

        bool const is_typing         = _current_state == STATE__TYPING;
        bool const can_append_char   = num_chars < _max_chars;
        bool const is_printable_char = *_typed_char.getData() >= 32u && *_typed_char.getData() < 127u;

        if (is_typing && can_append_char && is_printable_char) {

            _le_typing_text.setString(typing_text + _typed_char);
        }
    }

    void Line_edit::delete_char() {

        sf::String const typing_text = _le_typing_text.getString();
        size_t     const num_chars   = typing_text.getSize();

        if (_current_state == STATE__TYPING && num_chars > 0u) {

            sf::String const new_typing_text = typing_text.substring(0u, typing_text.getSize() - 1u);
            _le_typing_text.setString(new_typing_text);
        }
    }
/*
------------------------------------------------------------------------------
Set Functions
------------------------------------------------------------------------------
*/
    void Line_edit::set_max_chars(
        std::uint32_t const max_chars
        ) {

        _max_chars = max_chars;
    }

    void Line_edit::set_char_size(
        std::uint32_t const char_size
        ) {

        _le_typing_text.setCharacterSize     (char_size);
        _le_placeholder_text.setCharacterSize(char_size);
    }

    void Line_edit::set_pos(
        sf::Vector2f const pos
        ) {

        _le_typing_text.setPosition     (pos);
        _le_placeholder_text.setPosition(pos);
        _le_rect.setPosition            (pos);
    }

    void Line_edit::set_pos(
        float const x,
        float const y
        ) {

        _le_typing_text.setPosition     ({x, y});
        _le_placeholder_text.setPosition({x, y});
        _le_rect.setPosition            ({x, y});
    }

    void Line_edit::set_origin(
        sf::Vector2f const origin
        ) {

        _le_typing_text.setOrigin     (origin);
        _le_placeholder_text.setOrigin(origin);
        _le_rect.setOrigin            (origin);
    }

    void Line_edit::set_origin(
        float const x,
        float const y
        ) {

        _le_typing_text.setOrigin     ({x, y});
        _le_placeholder_text.setOrigin({x, y});
        _le_rect.setOrigin            ({x, y});
    }

    void Line_edit::set_rotation(
        sf::Angle const angle
        ) {

        _le_typing_text.setRotation     (angle);
        _le_placeholder_text.setRotation(angle);
        _le_rect.setRotation            (angle);
    }

    void Line_edit::set_typing_text_color(
        sf::Color const color
        ) {

        _le_typing_text.setFillColor(color);
    }

    void Line_edit::set_placeholder_text_color(
        sf::Color const color
        ) {

        _le_placeholder_text.setFillColor(color);
    }

    void Line_edit::set_typing_text_style(
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

            _le_typing_text.setStyle(style);
        } else {

            LOG(WARNING)                            <<
            "Style for widget text is not set to [" <<
            style                                   <<
            "] as this is not a valid sf text style.";
        }
    }

    void Line_edit::set_placeholder_text_style(
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

            _le_placeholder_text.setStyle(style);
        } else {

            LOG(WARNING)                            <<
            "Style for widget text is not set to [" <<
            style                                   <<
            "] as this is not a valid sf text style.";
        }
    }

    void Line_edit::set_border_thickness(
        float const thickness
        ) {

        if (thickness < 0.0f) {

            _le_rect.setOutlineThickness(0.0f);

            LOG(WARNING)                                  <<
            "Border thickness for widget is not set to [" <<
            thickness                                     <<
            "] as only positive values are allowed.";
        } else {

            _le_rect.setOutlineThickness(thickness);
        }
    }

    void Line_edit::set_border_color(
        sf::Color const color
        ) {

        _le_rect.setOutlineColor(color);
    }
/*
------------------------------------------------------------------------------
Get Functions
------------------------------------------------------------------------------
*/
    std::uint32_t Line_edit::get_char_size() const {

        return _le_typing_text.getCharacterSize();
    }

    sf::Vector2f Line_edit::get_pos() const {

        return _le_rect.getPosition();
    }

    float Line_edit::get_pos_x() const {

        return _le_rect.getPosition().x;
    }

    float Line_edit::get_pos_y() const {

        return _le_rect.getPosition().y;
    }

    sf::Vector2f Line_edit::get_origin() const {

        return _le_rect.getOrigin();
    }

    float Line_edit::get_origin_x() const {

        return _le_rect.getOrigin().x;
    }

    float Line_edit::get_origin_y() const {

        return _le_rect.getOrigin().y;
    }

    sf::Angle Line_edit::get_rotation() const {

        return _le_rect.getRotation();
    }

    sf::String Line_edit::get_typing_text_string() const {

        return _le_typing_text.getString();
    }

    sf::Color Line_edit::get_typing_text_color() const {

        return _le_typing_text.getFillColor();
    }

    sf::Color Line_edit::get_placeholder_text_color() const {

        return _le_placeholder_text.getFillColor();
    }

    std::uint32_t Line_edit::get_typing_text_style() const {

        return _le_typing_text.getStyle();
    }

    std::uint32_t Line_edit::get_placeholder_text_style() const {

        return _le_placeholder_text.getStyle();
    }

    float Line_edit::get_border_thickness() const {

        return _le_rect.getOutlineThickness();
    }

    sf::Color Line_edit::get_border_color() const {

        return _le_rect.getOutlineColor();
    }
/*
------------------------------------------------------------------------------
Signals / slots
------------------------------------------------------------------------------
*/
    void Line_edit::_handle_hover(
        sf::Event const& event
        ) {

        static_cast<void>(event);

        // If we are typing, then dont change state depending on hovering.
        if (_current_state == STATE__TYPING) {

            return;
        }

        // Check if we are hovering and not in a hovering state.
        if (_is_hovering() && _current_state != STATE__HOVERING) {

            change_state (STATE__HOVERING);
            _emit_signal (SIGNAL__HOVER  );
        }

        // Check if we are not hovering and in a hovering state.
        if (!_is_hovering() && _current_state == STATE__HOVERING) {

            change_state (STATE__DEFAULT    );
            _emit_signal (SIGNAL__STOP_HOVER);
        }
    }

    void Line_edit::_handle_text_entered_events(
        sf::Event const& event
        ) {

        if (_current_state == STATE__TYPING) {

            if (auto typed_char = event.getIf<sf::Event::TextEntered>()) {

                _typed_char = typed_char->unicode;
                _emit_signal(SIGNAL__WINDOW_TEXT_ENTERED);
            }
        }
    }

    void Line_edit::_handle_mouse_button_pressed_events(
        sf::Event const& event
        ) {

        if (auto btn_press = event.getIf<sf::Event::MouseButtonPressed>()) {

            if (btn_press->button == sf::Mouse::Button::Left) {

                if (_is_hovering()) {

                    change_state(STATE__TYPING);
                } else {

                    change_state(STATE__DEFAULT);
                }

                _emit_signal(SIGNAL__MOUSE_BUTTON_LEFT_PRESS);
                return;
            }
        }

        Signals_slots::_handle_mouse_button_pressed_events(event);
    }
/*
------------------------------------------------------------------------------
Helper Functions
------------------------------------------------------------------------------
*/
    bool Line_edit::_is_hovering() const {

        bool is_hovering = false;

        sf::Vector2i  const mouse_pos_pixels = sf::Mouse::getPosition          (*_parent_window );
        sf::Vector2f  const mouse_pos_coords = _parent_window->mapPixelToCoords(mouse_pos_pixels);
        sf::FloatRect const lbl_bounds       = _le_rect.getGlobalBounds        (/*------------*/);

        if (lbl_bounds.contains(mouse_pos_coords)) {

            is_hovering = true;
        } else {

            is_hovering = false;
        }

        return is_hovering;
    }

    void Line_edit::_resize_rect(
        sf::Text const& curr_text
        ) {

        // Measurement
        sf::Text measure(curr_text.getFont());
        measure.setCharacterSize(curr_text.getCharacterSize());
        sf::String wide = "";

        for (std::uint32_t i = 0; i < _max_chars; ++i) {

            wide += 'W';
        }

        measure.setString(wide);

        // Get useful variables that influence sizing
        sf::FloatRect const lb      = measure.getLocalBounds();
        float         const cs      = static_cast<float>(measure.getCharacterSize());

        // Padding
        float const pad_x  = std::max(4.0f, cs *  0.6f);
        float const pad_y  = std::max(3.0f, cs * 0.45f);
        float       rect_x = lb.size.x + pad_x * 2.f;
        float       rect_y = lb.size.y + pad_y * 2.f;

        rect_x = std::max(rect_x, 40.f     );
        rect_y = std::max(rect_y,  8.f + cs);

        _le_rect.setSize({rect_x, rect_y});

        // position text inside rect accounting for lb and padding
        sf::Vector2f const rp     = _le_rect.getPosition();
        float        const text_x = rp.x + pad_x - lb.position.x;
        float        const text_y = rp.y + pad_y - lb.position.y;

        if (curr_text.getString() == _le_typing_text.getString()) {

            _le_typing_text.setPosition({text_x, text_y});
        } else {

            _le_placeholder_text.setPosition({text_x, text_y});
        }
    }
}
/*
------------------------------------------------------------------------------
Namespace widgets END
------------------------------------------------------------------------------
*/
