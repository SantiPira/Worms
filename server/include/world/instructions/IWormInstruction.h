#pragma once

#include "../../../../Box2D/include/box2d/box2d.h"
#include "world/entities/WWorm.h"

class IWormInstruction {
protected:
    int m_IdPlayer = -1;
public:
    virtual void execute(WWorm* worm) = 0;
    void setIdPlayer(int idPlayer) {
        m_IdPlayer = idPlayer;
    }

    [[nodiscard]] int getIdPlayer() const {
        return m_IdPlayer;
    }

    virtual ~IWormInstruction() = default;
};

