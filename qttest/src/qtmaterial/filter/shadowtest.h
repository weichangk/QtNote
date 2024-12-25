#pragma once
#include "filter/shadow.h"

#include <QWidget>

class ShadowTestWidget : public QWidget {
    Q_OBJECT

public:
    ShadowTestWidget(QWidget *parent = nullptr);
    ~ShadowTestWidget();

private:
    qtmaterialfilter::ShadowEffect *m_pShadowEffect = nullptr;
};