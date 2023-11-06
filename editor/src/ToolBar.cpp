#include "../include/ToolBar.h"

ToolBar::ToolBar(SDL2pp::Renderer *renderer) : m_Renderer(renderer){
    m_Renderer->SetDrawColor(255, 255, 255, 255);

    // Dibuja la barra de herramientas (la parte superior)
    SDL2pp::Rect toolbarRect(0, 0, 960, 50);
    m_Renderer->FillRect(toolbarRect);

    // Configura el color de fondo en blanco
    m_Renderer->SetDrawColor(0, 0, 0, 255);

    // Dibuja el área principal (el resto de la ventana)
    SDL2pp::Rect mainRect(0, 50, 960, 720 - 50);
    m_Renderer->FillRect(mainRect);
    std::vector<std::string> grdl = {

    };
}

void ToolBar::render() {
    m_Renderer->Present();
}


