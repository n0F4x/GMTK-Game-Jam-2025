module;

#include <chrono>

export module common.GlobalTimer;

import core.time.VariableTimer;

using namespace std::chrono_literals;

export class GlobalTimer : public core::time::VariableTimer<std::chrono::milliseconds> {
public:
    GlobalTimer() : VariableTimer{ 1s / 200 } {}
};
