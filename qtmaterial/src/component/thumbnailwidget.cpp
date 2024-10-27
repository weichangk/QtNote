#include "component/thumbnailwidget.h"
#include <QPainter>
#include <QPainterPath>

ThumbnailWidget::ThumbnailWidget(QWidget *parent) :
    QWidget(parent) {
}

ThumbnailWidget::~ThumbnailWidget() {
}

void ThumbnailWidget::paintEvent(QPaintEvent *event) {
    if (m_pixmap.isNull()) {
        return;
    }

    QPainter painter(this);
    painter.save();

    painter.setRenderHint(QPainter::Antialiasing, true);
    QPixmap pixmapTemp;
    pixmapTemp = m_pixmap.scaled(this->rect().size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    pixmapTemp.setDevicePixelRatio(1);
    if (m_radiius > 0) {
        // 添加圆角裁剪
        QPainterPath path;
        path.addRoundedRect(this->rect(), m_radiius, m_radiius);
        painter.setClipPath(path);
        painter.setRenderHint(QPainter::Antialiasing);
        painter.setRenderHint(QPainter::SmoothPixmapTransform);
    }
    painter.drawPixmap(this->rect(), pixmapTemp);

    if (m_hasBorder) {
        QPen pen(QColor(177, 182, 193, 0.24 * 255));
        pen.setWidth(1);
        painter.setPen(pen);
        auto borderRect = this->rect(); //.adjusted(1, 1, -1, -1);
        painter.drawRoundedRect(borderRect, m_radiius, m_radiius);
    }

    painter.restore();
}
