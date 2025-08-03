module;

#include <chrono>

export module messages.CurrentTimeMessage;

export struct CurrentTimeMessage {
    std::chrono::steady_clock::time_point value = std::chrono::steady_clock::now();
};
