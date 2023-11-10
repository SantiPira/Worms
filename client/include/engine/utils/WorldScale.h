#pragma once

class WorldScale {
public:
    static float getPixelScale(float worldValue);
private:
    static const float worldScaleMeasure;
};