/// @file Widget.h
/// @brief Base widget class for UI components with state management and rendering

#ifndef WIDGET_H
#define WIDGET_H

/// @mainpage Widget Base Class
///
/// @section intro_sec Introduction
///
/// The Widget base class provides core foundation for UI widgets with basic state management,
/// positioning, and rendering capabilities. This is a simplified version where advanced
/// functionality like signal/slot communication, event handling, and animations should be
/// derived from the relevant classes.
///
/// @section lifecycle_sec Overview & Lifecycle
///
/// Widgets exist on a single RenderWindow and should be managed by pointers that are
/// dynamically created on the heap using "new" or smart pointers (never copied or moved)
/// and freed in the destructor of the class where they are created.
///
/// The typical lifecycle is:
///
///   1. Construction:   Widget created with parent window reference
///   2. Initialization: Size, position, and appearance set up
///   3. Active use:     Drawing occurs each frame
///   4. Destruction:    Virtual destructor called, cleanup performed
///
/// Each frame, widgets should call draw() to render to the parent window.
///
/// @section state_sec State Management
///
/// @subsection states_subsec State Enums
///
/// The base Widget class defines a basic State enum with three states:
///
///   - DEFAULT:     Widget is active and visible
///   - HIDDEN:      Widget is not rendered
///   - HOVERING:    Mouse over the widget
///   - TYPING:      Widget is receiving text input
///
/// If new states are discovered then they should be added to this base class to be usable
/// for all widgets to obtain a comprehensive list like the signals/slots. Also any new
/// states added should also be extended in the state_to_str(State) function.
///
/// @subsection transitions_subsec State Transitions
///
/// The change_state(State) method handles state transitions. It automatically prevents
/// redundant state changes (if already in the target state, nothing happens). Derived
/// classes should, if needed, create widget specific state transition methods
/// that call change_state(State) and perform any visual updates.
///
/// @section drawing_sec Drawing & Updates
///
/// @subsection draw_subsec Draw Method
///
/// Override draw() to render the widget. The base implementation:
///
///   1. Checks if in HIDDEN state, if so, returns without drawing
///   2. Calls _update_widget() for final pre draw updates
///   3. Logs a warning if not overridden
///
/// @subsection update_subsec Update Widget
///
/// The protected _update_widget() method is called just before drawing and should perform
/// any final calculations or state updates. Use this for:
///
///   - Recalculating positions
///   - Refreshing text content
///   - Syncing with external data
///   - Other pre render adjustments
///
/// @section position_sec Position & Size Management
///
/// The base class provides virtual setters and getters for position, size, scale, and
/// origin. All have default empty implementations, so override only what your widget needs.
///
/// Some widgets may support size, others scale, or both. The base class doesn't enforce
/// which to implement so use what makes sense for your widget type.
///
/// Note: For consistent scaling behavior, it's recommended to handle scaling calculations
/// (based on render window size) outside these functions to avoid double scaling issues.
///
/// @section ownership_sec Rule of 5 & Ownership
///
/// Widgets are NOT copyable or moveable:
///
///   - No copy constructor
///   - No copy assignment
///   - No move constructor
///   - No move assignment
///
/// This is intentional. Widgets should ONLY be managed as pointers or references, never
/// copied or moved. Always create widgets with new and manage them via
/// smart pointers or delete manually in destructors if using raw pointers.

/*
------------------------------------------------------------------------------
Includes
------------------------------------------------------------------------------
*/
#include "SFML/Graphics.hpp"

#include <memory>

/// @brief Widget namespace containing all UI widget classes
namespace widgets {

    /// @brief Base class for all UI widgets
    ///
    /// @details Provides core functionality for state management, positioning,
    ///          rendering, and lifecycle management. All UI widgets should inherit
    ///          from this class.
    ///
    /// @ingroup Widgets
    class Widget {
        // =========================================================================
        // Construction / Destruction
        // =========================================================================
    public:
        /// @brief Virtual destructor for proper polymorphic destruction
        virtual ~Widget() = default;

    protected:
        /// @brief Default constructor is deleted - widgets require a parent window
        Widget() = delete;

        /// @brief Construct a new Widget with a parent window
        /// @param parent_window Reference to the parent render window
        explicit Widget(std::shared_ptr<sf::RenderWindow> parent_window);

        /// @brief Reference to the parent window for rendering
        std::shared_ptr<sf::RenderWindow> _parent_window;

        // =========================================================================
        // Rule of 5 - Deleted Operations
        // =========================================================================
        // There is no need for any of these operations. Widgets should be
        // added using pointers and new, not copied or assigned as this can
        // get confusing with more complicated widgets referencing
        // the same thing or containing pointers to other widgets etc.
    protected:
        Widget           (Widget const&) = delete; ///< Copy constructor deleted
        Widget& operator=(Widget const&) = delete; ///< Copy assignment deleted
        Widget           (Widget&&     ) = delete; ///< Move constructor deleted
        Widget& operator=(Widget&&     ) = delete; ///< Move assignment deleted

