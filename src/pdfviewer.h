#ifndef PDFVIEWER_H
#define PDFVIEWER_H

#include <QWidget>
#include <memory>
#include <poppler-qt6.h>

class PdfViewer : public QWidget {
    Q_OBJECT
public:
    explicit PdfViewer(const QString& filePath, QWidget* parent = nullptr);

protected:
    void resizeEvent(QResizeEvent* event) override;
    void paintEvent(QPaintEvent* event) override;

private:
    void renderPage();
    std::unique_ptr<Poppler::Document> document;
    std::unique_ptr<Poppler::Page> page;
    QImage image;
    qreal scaleFactor = 1.0;
};

#endif // PDFVIEWER_H
