#pragma once

#include <cstdint>
#include "ActionFromClientEnum.h"

class Protocol;
class ClientMessage {
 public:
    virtual void deserialize(Protocol& aProtocol) = 0;
};