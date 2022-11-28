#include "physicsWorld.hpp"
#include "components.hpp"
#include "physicsWorld.hpp"
#include <iostream>

void PhysicsWorld::addObject(Object* obj) {
    objects.push_back(obj);
};

void PhysicsWorld::removeObject(Object* obj) {
    int size = objects.size();
    for (int i = 0; i < size; ++i) {
        if (objects[i] == obj) {
            //erase the object from the list
            objects.erase(objects.begin()+i);
            break;
        }
    }
};

/* loop over each object in the objects list and update each one
    calculate the acceleration the object experiences by taking the
    force and using the objects mass (F/m=a) 
*/
void PhysicsWorld::step(float dt) {
    for (Object* obj : objects) {
        Vector3* acceleration = (obj->force)/(obj->mass);
        acceleration->y += PhysicsWorld::gravity;

        // update position
        obj->position = *(obj->position + (*(*acceleration * (0.5 * dt * dt)) + (obj->velocity * dt)));
        

        // update velo
        obj->velocity = *((obj->velocity) + (*acceleration * dt));
    }
};

void PhysicsWorld::printObjectInfo() {
    for (Object* obj : objects) {
        std::cout << "------------------------\n";
        std::cout << "Force: " << obj->force << '\n';
        std::cout << "Velocity: " << obj->velocity << '\n';
        std::cout << "Position: " << obj->position << '\n';
        std::cout << "Mass: " << obj->mass << '\n';
    }
}