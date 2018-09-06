#ifndef HTMLDOWNLOADER_H
#define HTMLDOWNLOADER_H

#include <QObject>
#include <QByteArray>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

class HtmlDownloader : public QObject
{
    Q_OBJECT
public:
    explicit HtmlDownloader(QObject *parent = 0);
    QByteArray downloadedData() const;
    void download(QUrl url);

signals:
    void downloaded(QByteArray data);

private slots:
    void onDownloadedFinished(QNetworkReply* pReply);

private:
    QNetworkAccessManager m_webCtrl;
};

#endif // HTMLDOWNLOADER_H
