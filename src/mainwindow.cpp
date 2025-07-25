#include "mainwindow.h"
#include "pdfviewer.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent) {
    setWindowTitle("PDF Viewer");
    auto viewer = new PdfViewer("C:/Users/21421/Downloads/2024软研笔试题.pdf", this);
    setCentralWidget(viewer);
}

MainWindow::~MainWindow() {}
