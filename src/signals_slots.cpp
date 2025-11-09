/*
------------------------------------------------------------------------------
Includes
------------------------------------------------------------------------------
*/
#include "widgets/log.h"
#include "widgets/signals_slots.h"

#include <string>
/*
------------------------------------------------------------------------------
Namespace signals_slots BEGIN
------------------------------------------------------------------------------
*/
namespace signals_slots {
/*
------------------------------------------------------------------------------
Global functions
------------------------------------------------------------------------------
*/
    std::string signal_to_str(
        Signal const signal
        ) {

        std::string str = "UNDEFINED";

        switch (signal) {

        case SIGNAL__WINDOW_CLOSED:                str = "SIGNAL__WINDOW_CLOSED";                break;
        case SIGNAL__WINDOW_RESIZED:               str = "SIGNAL__WINDOW_RESIZED";               break;
        case SIGNAL__WINDOW_LOST_FOCUS:            str = "SIGNAL__WINDOW_LOST_FOCUS";            break;
        case SIGNAL__WINDOW_GAINED_FOCUS:          str = "SIGNAL__WINDOW_GAINED_FOCUS";          break;
        case SIGNAL__WINDOW_TEXT_ENTERED:          str = "SIGNAL__WINDOW_TEXT_ENTERED";          break;
        case SIGNAL__MOUSE_MOVED:                  str = "SIGNAL__MOUSE_MOVED";                  break;
        case SIGNAL__MOUSE_BUTTON_LEFT_PRESS:      str = "SIGNAL__MOUSE_BUTTON_LEFT_PRESS";      break;
        case SIGNAL__MOUSE_BUTTON_RIGHT_PRESS:     str = "SIGNAL__MOUSE_BUTTON_RIGHT_PRESS";     break;
        case SIGNAL__MOUSE_BUTTON_MIDDLE_PRESS:    str = "SIGNAL__MOUSE_BUTTON_MIDDLE_PRESS";    break;
        case SIGNAL__MOUSE_BUTTON_LEFT_RELEASE:    str = "SIGNAL__MOUSE_BUTTON_LEFT_RELEASE";    break;
        case SIGNAL__MOUSE_BUTTON_RIGHT_RELEASE:   str = "SIGNAL__MOUSE_BUTTON_RIGHT_RELEASE";   break;
        case SIGNAL__MOUSE_BUTTON_MIDDLE_RELEASE:  str = "SIGNAL__MOUSE_BUTTON_MIDDLE_RELEASE";  break;
        case SIGNAL__MOUSE_WHEEL_UP:               str = "SIGNAL__MOUSE_WHEEL_UP";               break;
        case SIGNAL__MOUSE_WHEEL_DOWN:             str = "SIGNAL__MOUSE_WHEEL_DOWN";             break;
        case SIGNAL__MOUSE_ENTER_WINDOW:           str = "SIGNAL__MOUSE_ENTER_WINDOW";           break;
        case SIGNAL__MOUSE_LEAVE_WINDOW:           str = "SIGNAL__MOUSE_LEAVE_WINDOW";           break;
        case SIGNAL__JOYSTICK_BUTTON_PRESSED:      str = "SIGNAL__JOYSTICK_BUTTON_PRESSED";      break;
        case SIGNAL__JOYSTICK_BUTTON_RELEASED:     str = "SIGNAL__JOYSTICK_BUTTON_RELEASED";     break;
        case SIGNAL__JOYSTICK_MOVED:               str = "SIGNAL__JOYSTICK_MOVED";               break;
        case SIGNAL__JOYSTICK_CONNECTED:           str = "SIGNAL__JOYSTICK_CONNECTED";           break;
        case SIGNAL__JOYSTICK_DISCONNECTED:        str = "SIGNAL__JOYSTICK_DISCONNECTED";        break;
        case SIGNAL__TOUCH_BEGAN:                  str = "SIGNAL__TOUCH_BEGAN";                  break;
        case SIGNAL__TOUCH_MOVED:                  str = "SIGNAL__TOUCH_MOVED";                  break;
        case SIGNAL__TOUCH_ENDED:                  str = "SIGNAL__TOUCH_ENDED";                  break;
        case SIGNAL__SENSOR_CHANGED:               str = "SIGNAL__SENSOR_CHANGED";               break;
        case SIGNAL__KEYPRESS_A:                   str = "SIGNAL__KEYPRESS_A";                   break;
        case SIGNAL__KEYPRESS_B:                   str = "SIGNAL__KEYPRESS_B";                   break;
        case SIGNAL__KEYPRESS_C:                   str = "SIGNAL__KEYPRESS_C";                   break;
        case SIGNAL__KEYPRESS_D:                   str = "SIGNAL__KEYPRESS_D";                   break;
        case SIGNAL__KEYPRESS_E:                   str = "SIGNAL__KEYPRESS_E";                   break;
        case SIGNAL__KEYPRESS_F:                   str = "SIGNAL__KEYPRESS_F";                   break;
        case SIGNAL__KEYPRESS_G:                   str = "SIGNAL__KEYPRESS_G";                   break;
        case SIGNAL__KEYPRESS_H:                   str = "SIGNAL__KEYPRESS_H";                   break;
        case SIGNAL__KEYPRESS_I:                   str = "SIGNAL__KEYPRESS_I";                   break;
        case SIGNAL__KEYPRESS_J:                   str = "SIGNAL__KEYPRESS_J";                   break;
        case SIGNAL__KEYPRESS_K:                   str = "SIGNAL__KEYPRESS_K";                   break;
        case SIGNAL__KEYPRESS_L:                   str = "SIGNAL__KEYPRESS_L";                   break;
        case SIGNAL__KEYPRESS_M:                   str = "SIGNAL__KEYPRESS_M";                   break;
        case SIGNAL__KEYPRESS_N:                   str = "SIGNAL__KEYPRESS_N";                   break;
        case SIGNAL__KEYPRESS_O:                   str = "SIGNAL__KEYPRESS_O";                   break;
        case SIGNAL__KEYPRESS_P:                   str = "SIGNAL__KEYPRESS_P";                   break;
        case SIGNAL__KEYPRESS_Q:                   str = "SIGNAL__KEYPRESS_Q";                   break;
        case SIGNAL__KEYPRESS_R:                   str = "SIGNAL__KEYPRESS_R";                   break;
        case SIGNAL__KEYPRESS_S:                   str = "SIGNAL__KEYPRESS_S";                   break;
        case SIGNAL__KEYPRESS_T:                   str = "SIGNAL__KEYPRESS_T";                   break;
        case SIGNAL__KEYPRESS_U:                   str = "SIGNAL__KEYPRESS_U";                   break;
        case SIGNAL__KEYPRESS_V:                   str = "SIGNAL__KEYPRESS_V";                   break;
        case SIGNAL__KEYPRESS_W:                   str = "SIGNAL__KEYPRESS_W";                   break;
        case SIGNAL__KEYPRESS_X:                   str = "SIGNAL__KEYPRESS_X";                   break;
        case SIGNAL__KEYPRESS_Y:                   str = "SIGNAL__KEYPRESS_Y";                   break;
        case SIGNAL__KEYPRESS_Z:                   str = "SIGNAL__KEYPRESS_Z";                   break;
        case SIGNAL__KEYPRESS_NUM0:                str = "SIGNAL__KEYPRESS_NUM0";                break;
        case SIGNAL__KEYPRESS_NUM1:                str = "SIGNAL__KEYPRESS_NUM1";                break;
        case SIGNAL__KEYPRESS_NUM2:                str = "SIGNAL__KEYPRESS_NUM2";                break;
        case SIGNAL__KEYPRESS_NUM3:                str = "SIGNAL__KEYPRESS_NUM3";                break;
        case SIGNAL__KEYPRESS_NUM4:                str = "SIGNAL__KEYPRESS_NUM4";                break;
        case SIGNAL__KEYPRESS_NUM5:                str = "SIGNAL__KEYPRESS_NUM5";                break;
        case SIGNAL__KEYPRESS_NUM6:                str = "SIGNAL__KEYPRESS_NUM6";                break;
        case SIGNAL__KEYPRESS_NUM7:                str = "SIGNAL__KEYPRESS_NUM7";                break;
        case SIGNAL__KEYPRESS_NUM8:                str = "SIGNAL__KEYPRESS_NUM8";                break;
        case SIGNAL__KEYPRESS_NUM9:                str = "SIGNAL__KEYPRESS_NUM9";                break;
        case SIGNAL__KEYPRESS_ESCAPE:              str = "SIGNAL__KEYPRESS_ESCAPE";              break;
        case SIGNAL__KEYPRESS_LCONTROL:            str = "SIGNAL__KEYPRESS_LCONTROL";            break;
        case SIGNAL__KEYPRESS_LSHIFT:              str = "SIGNAL__KEYPRESS_LSHIFT";              break;
        case SIGNAL__KEYPRESS_LALT:                str = "SIGNAL__KEYPRESS_LALT";                break;
        case SIGNAL__KEYPRESS_LSYSTEM:             str = "SIGNAL__KEYPRESS_LSYSTEM";             break;
        case SIGNAL__KEYPRESS_RCONTROL:            str = "SIGNAL__KEYPRESS_RCONTROL";            break;
        case SIGNAL__KEYPRESS_RSHIFT:              str = "SIGNAL__KEYPRESS_RSHIFT";              break;
        case SIGNAL__KEYPRESS_RALT:                str = "SIGNAL__KEYPRESS_RALT";                break;
        case SIGNAL__KEYPRESS_RSYSTEM:             str = "SIGNAL__KEYPRESS_RSYSTEM";             break;
        case SIGNAL__KEYPRESS_MENU:                str = "SIGNAL__KEYPRESS_MENU";                break;
        case SIGNAL__KEYPRESS_LBRACKET:            str = "SIGNAL__KEYPRESS_LBRACKET";            break;
        case SIGNAL__KEYPRESS_RBRACKET:            str = "SIGNAL__KEYPRESS_RBRACKET";            break;
        case SIGNAL__KEYPRESS_SEMICOLON:           str = "SIGNAL__KEYPRESS_SEMICOLON";           break;
        case SIGNAL__KEYPRESS_COMMA:               str = "SIGNAL__KEYPRESS_COMMA";               break;
        case SIGNAL__KEYPRESS_PERIOD:              str = "SIGNAL__KEYPRESS_PERIOD";              break;
        case SIGNAL__KEYPRESS_QUOTE:               str = "SIGNAL__KEYPRESS_QUOTE";               break;
        case SIGNAL__KEYPRESS_SLASH:               str = "SIGNAL__KEYPRESS_SLASH";               break;
        case SIGNAL__KEYPRESS_BACKSLASH:           str = "SIGNAL__KEYPRESS_BACKSLASH";           break;
        case SIGNAL__KEYPRESS_TILDE:               str = "SIGNAL__KEYPRESS_TILDE";               break;
        case SIGNAL__KEYPRESS_EQUAL:               str = "SIGNAL__KEYPRESS_EQUAL";               break;
        case SIGNAL__KEYPRESS_DASH:                str = "SIGNAL__KEYPRESS_DASH";                break;
        case SIGNAL__KEYPRESS_SPACE:               str = "SIGNAL__KEYPRESS_SPACE";               break;
        case SIGNAL__KEYPRESS_RETURN:              str = "SIGNAL__KEYPRESS_RETURN";              break;
        case SIGNAL__KEYPRESS_BACKSPACE:           str = "SIGNAL__KEYPRESS_BACKSPACE";           break;
        case SIGNAL__KEYPRESS_TAB:                 str = "SIGNAL__KEYPRESS_TAB";                 break;
        case SIGNAL__KEYPRESS_PAGEUP:              str = "SIGNAL__KEYPRESS_PAGEUP";              break;
        case SIGNAL__KEYPRESS_PAGEDOWN:            str = "SIGNAL__KEYPRESS_PAGEDOWN";            break;
        case SIGNAL__KEYPRESS_END:                 str = "SIGNAL__KEYPRESS_END";                 break;
        case SIGNAL__KEYPRESS_HOME:                str = "SIGNAL__KEYPRESS_HOME";                break;
        case SIGNAL__KEYPRESS_INSERT:              str = "SIGNAL__KEYPRESS_INSERT";              break;
        case SIGNAL__KEYPRESS_DELETE:              str = "SIGNAL__KEYPRESS_DELETE";              break;
        case SIGNAL__KEYPRESS_ADD:                 str = "SIGNAL__KEYPRESS_ADD";                 break;
        case SIGNAL__KEYPRESS_SUBTRACT:            str = "SIGNAL__KEYPRESS_SUBTRACT";            break;
        case SIGNAL__KEYPRESS_MULTIPLY:            str = "SIGNAL__KEYPRESS_MULTIPLY";            break;
        case SIGNAL__KEYPRESS_DIVIDE:              str = "SIGNAL__KEYPRESS_DIVIDE";              break;
        case SIGNAL__KEYPRESS_LEFT:                str = "SIGNAL__KEYPRESS_LEFT";                break;
        case SIGNAL__KEYPRESS_RIGHT:               str = "SIGNAL__KEYPRESS_RIGHT";               break;
        case SIGNAL__KEYPRESS_UP:                  str = "SIGNAL__KEYPRESS_UP";                  break;
        case SIGNAL__KEYPRESS_DOWN:                str = "SIGNAL__KEYPRESS_DOWN";                break;
        case SIGNAL__KEYPRESS_NUMPAD0:             str = "SIGNAL__KEYPRESS_NUMPAD0";             break;
        case SIGNAL__KEYPRESS_NUMPAD1:             str = "SIGNAL__KEYPRESS_NUMPAD1";             break;
        case SIGNAL__KEYPRESS_NUMPAD2:             str = "SIGNAL__KEYPRESS_NUMPAD2";             break;
        case SIGNAL__KEYPRESS_NUMPAD3:             str = "SIGNAL__KEYPRESS_NUMPAD3";             break;
        case SIGNAL__KEYPRESS_NUMPAD4:             str = "SIGNAL__KEYPRESS_NUMPAD4";             break;
        case SIGNAL__KEYPRESS_NUMPAD5:             str = "SIGNAL__KEYPRESS_NUMPAD5";             break;
        case SIGNAL__KEYPRESS_NUMPAD6:             str = "SIGNAL__KEYPRESS_NUMPAD6";             break;
        case SIGNAL__KEYPRESS_NUMPAD7:             str = "SIGNAL__KEYPRESS_NUMPAD7";             break;
        case SIGNAL__KEYPRESS_NUMPAD8:             str = "SIGNAL__KEYPRESS_NUMPAD8";             break;
        case SIGNAL__KEYPRESS_NUMPAD9:             str = "SIGNAL__KEYPRESS_NUMPAD9";             break;
        case SIGNAL__KEYPRESS_F1:                  str = "SIGNAL__KEYPRESS_F1";                  break;
        case SIGNAL__KEYPRESS_F2:                  str = "SIGNAL__KEYPRESS_F2";                  break;
        case SIGNAL__KEYPRESS_F3:                  str = "SIGNAL__KEYPRESS_F3";                  break;
        case SIGNAL__KEYPRESS_F4:                  str = "SIGNAL__KEYPRESS_F4";                  break;
        case SIGNAL__KEYPRESS_F5:                  str = "SIGNAL__KEYPRESS_F5";                  break;
        case SIGNAL__KEYPRESS_F6:                  str = "SIGNAL__KEYPRESS_F6";                  break;
        case SIGNAL__KEYPRESS_F7:                  str = "SIGNAL__KEYPRESS_F7";                  break;
        case SIGNAL__KEYPRESS_F8:                  str = "SIGNAL__KEYPRESS_F8";                  break;
        case SIGNAL__KEYPRESS_F9:                  str = "SIGNAL__KEYPRESS_F9";                  break;
        case SIGNAL__KEYPRESS_F10:                 str = "SIGNAL__KEYPRESS_F10";                 break;
        case SIGNAL__KEYPRESS_F11:                 str = "SIGNAL__KEYPRESS_F11";                 break;
        case SIGNAL__KEYPRESS_F12:                 str = "SIGNAL__KEYPRESS_F12";                 break;
        case SIGNAL__KEYRELEASE_A:                 str = "SIGNAL__KEYRELEASE_A";                 break;
        case SIGNAL__KEYRELEASE_B:                 str = "SIGNAL__KEYRELEASE_B";                 break;
        case SIGNAL__KEYRELEASE_C:                 str = "SIGNAL__KEYRELEASE_C";                 break;
        case SIGNAL__KEYRELEASE_D:                 str = "SIGNAL__KEYRELEASE_D";                 break;
        case SIGNAL__KEYRELEASE_E:                 str = "SIGNAL__KEYRELEASE_E";                 break;
        case SIGNAL__KEYRELEASE_F:                 str = "SIGNAL__KEYRELEASE_F";                 break;
        case SIGNAL__KEYRELEASE_G:                 str = "SIGNAL__KEYRELEASE_G";                 break;
        case SIGNAL__KEYRELEASE_H:                 str = "SIGNAL__KEYRELEASE_H";                 break;
        case SIGNAL__KEYRELEASE_I:                 str = "SIGNAL__KEYRELEASE_I";                 break;
        case SIGNAL__KEYRELEASE_J:                 str = "SIGNAL__KEYRELEASE_J";                 break;
        case SIGNAL__KEYRELEASE_K:                 str = "SIGNAL__KEYRELEASE_K";                 break;
        case SIGNAL__KEYRELEASE_L:                 str = "SIGNAL__KEYRELEASE_L";                 break;
        case SIGNAL__KEYRELEASE_M:                 str = "SIGNAL__KEYRELEASE_M";                 break;
        case SIGNAL__KEYRELEASE_N:                 str = "SIGNAL__KEYRELEASE_N";                 break;
        case SIGNAL__KEYRELEASE_O:                 str = "SIGNAL__KEYRELEASE_O";                 break;
        case SIGNAL__KEYRELEASE_P:                 str = "SIGNAL__KEYRELEASE_P";                 break;
        case SIGNAL__KEYRELEASE_Q:                 str = "SIGNAL__KEYRELEASE_Q";                 break;
        case SIGNAL__KEYRELEASE_R:                 str = "SIGNAL__KEYRELEASE_R";                 break;
        case SIGNAL__KEYRELEASE_S:                 str = "SIGNAL__KEYRELEASE_S";                 break;
        case SIGNAL__KEYRELEASE_T:                 str = "SIGNAL__KEYRELEASE_T";                 break;
        case SIGNAL__KEYRELEASE_U:                 str = "SIGNAL__KEYRELEASE_U";                 break;
        case SIGNAL__KEYRELEASE_V:                 str = "SIGNAL__KEYRELEASE_V";                 break;
        case SIGNAL__KEYRELEASE_W:                 str = "SIGNAL__KEYRELEASE_W";                 break;
        case SIGNAL__KEYRELEASE_X:                 str = "SIGNAL__KEYRELEASE_X";                 break;
        case SIGNAL__KEYRELEASE_Y:                 str = "SIGNAL__KEYRELEASE_Y";                 break;
        case SIGNAL__KEYRELEASE_Z:                 str = "SIGNAL__KEYRELEASE_Z";                 break;
        case SIGNAL__KEYRELEASE_NUM0:              str = "SIGNAL__KEYRELEASE_NUM0";              break;
        case SIGNAL__KEYRELEASE_NUM1:              str = "SIGNAL__KEYRELEASE_NUM1";              break;
        case SIGNAL__KEYRELEASE_NUM2:              str = "SIGNAL__KEYRELEASE_NUM2";              break;
        case SIGNAL__KEYRELEASE_NUM3:              str = "SIGNAL__KEYRELEASE_NUM3";              break;
        case SIGNAL__KEYRELEASE_NUM4:              str = "SIGNAL__KEYRELEASE_NUM4";              break;
        case SIGNAL__KEYRELEASE_NUM5:              str = "SIGNAL__KEYRELEASE_NUM5";              break;
        case SIGNAL__KEYRELEASE_NUM6:              str = "SIGNAL__KEYRELEASE_NUM6";              break;
        case SIGNAL__KEYRELEASE_NUM7:              str = "SIGNAL__KEYRELEASE_NUM7";              break;
        case SIGNAL__KEYRELEASE_NUM8:              str = "SIGNAL__KEYRELEASE_NUM8";              break;
        case SIGNAL__KEYRELEASE_NUM9:              str = "SIGNAL__KEYRELEASE_NUM9";              break;
        case SIGNAL__KEYRELEASE_ESCAPE:            str = "SIGNAL__KEYRELEASE_ESCAPE";            break;
        case SIGNAL__KEYRELEASE_LCONTROL:          str = "SIGNAL__KEYRELEASE_LCONTROL";          break;
        case SIGNAL__KEYRELEASE_LSHIFT:            str = "SIGNAL__KEYRELEASE_LSHIFT";            break;
        case SIGNAL__KEYRELEASE_LALT:              str = "SIGNAL__KEYRELEASE_LALT";              break;
        case SIGNAL__KEYRELEASE_LSYSTEM:           str = "SIGNAL__KEYRELEASE_LSYSTEM";           break;
        case SIGNAL__KEYRELEASE_RCONTROL:          str = "SIGNAL__KEYRELEASE_RCONTROL";          break;
        case SIGNAL__KEYRELEASE_RSHIFT:            str = "SIGNAL__KEYRELEASE_RSHIFT";            break;
        case SIGNAL__KEYRELEASE_RALT:              str = "SIGNAL__KEYRELEASE_RALT";              break;
        case SIGNAL__KEYRELEASE_RSYSTEM:           str = "SIGNAL__KEYRELEASE_RSYSTEM";           break;
        case SIGNAL__KEYRELEASE_MENU:              str = "SIGNAL__KEYRELEASE_MENU";              break;
        case SIGNAL__KEYRELEASE_LBRACKET:          str = "SIGNAL__KEYRELEASE_LBRACKET";          break;
        case SIGNAL__KEYRELEASE_RBRACKET:          str = "SIGNAL__KEYRELEASE_RBRACKET";          break;
        case SIGNAL__KEYRELEASE_SEMICOLON:         str = "SIGNAL__KEYRELEASE_SEMICOLON";         break;
        case SIGNAL__KEYRELEASE_COMMA:             str = "SIGNAL__KEYRELEASE_COMMA";             break;
        case SIGNAL__KEYRELEASE_PERIOD:            str = "SIGNAL__KEYRELEASE_PERIOD";            break;
        case SIGNAL__KEYRELEASE_QUOTE:             str = "SIGNAL__KEYRELEASE_QUOTE";             break;
        case SIGNAL__KEYRELEASE_SLASH:             str = "SIGNAL__KEYRELEASE_SLASH";             break;
        case SIGNAL__KEYRELEASE_BACKSLASH:         str = "SIGNAL__KEYRELEASE_BACKSLASH";         break;
        case SIGNAL__KEYRELEASE_TILDE:             str = "SIGNAL__KEYRELEASE_TILDE";             break;
        case SIGNAL__KEYRELEASE_EQUAL:             str = "SIGNAL__KEYRELEASE_EQUAL";             break;
        case SIGNAL__KEYRELEASE_DASH:              str = "SIGNAL__KEYRELEASE_DASH";              break;
        case SIGNAL__KEYRELEASE_SPACE:             str = "SIGNAL__KEYRELEASE_SPACE";             break;
        case SIGNAL__KEYRELEASE_RETURN:            str = "SIGNAL__KEYRELEASE_RETURN";            break;
        case SIGNAL__KEYRELEASE_BACKSPACE:         str = "SIGNAL__KEYRELEASE_BACKSPACE";         break;
        case SIGNAL__KEYRELEASE_TAB:               str = "SIGNAL__KEYRELEASE_TAB";               break;
        case SIGNAL__KEYRELEASE_PAGEUP:            str = "SIGNAL__KEYRELEASE_PAGEUP";            break;
        case SIGNAL__KEYRELEASE_PAGEDOWN:          str = "SIGNAL__KEYRELEASE_PAGEDOWN";          break;
        case SIGNAL__KEYRELEASE_END:               str = "SIGNAL__KEYRELEASE_END";               break;
        case SIGNAL__KEYRELEASE_HOME:              str = "SIGNAL__KEYRELEASE_HOME";              break;
        case SIGNAL__KEYRELEASE_INSERT:            str = "SIGNAL__KEYRELEASE_INSERT";            break;
        case SIGNAL__KEYRELEASE_DELETE:            str = "SIGNAL__KEYRELEASE_DELETE";            break;
        case SIGNAL__KEYRELEASE_ADD:               str = "SIGNAL__KEYRELEASE_ADD";               break;
        case SIGNAL__KEYRELEASE_SUBTRACT:          str = "SIGNAL__KEYRELEASE_SUBTRACT";          break;
        case SIGNAL__KEYRELEASE_MULTIPLY:          str = "SIGNAL__KEYRELEASE_MULTIPLY";          break;
        case SIGNAL__KEYRELEASE_DIVIDE:            str = "SIGNAL__KEYRELEASE_DIVIDE";            break;
        case SIGNAL__KEYRELEASE_LEFT:              str = "SIGNAL__KEYRELEASE_LEFT";              break;
        case SIGNAL__KEYRELEASE_RIGHT:             str = "SIGNAL__KEYRELEASE_RIGHT";             break;
        case SIGNAL__KEYRELEASE_UP:                str = "SIGNAL__KEYRELEASE_UP";                break;
        case SIGNAL__KEYRELEASE_DOWN:              str = "SIGNAL__KEYRELEASE_DOWN";              break;
        case SIGNAL__KEYRELEASE_NUMPAD0:           str = "SIGNAL__KEYRELEASE_NUMPAD0";           break;
        case SIGNAL__KEYRELEASE_NUMPAD1:           str = "SIGNAL__KEYRELEASE_NUMPAD1";           break;
        case SIGNAL__KEYRELEASE_NUMPAD2:           str = "SIGNAL__KEYRELEASE_NUMPAD2";           break;
        case SIGNAL__KEYRELEASE_NUMPAD3:           str = "SIGNAL__KEYRELEASE_NUMPAD3";           break;
        case SIGNAL__KEYRELEASE_NUMPAD4:           str = "SIGNAL__KEYRELEASE_NUMPAD4";           break;
        case SIGNAL__KEYRELEASE_NUMPAD5:           str = "SIGNAL__KEYRELEASE_NUMPAD5";           break;
        case SIGNAL__KEYRELEASE_NUMPAD6:           str = "SIGNAL__KEYRELEASE_NUMPAD6";           break;
        case SIGNAL__KEYRELEASE_NUMPAD7:           str = "SIGNAL__KEYRELEASE_NUMPAD7";           break;
        case SIGNAL__KEYRELEASE_NUMPAD8:           str = "SIGNAL__KEYRELEASE_NUMPAD8";           break;
        case SIGNAL__KEYRELEASE_NUMPAD9:           str = "SIGNAL__KEYRELEASE_NUMPAD9";           break;
        case SIGNAL__KEYRELEASE_F1:                str = "SIGNAL__KEYRELEASE_F1";                break;
        case SIGNAL__KEYRELEASE_F2:                str = "SIGNAL__KEYRELEASE_F2";                break;
        case SIGNAL__KEYRELEASE_F3:                str = "SIGNAL__KEYRELEASE_F3";                break;
        case SIGNAL__KEYRELEASE_F4:                str = "SIGNAL__KEYRELEASE_F4";                break;
        case SIGNAL__KEYRELEASE_F5:                str = "SIGNAL__KEYRELEASE_F5";                break;
        case SIGNAL__KEYRELEASE_F6:                str = "SIGNAL__KEYRELEASE_F6";                break;
        case SIGNAL__KEYRELEASE_F7:                str = "SIGNAL__KEYRELEASE_F7";                break;
        case SIGNAL__KEYRELEASE_F8:                str = "SIGNAL__KEYRELEASE_F8";                break;
        case SIGNAL__KEYRELEASE_F9:                str = "SIGNAL__KEYRELEASE_F9";                break;
        case SIGNAL__KEYRELEASE_F10:               str = "SIGNAL__KEYRELEASE_F10";               break;
        case SIGNAL__KEYRELEASE_F11:               str = "SIGNAL__KEYRELEASE_F11";               break;
        case SIGNAL__KEYRELEASE_F12:               str = "SIGNAL__KEYRELEASE_F12";               break;
        case SIGNAL__MOUSE_BUTTON_EXTRA_1_PRESS:   str = "SIGNAL__MOUSE_BUTTON_EXTRA_1_PRESS";   break;
        case SIGNAL__MOUSE_BUTTON_EXTRA_2_PRESS:   str = "SIGNAL__MOUSE_BUTTON_EXTRA_2_PRESS";   break;
        case SIGNAL__MOUSE_BUTTON_EXTRA_1_RELEASE: str = "SIGNAL__MOUSE_BUTTON_EXTRA_1_RELEASE"; break;
        case SIGNAL__MOUSE_BUTTON_EXTRA_2_RELEASE: str = "SIGNAL__MOUSE_BUTTON_EXTRA_2_RELEASE"; break;
        case SIGNAL__KEYPRESS_F13:                 str = "SIGNAL__KEYPRESS_F13";                 break;
        case SIGNAL__KEYPRESS_F14:                 str = "SIGNAL__KEYPRESS_F14";                 break;
        case SIGNAL__KEYPRESS_F15:                 str = "SIGNAL__KEYPRESS_F15";                 break;
        case SIGNAL__KEYPRESS_PAUSE:               str = "SIGNAL__KEYPRESS_PAUSE";               break;
        case SIGNAL__KEYRELEASE_F13:               str = "SIGNAL__KEYRELEASE_F13";               break;
        case SIGNAL__KEYRELEASE_F14:               str = "SIGNAL__KEYRELEASE_F14";               break;
        case SIGNAL__KEYRELEASE_F15:               str = "SIGNAL__KEYRELEASE_F15";               break;
        case SIGNAL__KEYRELEASE_PAUSE:             str = "SIGNAL__KEYRELEASE_PAUSE";             break;
        case SIGNAL__HOVER:                        str = "SIGNAL__HOVER";                        break;
        }

        return str;
    }
/*
------------------------------------------------------------------------------
Construction / Destruction
------------------------------------------------------------------------------
*/
    Signals_slots::Signals_slots() :
        _signal_slot_map()
    {}
/*
------------------------------------------------------------------------------
Functionality
------------------------------------------------------------------------------
*/
    void Signals_slots::connect(
        Signal                const  signal,
        std::function<void()> const& slot
        ) {

        _signal_slot_map[signal].push_back(slot);

        LOG(TRACE)            <<
        "Connecting signal [" <<
        signal_to_str(signal) <<
        "] to a slot.";
    }

