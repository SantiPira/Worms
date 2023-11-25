#include "messages/server/GameUpdate.h"

bool GameUpdate::operator!=(const GameUpdate& other) const {
    return player_id != other.player_id ||
           x_pos != other.x_pos ||
           y_pos != other.y_pos ||
           width != other.width ||
           height != other.height ||
           m_Health != other.m_Health ||
           m_Dir != other.m_Dir ||
           m_Weapon != other.m_Weapon ||
           m_IsAttacking != other.m_IsAttacking ||
           m_SelfCondition != other.m_SelfCondition ||
           m_Movement != other.m_Movement ||
           m_VelocityX != other.m_VelocityX ||
           m_VelocityY != other.m_VelocityY ||
           m_CurrentSprite != other.m_CurrentSprite;
}