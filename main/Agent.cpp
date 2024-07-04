#include "Agent.h"

#include <thread>
 
#include <string>
#include <cstring>
#include <utility>
#include <memory>
#include <fstream>

#include <stdio.h>

namespace cima {

    const system::Log Agent::LOGGER("Agent");

    void Agent::mainLoop(){
        while(keepRunning){
            for(auto function : mainLoopFunctions){
                function();
            }

            //TODO safety slowdown to avoid starvation - to be removed once finalized whole concept
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    }

    void Agent::registerToMainLoop(const std::function<void(void)> &function){
        mainLoopFunctions.push_back(function);
    }
}