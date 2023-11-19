#pragma once

#include "EntitiesType.h"

class WEntity {
 protected:
    EntitiesType type;
 public:
    virtual EntitiesType getEntityType() = 0;
    virtual ~WEntity() = default;
};