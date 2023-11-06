#pragma once

#include <string>

enum GrdEnum : uint8_t {
    GRD_LARGE_VERTICAL = 0x00,
    GRD_LARGE_HORIZONTAL = 0x01,
    GRD_LARGE_DIAGONAL_0 = 0x02,
    GRD_LARGE_DIAGONAL_1 = 0x03,
    GRD_LARGE_DIAGONAL_2 = 0x04,
    GRD_SMALL_VERTICAL = 0x05,
    GRD_SMALL_HORIZONTAL = 0x06,
    GRD_SMALL_DIAGONAL_0 = 0x07,
    GRD_SMALL_DIAGONAL_1 = 0x08,
    GRD_SMALL_DIAGONAL_2 = 0x09
};


[[maybe_unused]] inline std::string getGrdPath(GrdEnum grdType) {
    switch (grdType) {
        case GRD_LARGE_VERTICAL:
            return "resources/Weapons/grdl0.png";
        case GRD_LARGE_HORIZONTAL:
            return "resources/Weapons/grdl4.png";
        case GRD_LARGE_DIAGONAL_0:
            return "resources/Weapons/grdl1.png";
        case GRD_LARGE_DIAGONAL_1:
            return "resources/Weapons/grdl2.png";
        case GRD_LARGE_DIAGONAL_2:
            return "resources/Weapons/grdl3.png";
        case GRD_SMALL_VERTICAL:
            return "resources/Weapons/grds0.png";
        case GRD_SMALL_HORIZONTAL:
            return "resources/Weapons/grds4.png";
        case GRD_SMALL_DIAGONAL_0:
            return "resources/Weapons/grds1.png";
        case GRD_SMALL_DIAGONAL_1:
            return "resources/Weapons/grds2.png";
        case GRD_SMALL_DIAGONAL_2:
            return "resources/Weapons/grds3.png";
    }
    return "";
}
