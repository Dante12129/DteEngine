#ifndef STATE_HPP_INCLUDED
#define STATE_HPP_INCLUDED

namespace sf { class Time; }

/**
 * \brief The base namespace for all library members.
 */

namespace dte
{
    /** \addtogroup states
     * \{
     */

    /** \brief Interface that specifies a state in the game.
     *
     * These states are managed by the StateManager class. States can be things like menus, credits, the game itself, etc.
     */
    class State
    {
        public:
            /** \brief Virtual destructor.
             *
             * This class needs a virtual destructor so that the classes can inherit from it safely.
             */
            virtual ~State() = 0;

            /** \brief Handle events for the state.
             *
             * It is recommended that you handle the close event here.
             *
             * \return void
             */
            virtual void HandleEvents() = 0;
            /** \brief Handle logic for the state.
             *
             * This is where you do all your main calculations and etc.
             *
             * \param delta The current delta for the frame.
             * \return void
             */
            virtual void Logic(sf::Time& delta) = 0;
            /** \brief Render all things to the target that need to be rendered.
             *
             * This is where you render all your drawables to the target.
             *
             * \return void
             */
            virtual void Render() = 0;

            /** \brief Checks whether the state needs to be changed.
             *
             * \return Whether StateManager needs to change the state.
             */
            virtual bool CheckState() = 0;
            /** \brief Gets a pointer to the next state that will be run by the manager.
             *
             * StateManager uses this to change to the next state.
             *
             * \return A pointer to the next state to be activated. This pointer should be dynamically allocated.
             */
            virtual State* GetNextState() = 0;
    };

    /** \} */
}

#endif // STATE_HPP_INCLUDED
