#include "engine/utils/WorldScale.h"

const float WorldScale::worldScaleMeasure = 25.6f;

float WorldScale::getPixelScale(float worldValue) {
    return worldValue * worldScaleMeasure;
}
