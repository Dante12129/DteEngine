#ifndef STATEMANAGER_HPP_INCLUDED
#define STATEMANAGER_HPP_INCLUDED

#include <stack>
#include "Dte/State.hpp"

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
             * \param first_state The state to start the game engine with. It will not be valid after being moved into the manager.
             */
            StateManager(std::unique_ptr<State> first);
            /** \brief The default destructor.
             */
            ~StateManager();

            void HandleEvents(sf::Event& event);
            void Logic(sf::Time& dt);
            void Render();

            std::pair<bool, StateChangeType> GetCurrentStatus();

            void NextState();
            void PrevState();

        private:
            std::stack<std::unique_ptr<State>> m_state_stack;
    };
    /** \} */
}

#endif // STATEMANAGER_HPP_INCLUDED
