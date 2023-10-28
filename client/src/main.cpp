#include <iostream>
#include "../../common_libs/include/liberror.h"
#include "../include/PruebaClient.h"

int main(int argc, const char* argv[]) {
    if (argc != 3) {
        std::cout << "Error: argumentos invalidos" << std::endl;
        return 1;
    }
    try {
        PruebaClient client(argv[1], argv[2]);
        client.start();
    } catch (const LibError& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "Error: error desconocido" << std::endl;
        return 1;
    }
    return 0;}
