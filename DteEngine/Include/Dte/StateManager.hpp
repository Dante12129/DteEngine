#ifndef STATEMANAGER_HPP_INCLUDED
#define STATEMANAGER_HPP_INCLUDED

#include <memory>
#include "Dte/State.hpp"

namespace sf { class RenderWindow; }

namespace dte
{
    /** \addtogroup states
     * \{
     */

     /** \brief Class that manages the states in a game.
      *
      * This class manages states using the State class. It deals with changing, managing, and using states so you don't have to.
      */
    class StateManager
    {
        public:
            /** \brief The default constructor.
             */
            StateManager();
            /** \brief The main constructor.
             *
             * This constructor initializes the state machine with the first state.
             *
             * \param first_state The state to start the game engine with. It should be dynamically allocated by the programmed before being passed.
             */
            StateManager(State* first_state);
            /** \brief The default destructor.
             */
            ~StateManager();

            /** \brief Method to handle events for the current state.
             *
             * This method calls the current state's event handler.
             *
             * \return void
             */
            void HandleEvents();
            /** \brief Method to do logic and other calculations for the current state.
             *
             * This method calls the current state's logic handler.
             *
             * \param sf::Time& delta The time passed since the start of the current frame.
             * \return void
             *
             */
            void Logic(sf::Time& delta);
            /** \brief Method to render the screen.
             *
             * This method calls the current state's renderer.
             *
             * \return void
             */
            void Render();

            /** \brief Switches states.
             *
             * First, this method checks to see if the state needs change. If it does, it will change the state.
             *
             * \return void
             */
            void SwitchState();

        private:
            std::unique_ptr<State> current_state;
    };
    /** \} */
}

#endif // STATEMANAGER_HPP_INCLUDED
