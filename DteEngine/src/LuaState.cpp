#include <Dte/LuaState.hpp>

namespace dte
{
    LuaState::LuaState() { m_state = luaL_newstate(); luaL_openlibs(m_state); luabind::open(m_state); }
    LuaState::~LuaState() { lua_close(m_state); }

    void LuaState::doString(const std::string& string) { luaL_dostring(m_state, string.c_str()); }
    void LuaState::doFile(const std::string& filename) { luaL_dofile(m_state, filename.c_str()); }

    LuaState::operator lua_State*() const { return m_state; }
}
