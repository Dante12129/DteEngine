#include "Dte/StateManager.hpp"

namespace dte
{
    StateManager::StateManager() = default;
    StateManager::StateManager(std::unique_ptr<State> first) { m_state_stack.push(std::move(first)); }
    StateManager::~StateManager() = default;

    void StateManager::HandleEvents(sf::Event& event)
    {
        if(m_state_stack.top())
            m_state_stack.top()->HandleEvents(event);
    }
    void StateManager::Logic(sf::Time& dt)
    {
        if(m_state_stack.top())
            m_state_stack.top()->Logic(dt);
    }
    void StateManager::Render()
    {
        if(m_state_stack.top())
            m_state_stack.top()->Render();
    }

    std::pair<bool, StateChangeType> StateManager::GetCurrentStatus() { return m_state_stack.top()->CheckState(); }

    void StateManager::NextState()
    {
        if(m_state_stack.top())
            m_state_stack.push(m_state_stack.top()->GetNextState());
    }
    void StateManager::PrevState() { m_state_stack.pop(); }
}