    void Signals_slots::disconnect(
        Signal const signal
        ) {

        bool const is_connected = _signal_slot_map.find(signal) != _signal_slot_map.end();

        if (is_connected) {

            _signal_slot_map.erase(signal);

            LOG(TRACE)               <<
            "Disconnecting signal [" <<
            signal_to_str(signal)    <<
            "].";
        } else {

            // Signal is not currently connected so dont call anything.
            LOG(WARNING)                        <<
            "Attempting to disconnect signal [" <<
            signal_to_str(signal)               <<
            "] but this signal is not currently connected.";
        }
    }

    void Signals_slots::disconnect_all_signals() {

        _signal_slot_map.clear();

        LOG(TRACE) << "Disconnecting all signals.";
    }

    void Signals_slots::_emit_signal(
        Signal const signal
        ) const {

        auto const  signal_to_find  = _signal_slot_map.find(signal);
        bool const  is_signal_found = signal_to_find != _signal_slot_map.end();
        auto const& slot_vector     = signal_to_find->second;

        if (is_signal_found) {

            for (auto const& slot : slot_vector) {

                slot();
            }
        }
    }

    void Signals_slots::handle_events(
        sf::Event const& event
        ) {

        _handle_hover(event);

        if (event.is<sf::Event::Closed>()) {

            _handle_window_closed_events(event);
        }

        if (event.is<sf::Event::Resized>()) {

            _handle_window_resized_events(event);
        }

        if (event.is<sf::Event::FocusLost>()) {

            _handle_window_lost_focus_events(event);
        }

        if (event.is<sf::Event::FocusGained>()) {

            _handle_window_gained_focus_events(event);
        }

        if (event.is<sf::Event::TextEntered>()) {

            _handle_text_entered_events(event);
        }

        if (event.is<sf::Event::MouseMoved>()) {

            _handle_mouse_moved_events(event);
        }

        if (event.is<sf::Event::MouseButtonPressed>()) {

            _handle_mouse_button_pressed_events(event);
        }

        if (event.is<sf::Event::MouseButtonReleased>()) {

            _handle_mouse_button_release_events(event);
        }

        if (event.is<sf::Event::MouseWheelScrolled>()) {

            _handle_mouse_wheel_events(event);
        }

        if (event.is<sf::Event::MouseEntered>()) {

            _handle_mouse_enter_window_events(event);
        }

        if (event.is<sf::Event::MouseLeft>()) {

            _handle_mouse_left_window_events(event);
        }

        if (event.is<sf::Event::JoystickButtonPressed>()) {

            _handle_joystick_button_pressed_events(event);
        }

        if (event.is<sf::Event::JoystickButtonReleased>()) {

            _handle_joystick_button_released_events(event);
        }

        if (event.is<sf::Event::JoystickMoved>()) {

            _handle_joystick_moved_events(event);
        }

        if (event.is<sf::Event::JoystickConnected>()) {

            _handle_joystick_connected_events(event);
        }

        if (event.is<sf::Event::JoystickDisconnected>()) {

            _handle_joystick_disconnected_events(event);
        }

        if (event.is<sf::Event::TouchBegan>()) {

            _handle_touch_began_events(event);
        }

        if (event.is<sf::Event::TouchMoved>()) {

            _handle_touch_moved_events(event);
        }

        if (event.is<sf::Event::TouchEnded>()) {

            _handle_touch_ended_events(event);
        }

        if (event.is<sf::Event::SensorChanged>()) {

            _handle_sensor_changed_events(event);
        }

        if (event.is<sf::Event::KeyPressed>()) {

            _handle_key_pressed_events(event);
        }

        if (event.is<sf::Event::KeyReleased>()) {

            _handle_key_released_events(event);
        }
    }

