#pragma once

#include <string>
#include <list>
#include <map>
#include <functional>

#include <system/Log.h>

namespace cima {
    class Agent {
        static const system::Log LOGGER;

        std::list<std::function<void()>> mainLoopFunctions;

        bool keepRunning = true;

        uint32_t lastRfEventTime;

        public:
            void mainLoop();
            void registerToMainLoop(const std::function<void(void)> &function);
    };
}