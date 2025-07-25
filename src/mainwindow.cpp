#include "mainwindow.h"
#include <QLabel>
#include <poppler-qt6.h>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent) {
    setWindowTitle("SAST demo");
    // auto label = new QLabel(this);
    // label->setAlignment(Qt::AlignCenter);
    // label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    // QString filename = "C:/Users/21421/Downloads/2024软研笔试题.pdf";
    // std::unique_ptr<Poppler::Document> document = Poppler::Document::load(filename);
    // if (!document || document->isLocked()) {
    //     return;
    // }
    // std::unique_ptr<Poppler::Page> pdfPage = document->page(0);
    // QImage image = pdfPage->renderToImage();
    // label->setPixmap(QPixmap::fromImage(image));
    // label->adjustSize();
    // label->setScaledContents(true);
    // label->show();
}

MainWindow::~MainWindow() {}
