#pragma once
#include <QWidget>
#include <QComboBox>
#include <QLabel>
#include <QPushButton>
#include "helper/languagechangehelper.h"

class LanguageChangeTest : public QWidget {
    Q_OBJECT

public:
    LanguageChangeTest(QWidget *parent = nullptr);
    ~LanguageChangeTest();

private:
    void createUi();
    void sigConnect();

private slots:
    void slotLanguageChanged();
    void slotLangComboxIndexChanged(int index);

private:
    QComboBox *lang_combox_ = nullptr;
    QLabel *label_ = nullptr;
    LanguageChangeHelper *lang_helper_ = nullptr;
};