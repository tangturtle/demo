#include "mainwindow.h"
#include <poppler/qt6/poppler-qt6.h>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent) {
    setWindowTitle("SAST demo");
}

MainWindow::~MainWindow() {}
