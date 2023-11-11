#include "engine/utils/WorldScale.h"

const float WorldScale::worldScaleMeasure = 51.2f;

float WorldScale::getPixelScale(float worldValue) {
    return worldValue * worldScaleMeasure;
}
