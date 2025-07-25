#include "pdfviewer.h"
#include <QPainter>
#include <QResizeEvent>

PdfViewer::PdfViewer(const QString& filePath, QWidget* parent)
    : QWidget(parent) {
    document = Poppler::Document::load(filePath);
    if (!document || document->isLocked())
        return;

    document->setRenderHint(Poppler::Document::Antialiasing, true);
    document->setRenderHint(Poppler::Document::TextAntialiasing, true);
    document->setRenderHint(Poppler::Document::TextHinting, true);
    document->setRenderHint(Poppler::Document::TextSlightHinting, true);

    page = document->page(0);
    if (!page)
        return;

    scaleFactor = devicePixelRatioF();
    renderPage();
}

void PdfViewer::resizeEvent(QResizeEvent* event) {
    QWidget::resizeEvent(event);
    renderPage();
    update();
}

void PdfViewer::renderPage() {
    if (!page)
        return;

    QSizeF pts = page->pageSizeF(); // 单位：point (1/72 英寸)
    double wInch = pts.width() / 72.0;
    double hInch = pts.height() / 72.0;

    QSize sizePx = size() * scaleFactor; // 当前控件尺寸，考虑 DPI

    // 计算 DPI 时保持横纵比，取较小的 DPI 值
    double dpiX = sizePx.width() / wInch;
    double dpiY = sizePx.height() / hInch;
    double dpi = qMin(dpiX, dpiY); // 保持横纵比，避免变形

    // 渲染为图像
    QImage img = page->renderToImage(dpi, dpi);
    if (img.isNull())
        return;

    img.setDevicePixelRatio(scaleFactor);
    image = img;
}

void PdfViewer::paintEvent(QPaintEvent* event) {
    QWidget::paintEvent(event);
    if (!image.isNull()) {
        QPainter painter(this);

        // 获取原始图像的宽高比
        double aspectRatio = static_cast<double>(image.width()) / image.height();

        // 获取控件的可用区域
        QRect rect = this->rect();

        // 计算适合控件的宽度和高度，保持原始宽高比
        int newWidth = rect.width();
        int newHeight = static_cast<int>(newWidth / aspectRatio);

        // 如果新的高度超出控件高度，调整宽度和高度以保持比例
        if (newHeight > rect.height()) {
            newHeight = rect.height();
            newWidth = static_cast<int>(newHeight * aspectRatio);
        }

        // 计算居中位置
        int xOffset = (rect.width() - newWidth) / 2;
        int yOffset = (rect.height() - newHeight) / 2;

        // 绘制图像，居中显示
        painter.drawImage(QRect(xOffset, yOffset, newWidth, newHeight), image);
    }
}
