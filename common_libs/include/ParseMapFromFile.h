#pragma once

#include <vector>
#include <iostream>
#include <fstream>
#include "resources/GrdEnum.h"

struct Grd {
    Grd(int grdType, int posX, int posY);
    GrdEnum grdType;
    int x;
    int y;
};

class ParseMapFromFile {
public:
    static std::vector<Grd> parse(const std::string& mapName);
};