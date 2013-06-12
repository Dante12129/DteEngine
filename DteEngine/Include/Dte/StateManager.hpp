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
            ~StateManager();

            void HandleEvents();
            void Logic(sf::Time&);
            void Render();

            void SwitchState();

        private:
            std::unique_ptr<State> current_state;
    };
    /** \} */
}

#endif // STATEMANAGER_HPP_INCLUDED