    void Signals_slots::_handle_window_closed_events(
        sf::Event const& event
        ) {

        static_cast<void>(event);
        _emit_signal(SIGNAL__WINDOW_CLOSED);
    }

    void Signals_slots::_handle_window_resized_events(
        sf::Event const& event
        ) {

        static_cast<void>(event);
        _emit_signal(SIGNAL__WINDOW_RESIZED);
    }

    void Signals_slots::_handle_window_lost_focus_events(
        sf::Event const& event
        ) {

        static_cast<void>(event);
        _emit_signal(SIGNAL__WINDOW_LOST_FOCUS);
    }

    void Signals_slots::_handle_window_gained_focus_events(
        sf::Event const& event
        ) {

        static_cast<void>(event);
        _emit_signal(SIGNAL__WINDOW_GAINED_FOCUS);
    }

    void Signals_slots::_handle_text_entered_events(
        sf::Event const& event
        ) {

        static_cast<void>(event);
        _emit_signal(SIGNAL__WINDOW_TEXT_ENTERED);
    }

    void Signals_slots::_handle_mouse_moved_events(
        sf::Event const& event
        ) {

        static_cast<void>(event);
        _emit_signal(SIGNAL__MOUSE_MOVED);
    }

    void Signals_slots::_handle_mouse_button_pressed_events(
        sf::Event const& event
        ) {

        if (auto btn_press = event.getIf<sf::Event::MouseButtonPressed>()) {

            switch (btn_press->button) {

            case sf::Mouse::Button::Left:   _emit_signal(Signal::SIGNAL__MOUSE_BUTTON_LEFT_PRESS   ); break;
            case sf::Mouse::Button::Right:  _emit_signal(Signal::SIGNAL__MOUSE_BUTTON_RIGHT_PRESS  ); break;
            case sf::Mouse::Button::Middle: _emit_signal(Signal::SIGNAL__MOUSE_BUTTON_MIDDLE_PRESS ); break;
            case sf::Mouse::Button::Extra1: _emit_signal(Signal::SIGNAL__MOUSE_BUTTON_EXTRA_1_PRESS); break;
            case sf::Mouse::Button::Extra2: _emit_signal(Signal::SIGNAL__MOUSE_BUTTON_EXTRA_2_PRESS); break;
            }
        }
    }