        // =========================================================================
        // State Management
        // =========================================================================
    public:
        /// @brief Widget state enumeration
        enum State {
            STATE__DEFAULT,  ///< Widget is active and visible
            STATE__HIDDEN,   ///< Widget is not rendered
            STATE__HOVERING, ///< Mouse is hovering over widget
            STATE__TYPING    ///< Widget is receiving text input
        };

        /// @brief Convert state enum to string representation
        /// @param state The state to convert
        /// @return std::string String representation of the state
        std::string state_to_str(State const state) const;

        /// @brief Change the widget's current state
        /// @param state_to_change_to The new state to transition to
        virtual void change_state(State const state_to_change_to);

    protected:
        /// @brief Current state of the widget
        State _current_state;

        // =========================================================================
        // Core Functionality
        // =========================================================================
    public:
        /// @brief Draw the widget to its parent window
        /// @details Override this function in derived classes to implement
        ///          custom rendering. Base implementation checks for HIDDEN
        ///          state and calls _update_widget().
        virtual void draw();

        /// @brief Move the widget by specified offset
        /// @param offset Vector offset to move the widget by
        virtual void move(sf::Vector2f const offset);

        /// @brief Move the widget by specified coordinates
        /// @param x X coordinate offset
        /// @param y Y coordinate offset
        virtual void move(float const x, float const y);

        /// @brief Rotate the widget by specified angle
        /// @param angle Angle to rotate the widget by
        virtual void rotate(sf::Angle const angle);

    protected:
        /// @brief Update widget before drawing
        /// @details Called automatically before draw(). Override to implement
        ///          pre-render updates like recalculating positions or
        ///          refreshing content.
        virtual void _update_widget();

        // =========================================================================
        // Setter Functions
        // =========================================================================
    public:
        /// @brief Set the widget size
        /// @param size New size as 2D vector
        virtual void set_size(sf::Vector2f const size);

        /// @brief Set the widget size
        /// @param x Width
        /// @param y Height
        virtual void set_size(float const x, float const y);

        /// @brief Set the widget scale
        /// @param scale New scale as 2D vector
        virtual void set_scale(sf::Vector2f const scale);

        /// @brief Set the widget scale
        /// @param x X scale factor
        /// @param y Y scale factor
        virtual void set_scale(float const x, float const y);

        /// @brief Set the widget position
        /// @param pos New position as 2D vector
        virtual void set_pos(sf::Vector2f const pos);

        /// @brief Set the widget position
        /// @param x X coordinate
        /// @param y Y coordinate
        virtual void set_pos(float const x, float const y);

        /// @brief Set the widget origin
        /// @param origin New origin as 2D vector
        virtual void set_origin(sf::Vector2f const origin);

        /// @brief Set the widget origin
        /// @param x X origin
        /// @param y Y origin
        virtual void set_origin(float const x, float const y);

        /// @brief Set the widget rotation
        /// @param angle New rotation angle
        virtual void set_rotation(sf::Angle const angle);

        // =========================================================================
        // Getter Functions
        // =========================================================================
    public:
        /// @brief Get the widget size
        /// @return sf::Vector2f Current size as 2D vector
        virtual sf::Vector2f get_size() const;

        /// @brief Get the widget width
        /// @return float Current width
        virtual float get_size_x() const;

        /// @brief Get the widget height
        /// @return float Current height
        virtual float get_size_y() const;

        /// @brief Get the widget scale
        /// @return sf::Vector2f Current scale as 2D vector
        virtual sf::Vector2f get_scale() const;

        /// @brief Get the widget X scale
        /// @return float Current X scale factor
        virtual float get_scale_x() const;

        /// @brief Get the widget Y scale
        /// @return float Current Y scale factor
        virtual float get_scale_y() const;

        /// @brief Get the widget position
        /// @return sf::Vector2f Current position as 2D vector
        virtual sf::Vector2f get_pos() const;

        /// @brief Get the widget X position
        /// @return float Current X coordinate
        virtual float get_pos_x() const;

        /// @brief Get the widget Y position
        /// @return float Current Y coordinate
        virtual float get_pos_y() const;

        /// @brief Get the widget origin
        /// @return sf::Vector2f Current origin as 2D vector
        virtual sf::Vector2f get_origin() const;

        /// @brief Get the widget X origin
        /// @return float Current X origin
        virtual float get_origin_x() const;

        /// @brief Get the widget Y origin
        /// @return float Current Y origin
        virtual float get_origin_y() const;

        /// @brief Get the widget rotation
        /// @return sf::Angle Current rotation angle
        virtual sf::Angle get_rotation() const;
        // =========================================================================
        // Helper Functions
        // =========================================================================
    protected:
        bool _is_parent_window_nullptr() const;
    }; // class widget

} // namespace widgets

#endif // WIDGET_H
