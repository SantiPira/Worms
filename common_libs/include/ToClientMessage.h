#pragma once

#include <cstdint>

class Protocol;
class ToClientMessage {
 public:
    virtual void serialize(Protocol& protocol) = 0;
};