    void Signals_slots::_handle_mouse_button_release_events(
        sf::Event const& event
        ) {

        if (auto mouse_released = event.getIf<sf::Event::MouseButtonReleased>()) {

            switch (mouse_released->button) {

            case sf::Mouse::Button::Left:   _emit_signal(Signal::SIGNAL__MOUSE_BUTTON_LEFT_RELEASE   ); break;
            case sf::Mouse::Button::Right:  _emit_signal(Signal::SIGNAL__MOUSE_BUTTON_RIGHT_RELEASE  ); break;
            case sf::Mouse::Button::Middle: _emit_signal(Signal::SIGNAL__MOUSE_BUTTON_MIDDLE_RELEASE ); break;
            case sf::Mouse::Button::Extra1: _emit_signal(Signal::SIGNAL__MOUSE_BUTTON_EXTRA_1_RELEASE); break;
            case sf::Mouse::Button::Extra2: _emit_signal(Signal::SIGNAL__MOUSE_BUTTON_EXTRA_2_RELEASE); break;
            }
        }
    }

    void Signals_slots::_handle_mouse_wheel_events(
        sf::Event const& event
        ) {

        if (auto mouse_released = event.getIf<sf::Event::MouseWheelScrolled>()) {

            if (mouse_released->delta > 0) {

                _emit_signal(Signal::SIGNAL__MOUSE_WHEEL_UP);
            } else {

                _emit_signal(Signal::SIGNAL__MOUSE_WHEEL_DOWN);
            }
        }
    }

