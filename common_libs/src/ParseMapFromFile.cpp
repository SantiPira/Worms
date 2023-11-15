#include "../include/ParseMapFromFile.h"

std::vector<Grd> ParseMapFromFile::parse(const std::string& mapName) {
    std::ifstream inputFile(std::filesystem::current_path().concat("/maps/").concat(mapName + ".txt"));
    if (!inputFile.is_open()) {
        std::cerr << "Cannot open file" << std::endl;
    }

    int numGrds;
    std::vector<Grd> grds;
    inputFile >> numGrds;
    for (int i = 0; i < numGrds; i++) {
        float x, y;
        int type;
        inputFile >> type >> x >> y;
        grds.emplace_back(type, x, y);
    }
    inputFile.close();
    return grds;
}

Grd::Grd(int grdType, float posX, float posY) {
    this->grdType = static_cast<GrdEnum>(grdType);
    this->x = posX;
    this->y = posY;
}
