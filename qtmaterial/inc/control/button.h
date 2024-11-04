#include "qtmaterial_global.h"

#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QPixmap>

namespace button {
    enum ButtonStatus {
        Normal = 0,
        Hover,
        Pressed,
        Disabled
    };
}

class QTMATERIAL_EXPORT IconButton : public QPushButton {
    Q_OBJECT
    Q_PROPERTY(int iconMargin READ iconMargin WRITE setIconMargin)
    Q_PROPERTY(QString fourIcon READ fourPixmapPath WRITE setFourPixmap)
    Q_PROPERTY(QString normalIcon READ normalPixmapPath WRITE setNormalPixmap)
    Q_PROPERTY(QString hoverIcon READ hoverPixmapPath WRITE setHoverPixmap)
    Q_PROPERTY(QString pressedIcon READ pressedPixmapPath WRITE setPressedPixmap)
    Q_PROPERTY(QString disabledIcon READ disablePixmapPath WRITE setDisablePixmap)

public:
    IconButton(QWidget *parent = nullptr);
    ~IconButton() override {
    }

    void setObjectName(const QString &);

    void setEnabled(bool);
    bool isEnabled() const;

    void setIconMargin(int);
    int iconMargin() const;

    void setFourPixmap(const QString &);
    QString fourPixmapPath() const;
    void setNormalPixmap(const QString &);
    QString normalPixmapPath() const;
    void setHoverPixmap(const QString &);
    QString hoverPixmapPath() const;
    void setPressedPixmap(const QString &);
    QString pressedPixmapPath() const;
    void setDisablePixmap(const QString &);
    QString disablePixmapPath() const;

protected:
    void paintEvent(QPaintEvent *) override;
    void mousePressEvent(QMouseEvent *) override;
    void mouseReleaseEvent(QMouseEvent *) override;
    void enterEvent(QEvent *) override;
    void leaveEvent(QEvent *) override;

private:
    void setButtonState(button::ButtonStatus);
    QPixmap getCurrentPixmap() const;

private:
    QString m_strFourStatePath = "";
    QString m_strNormalPath = "";
    QString m_strHoverPath = "";
    QString m_strPressedPath = "";
    QString m_strDisabledPath = "";

    QPixmap m_pixmapFourState;
    QPixmap m_pixmapNormal;
    QPixmap m_pixmapHover;
    QPixmap m_pixmapPressed;
    QPixmap m_pixmapDisabled;

    button::ButtonStatus m_eButtonState = button::ButtonStatus::Normal;
    
    int m_nIconMargin = 0;
};

class QTMATERIAL_EXPORT HorIconTextButton : public QPushButton {
    Q_OBJECT
    Q_PROPERTY(int iconSize READ iconSize WRITE setIconSize)
    Q_PROPERTY(int leftRightSpacing READ leftRightSpacing WRITE setLeftRightSpacing)
    Q_PROPERTY(int iconTextSpacing READ iconTextSpacing WRITE setIconTextSpacing)
    Q_PROPERTY(QString fourIcon READ fourPixmapPath WRITE setFourPixmap)
    Q_PROPERTY(QString normalIcon READ normalPixmapPath WRITE setNormalPixmap)
    Q_PROPERTY(QString hoverIcon READ hoverPixmapPath WRITE setHoverPixmap)
    Q_PROPERTY(QString pressedIcon READ pressedPixmapPath WRITE setPressedPixmap)
    Q_PROPERTY(QString disabledIcon READ disablePixmapPath WRITE setDisablePixmap)

public:
    HorIconTextButton(QWidget *parent = nullptr);
    ~HorIconTextButton() override {
    }

    void setObjectName(const QString &);

    void setEnabled(bool);
    bool isEnabled() const;

    void setText(const QString &);
    QString text() const;

    void setIconSize(int);
    int iconSize() const;

    void setLeftRightSpacing(int);
    int leftRightSpacing() const;

    void setIconTextSpacing(int);
    int iconTextSpacing() const;

    void setFourPixmap(const QString &);
    QString fourPixmapPath() const;
    void setNormalPixmap(const QString &);
    QString normalPixmapPath() const;
    void setHoverPixmap(const QString &);
    QString hoverPixmapPath() const;
    void setPressedPixmap(const QString &);
    QString pressedPixmapPath() const;
    void setDisablePixmap(const QString &);
    QString disablePixmapPath() const;

protected:
    void paintEvent(QPaintEvent *) override;
    void mousePressEvent(QMouseEvent *) override;
    void mouseReleaseEvent(QMouseEvent *) override;
    void enterEvent(QEvent *) override;
    void leaveEvent(QEvent *) override;

private:
    void setButtonState(button::ButtonStatus);
    QPixmap getCurrentPixmap() const;

private:
    QHBoxLayout *m_pLayout = nullptr;
    QLabel *m_pText = nullptr;

    QString m_strFourStatePath = "";
    QString m_strNormalPath = "";
    QString m_strHoverPath = "";
    QString m_strPressedPath = "";
    QString m_strDisabledPath = "";

    QPixmap m_pixmapFourState;
    QPixmap m_pixmapNormal;
    QPixmap m_pixmapHover;
    QPixmap m_pixmapPressed;
    QPixmap m_pixmapDisabled;

    button::ButtonStatus m_eButtonState = button::ButtonStatus::Normal;
    
    int m_nIconSize = 16;
    int m_nLeftRightSpacing = 4;
    int m_nIconTextSpacing = 2;
};