    void Signals_slots::_handle_mouse_enter_window_events(
        sf::Event const& event
        ) {

        static_cast<void>(event);
        _emit_signal(Signal::SIGNAL__MOUSE_ENTER_WINDOW);
    }

    void Signals_slots::_handle_mouse_left_window_events(
        sf::Event const& event
        ) {

        static_cast<void>(event);
        _emit_signal(Signal::SIGNAL__MOUSE_LEAVE_WINDOW);
    }

    // Joystick implementation is strange, if you need it
    // override this.
    void Signals_slots::_handle_joystick_button_pressed_events(
        sf::Event const& event
        ) {

        static_cast<void>(event);
        _emit_signal(Signal::SIGNAL__JOYSTICK_BUTTON_PRESSED);
    }

    // Joystick implementation is strange, if you need it
    // override this.
    void Signals_slots::_handle_joystick_button_released_events(
        sf::Event const& event
        ) {

        static_cast<void>(event);
        _emit_signal(Signal::SIGNAL__JOYSTICK_BUTTON_RELEASED);
    }

    // Joystick implementation is strange, if you need it
    // override this.
    void Signals_slots::_handle_joystick_moved_events(
        sf::Event const& event
        ) {

        static_cast<void>(event);
        _emit_signal(Signal::SIGNAL__JOYSTICK_MOVED);
    }

    // Joystick implementation is strange, if you need it
    // override this.
    void Signals_slots::_handle_joystick_connected_events(
        sf::Event const& event
        ) {

        static_cast<void>(event);
        _emit_signal(Signal::SIGNAL__JOYSTICK_CONNECTED);
    }

    // Joystick implementation is strange, if you need it
    // override this.
    void Signals_slots::_handle_joystick_disconnected_events(
        sf::Event const& event
        ) {

        static_cast<void>(event);
        _emit_signal(Signal::SIGNAL__JOYSTICK_DISCONNECTED);
    }

    // Touch implementation is strange, if you need it
    // override this.
    void Signals_slots::_handle_touch_began_events(
        sf::Event const& event
        ) {

        static_cast<void>(event);
        _emit_signal(Signal::SIGNAL__TOUCH_BEGAN);
    }

    // Touch implementation is strange, if you need it
    // override this.
    void Signals_slots::_handle_touch_moved_events(
        sf::Event const& event
        ) {

        static_cast<void>(event);
        _emit_signal(Signal::SIGNAL__TOUCH_MOVED);
    }

    // Touch implementation is strange, if you need it
    // override this.
    void Signals_slots::_handle_touch_ended_events(
        sf::Event const& event
        ) {

        static_cast<void>(event);
        _emit_signal(Signal::SIGNAL__TOUCH_ENDED);
    }

    // Sensor changed is strange, if you need it
    // override this.
    void Signals_slots::_handle_sensor_changed_events(
        sf::Event const& event
        ) {

        static_cast<void>(event);
        _emit_signal(Signal::SIGNAL__SENSOR_CHANGED);
    }

