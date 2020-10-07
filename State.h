#pragma once

namespace Engine {
    class State {
    public:
        virtual void init() = 0;
        virtual void resume() = 0;
        virtual void pause() = 0;

        virtual void handleInput() = 0;
        virtual void update(float dt) = 0;
        virtual void draw() = 0;
    };
}