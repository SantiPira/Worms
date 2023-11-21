#include "waitingWindow.h"

WaitingWindow::WaitingWindow(QWidget *parent) : QWidget(parent) {
    // Configurar la ventana
    setFixedSize(300, 150);
    setWindowTitle("Ventana de Espera");

    // Etiqueta para mostrar información
    etiqueta = new QLabel("Esperando al resto de jugadores...", this);
    etiqueta->setAlignment(Qt::AlignCenter);
    etiqueta->setGeometry(50, 30, 200, 30);
}