    void Signals_slots::_handle_key_pressed_events(
        sf::Event const& event
        ) {

        if (auto const key_pressed = event.getIf<sf::Event::KeyPressed>()) {

            switch (key_pressed->code) {

            case sf::Keyboard::Key::A         : _emit_signal(SIGNAL__KEYPRESS_A);         break;
            case sf::Keyboard::Key::B         : _emit_signal(SIGNAL__KEYPRESS_B);         break;
            case sf::Keyboard::Key::C         : _emit_signal(SIGNAL__KEYPRESS_C);         break;
            case sf::Keyboard::Key::D         : _emit_signal(SIGNAL__KEYPRESS_D);         break;
            case sf::Keyboard::Key::E         : _emit_signal(SIGNAL__KEYPRESS_E);         break;
            case sf::Keyboard::Key::F         : _emit_signal(SIGNAL__KEYPRESS_F);         break;
            case sf::Keyboard::Key::G         : _emit_signal(SIGNAL__KEYPRESS_G);         break;
            case sf::Keyboard::Key::H         : _emit_signal(SIGNAL__KEYPRESS_H);         break;
            case sf::Keyboard::Key::I         : _emit_signal(SIGNAL__KEYPRESS_I);         break;
            case sf::Keyboard::Key::J         : _emit_signal(SIGNAL__KEYPRESS_J);         break;
            case sf::Keyboard::Key::K         : _emit_signal(SIGNAL__KEYPRESS_K);         break;
            case sf::Keyboard::Key::L         : _emit_signal(SIGNAL__KEYPRESS_L);         break;
            case sf::Keyboard::Key::M         : _emit_signal(SIGNAL__KEYPRESS_M);         break;
            case sf::Keyboard::Key::N         : _emit_signal(SIGNAL__KEYPRESS_N);         break;
            case sf::Keyboard::Key::O         : _emit_signal(SIGNAL__KEYPRESS_O);         break;
            case sf::Keyboard::Key::P         : _emit_signal(SIGNAL__KEYPRESS_P);         break;
            case sf::Keyboard::Key::Q         : _emit_signal(SIGNAL__KEYPRESS_Q);         break;
            case sf::Keyboard::Key::R         : _emit_signal(SIGNAL__KEYPRESS_R);         break;
            case sf::Keyboard::Key::S         : _emit_signal(SIGNAL__KEYPRESS_S);         break;
            case sf::Keyboard::Key::T         : _emit_signal(SIGNAL__KEYPRESS_T);         break;
            case sf::Keyboard::Key::U         : _emit_signal(SIGNAL__KEYPRESS_U);         break;
            case sf::Keyboard::Key::V         : _emit_signal(SIGNAL__KEYPRESS_V);         break;
            case sf::Keyboard::Key::W         : _emit_signal(SIGNAL__KEYPRESS_W);         break;
            case sf::Keyboard::Key::X         : _emit_signal(SIGNAL__KEYPRESS_X);         break;
            case sf::Keyboard::Key::Y         : _emit_signal(SIGNAL__KEYPRESS_Y);         break;
            case sf::Keyboard::Key::Z         : _emit_signal(SIGNAL__KEYPRESS_Z);         break;
            case sf::Keyboard::Key::Num0      : _emit_signal(SIGNAL__KEYPRESS_NUM0);      break;
            case sf::Keyboard::Key::Num1      : _emit_signal(SIGNAL__KEYPRESS_NUM1);      break;
            case sf::Keyboard::Key::Num2      : _emit_signal(SIGNAL__KEYPRESS_NUM2);      break;
            case sf::Keyboard::Key::Num3      : _emit_signal(SIGNAL__KEYPRESS_NUM3);      break;
            case sf::Keyboard::Key::Num4      : _emit_signal(SIGNAL__KEYPRESS_NUM4);      break;
            case sf::Keyboard::Key::Num5      : _emit_signal(SIGNAL__KEYPRESS_NUM5);      break;
            case sf::Keyboard::Key::Num6      : _emit_signal(SIGNAL__KEYPRESS_NUM6);      break;
            case sf::Keyboard::Key::Num7      : _emit_signal(SIGNAL__KEYPRESS_NUM7);      break;
            case sf::Keyboard::Key::Num8      : _emit_signal(SIGNAL__KEYPRESS_NUM8);      break;
            case sf::Keyboard::Key::Num9      : _emit_signal(SIGNAL__KEYPRESS_NUM9);      break;
            case sf::Keyboard::Key::Escape    : _emit_signal(SIGNAL__KEYPRESS_ESCAPE);    break;
            case sf::Keyboard::Key::LControl  : _emit_signal(SIGNAL__KEYPRESS_LCONTROL);  break;
            case sf::Keyboard::Key::LShift    : _emit_signal(SIGNAL__KEYPRESS_LSHIFT);    break;
            case sf::Keyboard::Key::LAlt      : _emit_signal(SIGNAL__KEYPRESS_LALT);      break;
            case sf::Keyboard::Key::LSystem   : _emit_signal(SIGNAL__KEYPRESS_LSYSTEM);   break;
            case sf::Keyboard::Key::RControl  : _emit_signal(SIGNAL__KEYPRESS_RCONTROL);  break;
            case sf::Keyboard::Key::RShift    : _emit_signal(SIGNAL__KEYPRESS_RSHIFT);    break;
            case sf::Keyboard::Key::RAlt      : _emit_signal(SIGNAL__KEYPRESS_RALT);      break;
            case sf::Keyboard::Key::RSystem   : _emit_signal(SIGNAL__KEYPRESS_RSYSTEM);   break;
            case sf::Keyboard::Key::Menu      : _emit_signal(SIGNAL__KEYPRESS_MENU);      break;
            case sf::Keyboard::Key::LBracket  : _emit_signal(SIGNAL__KEYPRESS_LBRACKET);  break;
            case sf::Keyboard::Key::RBracket  : _emit_signal(SIGNAL__KEYPRESS_RBRACKET);  break;
            case sf::Keyboard::Key::Semicolon : _emit_signal(SIGNAL__KEYPRESS_SEMICOLON); break;
            case sf::Keyboard::Key::Comma     : _emit_signal(SIGNAL__KEYPRESS_COMMA);     break;
            case sf::Keyboard::Key::Period    : _emit_signal(SIGNAL__KEYPRESS_PERIOD);    break;
            case sf::Keyboard::Key::Apostrophe: _emit_signal(SIGNAL__KEYPRESS_QUOTE);     break;
            case sf::Keyboard::Key::Slash     : _emit_signal(SIGNAL__KEYPRESS_SLASH);     break;
            case sf::Keyboard::Key::Backslash : _emit_signal(SIGNAL__KEYPRESS_BACKSLASH); break;
            case sf::Keyboard::Key::Grave     : _emit_signal(SIGNAL__KEYPRESS_TILDE);     break;
            case sf::Keyboard::Key::Equal     : _emit_signal(SIGNAL__KEYPRESS_EQUAL);     break;
            case sf::Keyboard::Key::Hyphen    : _emit_signal(SIGNAL__KEYPRESS_DASH);      break;
            case sf::Keyboard::Key::Space     : _emit_signal(SIGNAL__KEYPRESS_SPACE);     break;
            case sf::Keyboard::Key::Enter     : _emit_signal(SIGNAL__KEYPRESS_RETURN);    break;
            case sf::Keyboard::Key::Backspace : _emit_signal(SIGNAL__KEYPRESS_BACKSPACE); break;
            case sf::Keyboard::Key::Tab       : _emit_signal(SIGNAL__KEYPRESS_TAB);       break;
            case sf::Keyboard::Key::PageUp    : _emit_signal(SIGNAL__KEYPRESS_PAGEUP);    break;
            case sf::Keyboard::Key::PageDown  : _emit_signal(SIGNAL__KEYPRESS_PAGEDOWN);  break;
            case sf::Keyboard::Key::End       : _emit_signal(SIGNAL__KEYPRESS_END);       break;
            case sf::Keyboard::Key::Home      : _emit_signal(SIGNAL__KEYPRESS_HOME);      break;
            case sf::Keyboard::Key::Insert    : _emit_signal(SIGNAL__KEYPRESS_INSERT);    break;
            case sf::Keyboard::Key::Delete    : _emit_signal(SIGNAL__KEYPRESS_DELETE);    break;
            case sf::Keyboard::Key::Add       : _emit_signal(SIGNAL__KEYPRESS_ADD);       break;
            case sf::Keyboard::Key::Subtract  : _emit_signal(SIGNAL__KEYPRESS_SUBTRACT);  break;
            case sf::Keyboard::Key::Multiply  : _emit_signal(SIGNAL__KEYPRESS_MULTIPLY);  break;
            case sf::Keyboard::Key::Divide    : _emit_signal(SIGNAL__KEYPRESS_DIVIDE);    break;
            case sf::Keyboard::Key::Left      : _emit_signal(SIGNAL__KEYPRESS_LEFT);      break;
            case sf::Keyboard::Key::Right     : _emit_signal(SIGNAL__KEYPRESS_RIGHT);     break;
            case sf::Keyboard::Key::Up        : _emit_signal(SIGNAL__KEYPRESS_UP);        break;
            case sf::Keyboard::Key::Down      : _emit_signal(SIGNAL__KEYPRESS_DOWN);      break;
            case sf::Keyboard::Key::Numpad0   : _emit_signal(SIGNAL__KEYPRESS_NUMPAD0);   break;
            case sf::Keyboard::Key::Numpad1   : _emit_signal(SIGNAL__KEYPRESS_NUMPAD1);   break;
            case sf::Keyboard::Key::Numpad2   : _emit_signal(SIGNAL__KEYPRESS_NUMPAD2);   break;
            case sf::Keyboard::Key::Numpad3   : _emit_signal(SIGNAL__KEYPRESS_NUMPAD3);   break;
            case sf::Keyboard::Key::Numpad4   : _emit_signal(SIGNAL__KEYPRESS_NUMPAD4);   break;
            case sf::Keyboard::Key::Numpad5   : _emit_signal(SIGNAL__KEYPRESS_NUMPAD5);   break;
            case sf::Keyboard::Key::Numpad6   : _emit_signal(SIGNAL__KEYPRESS_NUMPAD6);   break;
            case sf::Keyboard::Key::Numpad7   : _emit_signal(SIGNAL__KEYPRESS_NUMPAD7);   break;
            case sf::Keyboard::Key::Numpad8   : _emit_signal(SIGNAL__KEYPRESS_NUMPAD8);   break;
            case sf::Keyboard::Key::Numpad9   : _emit_signal(SIGNAL__KEYPRESS_NUMPAD9);   break;
            case sf::Keyboard::Key::F1        : _emit_signal(SIGNAL__KEYPRESS_F1);        break;
            case sf::Keyboard::Key::F2        : _emit_signal(SIGNAL__KEYPRESS_F2);        break;
            case sf::Keyboard::Key::F3        : _emit_signal(SIGNAL__KEYPRESS_F3);        break;
            case sf::Keyboard::Key::F4        : _emit_signal(SIGNAL__KEYPRESS_F4);        break;
            case sf::Keyboard::Key::F5        : _emit_signal(SIGNAL__KEYPRESS_F5);        break;
            case sf::Keyboard::Key::F6        : _emit_signal(SIGNAL__KEYPRESS_F6);        break;
            case sf::Keyboard::Key::F7        : _emit_signal(SIGNAL__KEYPRESS_F7);        break;
            case sf::Keyboard::Key::F8        : _emit_signal(SIGNAL__KEYPRESS_F8);        break;
            case sf::Keyboard::Key::F9        : _emit_signal(SIGNAL__KEYPRESS_F9);        break;
            case sf::Keyboard::Key::F10       : _emit_signal(SIGNAL__KEYPRESS_F10);       break;
            case sf::Keyboard::Key::F11       : _emit_signal(SIGNAL__KEYPRESS_F11);       break;
            case sf::Keyboard::Key::F12       : _emit_signal(SIGNAL__KEYPRESS_F12);       break;
            case sf::Keyboard::Key::F13       : _emit_signal(SIGNAL__KEYPRESS_F13);       break;
            case sf::Keyboard::Key::F14       : _emit_signal(SIGNAL__KEYPRESS_F14);       break;
            case sf::Keyboard::Key::F15       : _emit_signal(SIGNAL__KEYPRESS_F15);       break;
            case sf::Keyboard::Key::Pause     : _emit_signal(SIGNAL__KEYPRESS_PAUSE);     break;
            }
        }
    }

