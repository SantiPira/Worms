#pragma once

#include <vector>
#include <iostream>
#include <fstream>
#include <filesystem>
#include "resources/GrdEnum.h"

struct Grd {
    Grd(int grdType, float posX, float posY);
    GrdEnum grdType;
    float x;
    float y;
};

class ParseMapFromFile {
public:
    static std::vector<Grd> parse(const std::string& mapName);
};