#include "../include/utils/WorldScale.h"

const float WorldScale::worldScaleMeasure = 25.6f;
const float WorldScale::heightWindow = 512;

float WorldScale::pixelToWorldX(float initPixelValue, float width) {
    float scaledValue = initPixelValue / worldScaleMeasure;
    return scaledValue + (width / 2);
}

float WorldScale::pixelToWorldY(float initPixelValue, float height) {
    float scaledValue = initPixelValue / worldScaleMeasure;
    float heightWorld = heightWindow / worldScaleMeasure;
    return (heightWorld - scaledValue) + (height / 2);
}

float WorldScale::worldToPixelX(float initWorldValue, float width) {
    float scaledValue = worldScaleMeasure * initWorldValue;
    return scaledValue - (width / 2);
}

float WorldScale::worldToPixelY(float initWorldValue, float height) {
    float scaledValue = worldScaleMeasure * initWorldValue;
    return heightWindow - (scaledValue - (height / 2));
}
