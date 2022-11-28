#include "componentBuilder.hpp"
#include "components.hpp"
#include "physicsWorld.hpp"

#include <iostream>
#include <string.h>


int main(int argc, char **argv) {
    // parse command line arguments
    const int MAX_ARGS = 1;
    if ((argc - 1) > MAX_ARGS) {
        std::cout << "Error. Number of arguments exceeds maximum number alloted\n";
        return -1;
    }

    bool manualStep = false;
    for (int i = 0; i < argc; ++i) {
        if (strcmp(argv[i], "manualStep") == 0)
            manualStep = true;
    }

    PhysicsWorld pw;

    Vector3* pos = ComponentBuilder::vector3(0.0f, 0.0f, 0.0f);
    Vector3* velo  = ComponentBuilder::vector3(1.0f, -1.0f, 2.5f);
    Vector3* f = ComponentBuilder::vector3(1.0f, 2.0f, 3.0f);
    Object* obj = ComponentBuilder::object(pos, velo, f, 1.0f);

    pw.addObject(obj);

    // main loop
    if (manualStep) {
        do {
            pw.printObjectInfo();
            pw.step(1.0f);
        } while(std::cin.get() == '\n');
    }
    else {

    }

    return 0;
};