    void Signals_slots::_handle_key_released_events(
        sf::Event const& event
        ) {

        if (auto const key_released = event.getIf<sf::Event::KeyReleased>()) {

            switch (key_released->code) {

            case sf::Keyboard::Key::A         : _emit_signal(SIGNAL__KEYRELEASE_A);         break;
            case sf::Keyboard::Key::B         : _emit_signal(SIGNAL__KEYRELEASE_B);         break;
            case sf::Keyboard::Key::C         : _emit_signal(SIGNAL__KEYRELEASE_C);         break;
            case sf::Keyboard::Key::D         : _emit_signal(SIGNAL__KEYRELEASE_D);         break;
            case sf::Keyboard::Key::E         : _emit_signal(SIGNAL__KEYRELEASE_E);         break;
            case sf::Keyboard::Key::F         : _emit_signal(SIGNAL__KEYRELEASE_F);         break;
            case sf::Keyboard::Key::G         : _emit_signal(SIGNAL__KEYRELEASE_G);         break;
            case sf::Keyboard::Key::H         : _emit_signal(SIGNAL__KEYRELEASE_H);         break;
            case sf::Keyboard::Key::I         : _emit_signal(SIGNAL__KEYRELEASE_I);         break;
            case sf::Keyboard::Key::J         : _emit_signal(SIGNAL__KEYRELEASE_J);         break;
            case sf::Keyboard::Key::K         : _emit_signal(SIGNAL__KEYRELEASE_K);         break;
            case sf::Keyboard::Key::L         : _emit_signal(SIGNAL__KEYRELEASE_L);         break;
            case sf::Keyboard::Key::M         : _emit_signal(SIGNAL__KEYRELEASE_M);         break;
            case sf::Keyboard::Key::N         : _emit_signal(SIGNAL__KEYRELEASE_N);         break;
            case sf::Keyboard::Key::O         : _emit_signal(SIGNAL__KEYRELEASE_O);         break;
            case sf::Keyboard::Key::P         : _emit_signal(SIGNAL__KEYRELEASE_P);         break;
            case sf::Keyboard::Key::Q         : _emit_signal(SIGNAL__KEYRELEASE_Q);         break;
            case sf::Keyboard::Key::R         : _emit_signal(SIGNAL__KEYRELEASE_R);         break;
            case sf::Keyboard::Key::S         : _emit_signal(SIGNAL__KEYRELEASE_S);         break;
            case sf::Keyboard::Key::T         : _emit_signal(SIGNAL__KEYRELEASE_T);         break;
            case sf::Keyboard::Key::U         : _emit_signal(SIGNAL__KEYRELEASE_U);         break;
            case sf::Keyboard::Key::V         : _emit_signal(SIGNAL__KEYRELEASE_V);         break;
            case sf::Keyboard::Key::W         : _emit_signal(SIGNAL__KEYRELEASE_W);         break;
            case sf::Keyboard::Key::X         : _emit_signal(SIGNAL__KEYRELEASE_X);         break;
            case sf::Keyboard::Key::Y         : _emit_signal(SIGNAL__KEYRELEASE_Y);         break;
            case sf::Keyboard::Key::Z         : _emit_signal(SIGNAL__KEYRELEASE_Z);         break;
            case sf::Keyboard::Key::Num0      : _emit_signal(SIGNAL__KEYRELEASE_NUM0);      break;
            case sf::Keyboard::Key::Num1      : _emit_signal(SIGNAL__KEYRELEASE_NUM1);      break;
            case sf::Keyboard::Key::Num2      : _emit_signal(SIGNAL__KEYRELEASE_NUM2);      break;
            case sf::Keyboard::Key::Num3      : _emit_signal(SIGNAL__KEYRELEASE_NUM3);      break;
            case sf::Keyboard::Key::Num4      : _emit_signal(SIGNAL__KEYRELEASE_NUM4);      break;
            case sf::Keyboard::Key::Num5      : _emit_signal(SIGNAL__KEYRELEASE_NUM5);      break;
            case sf::Keyboard::Key::Num6      : _emit_signal(SIGNAL__KEYRELEASE_NUM6);      break;
            case sf::Keyboard::Key::Num7      : _emit_signal(SIGNAL__KEYRELEASE_NUM7);      break;
            case sf::Keyboard::Key::Num8      : _emit_signal(SIGNAL__KEYRELEASE_NUM8);      break;
            case sf::Keyboard::Key::Num9      : _emit_signal(SIGNAL__KEYRELEASE_NUM9);      break;
            case sf::Keyboard::Key::Escape    : _emit_signal(SIGNAL__KEYRELEASE_ESCAPE);    break;
            case sf::Keyboard::Key::LControl  : _emit_signal(SIGNAL__KEYRELEASE_LCONTROL);  break;
            case sf::Keyboard::Key::LShift    : _emit_signal(SIGNAL__KEYRELEASE_LSHIFT);    break;
            case sf::Keyboard::Key::LAlt      : _emit_signal(SIGNAL__KEYRELEASE_LALT);      break;
            case sf::Keyboard::Key::LSystem   : _emit_signal(SIGNAL__KEYRELEASE_LSYSTEM);   break;
            case sf::Keyboard::Key::RControl  : _emit_signal(SIGNAL__KEYRELEASE_RCONTROL);  break;
            case sf::Keyboard::Key::RShift    : _emit_signal(SIGNAL__KEYRELEASE_RSHIFT);    break;
            case sf::Keyboard::Key::RAlt      : _emit_signal(SIGNAL__KEYRELEASE_RALT);      break;
            case sf::Keyboard::Key::RSystem   : _emit_signal(SIGNAL__KEYRELEASE_RSYSTEM);   break;
            case sf::Keyboard::Key::Menu      : _emit_signal(SIGNAL__KEYRELEASE_MENU);      break;
            case sf::Keyboard::Key::LBracket  : _emit_signal(SIGNAL__KEYRELEASE_LBRACKET);  break;
            case sf::Keyboard::Key::RBracket  : _emit_signal(SIGNAL__KEYRELEASE_RBRACKET);  break;
            case sf::Keyboard::Key::Semicolon : _emit_signal(SIGNAL__KEYRELEASE_SEMICOLON); break;
            case sf::Keyboard::Key::Comma     : _emit_signal(SIGNAL__KEYRELEASE_COMMA);     break;
            case sf::Keyboard::Key::Period    : _emit_signal(SIGNAL__KEYRELEASE_PERIOD);    break;
            case sf::Keyboard::Key::Apostrophe: _emit_signal(SIGNAL__KEYRELEASE_QUOTE);     break;
            case sf::Keyboard::Key::Slash     : _emit_signal(SIGNAL__KEYRELEASE_SLASH);     break;
            case sf::Keyboard::Key::Backslash : _emit_signal(SIGNAL__KEYRELEASE_BACKSLASH); break;
            case sf::Keyboard::Key::Grave     : _emit_signal(SIGNAL__KEYRELEASE_TILDE);     break;
            case sf::Keyboard::Key::Equal     : _emit_signal(SIGNAL__KEYRELEASE_EQUAL);     break;
            case sf::Keyboard::Key::Hyphen    : _emit_signal(SIGNAL__KEYRELEASE_DASH);      break;
            case sf::Keyboard::Key::Space     : _emit_signal(SIGNAL__KEYRELEASE_SPACE);     break;
            case sf::Keyboard::Key::Enter     : _emit_signal(SIGNAL__KEYRELEASE_RETURN);    break;
            case sf::Keyboard::Key::Backspace : _emit_signal(SIGNAL__KEYRELEASE_BACKSPACE); break;
            case sf::Keyboard::Key::Tab       : _emit_signal(SIGNAL__KEYRELEASE_TAB);       break;
            case sf::Keyboard::Key::PageUp    : _emit_signal(SIGNAL__KEYRELEASE_PAGEUP);    break;
            case sf::Keyboard::Key::PageDown  : _emit_signal(SIGNAL__KEYRELEASE_PAGEDOWN);  break;
            case sf::Keyboard::Key::End       : _emit_signal(SIGNAL__KEYRELEASE_END);       break;
            case sf::Keyboard::Key::Home      : _emit_signal(SIGNAL__KEYRELEASE_HOME);      break;
            case sf::Keyboard::Key::Insert    : _emit_signal(SIGNAL__KEYRELEASE_INSERT);    break;
            case sf::Keyboard::Key::Delete    : _emit_signal(SIGNAL__KEYRELEASE_DELETE);    break;
            case sf::Keyboard::Key::Add       : _emit_signal(SIGNAL__KEYRELEASE_ADD);       break;
            case sf::Keyboard::Key::Subtract  : _emit_signal(SIGNAL__KEYRELEASE_SUBTRACT);  break;
            case sf::Keyboard::Key::Multiply  : _emit_signal(SIGNAL__KEYRELEASE_MULTIPLY);  break;
            case sf::Keyboard::Key::Divide    : _emit_signal(SIGNAL__KEYRELEASE_DIVIDE);    break;
            case sf::Keyboard::Key::Left      : _emit_signal(SIGNAL__KEYRELEASE_LEFT);      break;
            case sf::Keyboard::Key::Right     : _emit_signal(SIGNAL__KEYRELEASE_RIGHT);     break;
            case sf::Keyboard::Key::Up        : _emit_signal(SIGNAL__KEYRELEASE_UP);        break;
            case sf::Keyboard::Key::Down      : _emit_signal(SIGNAL__KEYRELEASE_DOWN);      break;
            case sf::Keyboard::Key::Numpad0   : _emit_signal(SIGNAL__KEYRELEASE_NUMPAD0);   break;
            case sf::Keyboard::Key::Numpad1   : _emit_signal(SIGNAL__KEYRELEASE_NUMPAD1);   break;
            case sf::Keyboard::Key::Numpad2   : _emit_signal(SIGNAL__KEYRELEASE_NUMPAD2);   break;
            case sf::Keyboard::Key::Numpad3   : _emit_signal(SIGNAL__KEYRELEASE_NUMPAD3);   break;
            case sf::Keyboard::Key::Numpad4   : _emit_signal(SIGNAL__KEYRELEASE_NUMPAD4);   break;
            case sf::Keyboard::Key::Numpad5   : _emit_signal(SIGNAL__KEYRELEASE_NUMPAD5);   break;
            case sf::Keyboard::Key::Numpad6   : _emit_signal(SIGNAL__KEYRELEASE_NUMPAD6);   break;
            case sf::Keyboard::Key::Numpad7   : _emit_signal(SIGNAL__KEYRELEASE_NUMPAD7);   break;
            case sf::Keyboard::Key::Numpad8   : _emit_signal(SIGNAL__KEYRELEASE_NUMPAD8);   break;
            case sf::Keyboard::Key::Numpad9   : _emit_signal(SIGNAL__KEYRELEASE_NUMPAD9);   break;
            case sf::Keyboard::Key::F1        : _emit_signal(SIGNAL__KEYRELEASE_F1);        break;
            case sf::Keyboard::Key::F2        : _emit_signal(SIGNAL__KEYRELEASE_F2);        break;
            case sf::Keyboard::Key::F3        : _emit_signal(SIGNAL__KEYRELEASE_F3);        break;
            case sf::Keyboard::Key::F4        : _emit_signal(SIGNAL__KEYRELEASE_F4);        break;
            case sf::Keyboard::Key::F5        : _emit_signal(SIGNAL__KEYRELEASE_F5);        break;
            case sf::Keyboard::Key::F6        : _emit_signal(SIGNAL__KEYRELEASE_F6);        break;
            case sf::Keyboard::Key::F7        : _emit_signal(SIGNAL__KEYRELEASE_F7);        break;
            case sf::Keyboard::Key::F8        : _emit_signal(SIGNAL__KEYRELEASE_F8);        break;
            case sf::Keyboard::Key::F9        : _emit_signal(SIGNAL__KEYRELEASE_F9);        break;
            case sf::Keyboard::Key::F10       : _emit_signal(SIGNAL__KEYRELEASE_F10);       break;
            case sf::Keyboard::Key::F11       : _emit_signal(SIGNAL__KEYRELEASE_F11);       break;
            case sf::Keyboard::Key::F12       : _emit_signal(SIGNAL__KEYRELEASE_F12);       break;
            case sf::Keyboard::Key::F13       : _emit_signal(SIGNAL__KEYRELEASE_F13);       break;
            case sf::Keyboard::Key::F14       : _emit_signal(SIGNAL__KEYRELEASE_F14);       break;
            case sf::Keyboard::Key::F15       : _emit_signal(SIGNAL__KEYRELEASE_F15);       break;
            case sf::Keyboard::Key::Pause     : _emit_signal(SIGNAL__KEYRELEASE_PAUSE);     break;
            }
        }
    }

    void Signals_slots::_handle_hover(
        sf::Event const& event
        ) {

        LOG(WARNING)                                  <<
        "Widget signal ["                             <<
        signal_to_str(SIGNAL__HOVER)                  <<
        "] needs to be overridden as this base class" <<
        "implementation does nothing.";
    }
}
/*
------------------------------------------------------------------------------
Namespace signals_slots END
------------------------------------------------------------------------------
*/
