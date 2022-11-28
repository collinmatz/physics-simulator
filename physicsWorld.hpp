#pragma once
#include "components.hpp"
#include <vector>

class PhysicsWorld {
    private:
        std::vector<Object*> objects;
        float gravity;
        float dt;
    public:
        PhysicsWorld(float dt, float gravity);
        void addObject(Object* obj);
        void removeObject(Object* obj);
        void step(float dt);
        void printObjectInfo();
};