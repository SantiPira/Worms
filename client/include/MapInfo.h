#pragma once

#include <vector>
#include "../../common_libs/include/ParseMapFromFile.h"

struct MapInfo {
    int cantBeams;
    std::vector<Grd> grd;
    int cantWorms;
    std::vector<GameUpdate> worms;
};