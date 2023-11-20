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
    switch (grdType) {
        case GRD_SMALL_HORIZONTAL:
            this->width = 2.0f;
            this->height = 0.5f;
            break;
        case GRD_LARGE_HORIZONTAL:
            this->width = GrdWidthEnum::GRD_HORIZONTAL_WIDTH_LARGE;
            this->height = GrdHeightEnum::GRD_HORIZONTAL_HEIGHT_LARGE;
            break;
        case GRD_LARGE_VERTICAL:
            this->width = 1.0f;
            this->height = 10.0f;
            break;
        default:
            this->width = 10.0f;
            this->height = 1.0f;
            break;
    }
}

Grd::Grd(int grdType, float posX, float posY, float w, float h) {
    this->grdType = static_cast<GrdEnum>(grdType);
    this->x = posX;
    this->y = posY;
    this->width = w;
    this->height = h;
}
