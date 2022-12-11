cmake_minimum_required(VERSION 3.0.0)
project(phys_sim VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(phys_sim main.cpp componentBuilder.cpp components.cpp constructors.cpp physicsWorld.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

set_target_properties( phys_sim PROPERTIES RUNTIME_OUTPUT_DIRECTORY "../../bin/" )
