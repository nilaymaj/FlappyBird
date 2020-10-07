#pragma once

#include <memory>
#include <stack>
#include "State.h"

namespace Engine {
    typedef std::unique_ptr<State> StateRef;
    class StateMachine {
    private:
        std::stack<StateRef> _states;
        StateRef _incomingState;
        bool _isAdding, _isRemoving, _isReplacing;
    public:
        void addState(StateRef newState, bool shouldReplace = true);
        void removeState();
        StateRef& getActiveState();
        void processStateChanges();
    };
}