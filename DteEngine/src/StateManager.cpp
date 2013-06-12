#include "Include/StateManager.hpp"

namespace dte
{
    StateManager::StateManager() = default;
    StateManager::StateManager(State* first_state)
    {
        current_state.reset(first_state);
    }
    StateManager::~StateManager() = default;

    void StateManager::HandleEvents() { current_state->HandleEvents(); }
    void StateManager::Logic(sf::Time& delta) { current_state->Logic(delta); }
    void StateManager::Render() { current_state->Render(); }

    void StateManager::SwitchState()
    {
        if(current_state)
            if(current_state->CheckState())
                current_state.reset(current_state->GetNextState());
    }
}
