#ifndef HISTORYWIDGET_H
#define HISTORYWIDGET_H

#define HISTORYPIXMAP_MAX_PREVIEW_WIDTH 160
#define HISTORYPIXMAP_MAX_PREVIEW_HEIGHT 90

#include <QObject>
#include <QWidget>
#include <QDialog>
#include <QString>
#include "src/tools/imgs3/imgs3settings.h"

class QLayout;
class QVBoxLayout;
class NotificationWidget;

class HistoryWidget : public QDialog
{
    Q_OBJECT
public:
    explicit HistoryWidget(QWidget *parent = nullptr);

signals:

private:
    void loadHistory();
    void addLine(const QString &, const QString &);
    void removeItem(QLayout *pl, const QString& s3FileName, const QString& deleteToken);
    void removeLocalItem(QLayout *pl);
    void setEmptyMessage();

private:
    ImgS3Settings m_s3Settings;
    QVBoxLayout *m_pVBox;
    NotificationWidget *m_notification;
};

#endif // HISTORYWIDGET_H