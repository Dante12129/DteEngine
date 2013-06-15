#include "Dte/StateManager.hpp"

namespace dte
{
    StateManager::StateManager() = default;
    StateManager::StateManager(State* first_state)
    {
        current_state.reset(first_state);
    }
    StateManager::~StateManager() = default;

    bool StateManager::initialize(State* first_state)
    {
        current_state.reset(first_state);
        return static_cast<bool>(current_state);
    }

    void StateManager::HandleEvents() { if(current_state) current_state->HandleEvents(); }
    void StateManager::Logic(sf::Time& delta) { if(current_state) current_state->Logic(delta); }
    void StateManager::Render() { if(current_state) current_state->Render(); }

    void StateManager::SwitchState()
    {
        if(current_state)
            if(current_state->CheckState())
                current_state.reset(current_state->GetNextState());
    }
}
