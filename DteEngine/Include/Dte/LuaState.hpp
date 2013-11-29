#ifndef LUASTATE_HPP_INCLUDED
#define LUASTATE_HPP_INCLUDED

#include <string>
#include <luabind/luabind.hpp>

namespace dte
{
    class LuaState
    {
        public:
            LuaState();
            ~LuaState();

            void doString(const std::string& string);
            void doFile(const std::string& filename);

            operator lua_State*() const;

        private:
            lua_State* m_state;
    };
}

#endif // LUASTATE_HPP_INCLUDED
