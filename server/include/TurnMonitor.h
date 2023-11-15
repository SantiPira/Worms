#pragma once

#include "../../common_libs/include/ProtectedQueue.h"

class TurnMonitor {
 private:
    ProtectedQueue<std::string> m_InputActions;
public:
    TurnMonitor();
};

