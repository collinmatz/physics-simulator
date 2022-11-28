#include "componentBuilder.hpp"
#include "components.hpp"
#include "physicsWorld.hpp"

#include <iostream>
#include <string.h>


int main(int argc, char **argv) {
    // parse command line arguments
    const int MAX_ARGS = 10;
    if ((argc - 1) > MAX_ARGS) {
        std::cout << "Error. Number of arguments exceeds maximum number alloted\n";
        return -1;
    }

    int mode = 0;
    float dt = 1.0f;
    float gravity = -9.81f;
    for (int i = 0; i < argc; ++i) {
        if (std::strcmp(argv[i], "-m") == 0) {
            if (i + 1 > argc) {
                std::cout << "Expected argument after -m" << '\n';
                return -2;
            }
            if (std::strcmp(argv[i+1], "manualStep") == 0)
                mode = 1;
        }
        if (std::strcmp(argv[i], "-t") == 0) {
            if (i + 1 > argc) {
                std::cout << "Expected argument after -t" << '\n';
                return -2;
            }
            dt = std::stof(argv[i+1]);
        }
        if (std::strcmp(argv[i], "-g") == 0) {
            if (i + 1 > argc) {
                std::cout << "Expected argument after -g" << '\n';
                return -2;
            }
            gravity = std::stof(argv[i+1]);
        }
    }

    PhysicsWorld pw(dt, gravity);

    Vector3* pos = ComponentBuilder::vector3(0.0f, 0.0f, 0.0f);
    Vector3* velo  = ComponentBuilder::vector3(1.0f, -1.0f, 2.5f);
    Vector3* f = ComponentBuilder::vector3(1.0f, 2.0f, 3.0f);
    Object* obj = ComponentBuilder::object(pos, velo, f, 1.0f);

    pw.addObject(obj);

    // main loop
    if (mode == 1) {
        do {
            pw.printObjectInfo();
            pw.step(1.0f);
        } while(std::cin.get() == '\n');
    }
    else {

    }

    return 0;
};