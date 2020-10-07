#include <memory>
#include "StateMachine.h"

namespace Engine {
    void StateMachine::addState(StateRef newState, bool shouldReplace) {
        _isAdding = true;
        _isReplacing = shouldReplace;
        _incomingState = std::move(newState);
    }

    void StateMachine::removeState() {
        _isRemoving = true;
    }

    void StateMachine::processStateChanges() {
        if (_isRemoving && !_states.empty()) {
            _states.pop();
            if (!_states.empty()) _states.top()->resume();
            _isRemoving = false;
        }

        if (_isAdding) {
            if (_isReplacing) _states.pop();
            else if (!_states.empty()) _states.top()->pause();
            _states.push(std::move(_incomingState));
            _states.top()->init();
            _isAdding = false;
        }
    }

    StateRef & StateMachine::getActiveState() {
        return _states.top();
    }
}