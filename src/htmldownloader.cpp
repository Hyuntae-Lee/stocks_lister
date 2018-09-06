#include "htmldownloader.h"

HtmlDownloader::HtmlDownloader(QObject *parent)
    : QObject(parent)
{
    connect(&m_webCtrl, SIGNAL(finished(QNetworkReply*)), this,
            SLOT(onDownloadedFinished(QNetworkReply*)));
}

void HtmlDownloader::onDownloadedFinished(QNetworkReply* pReply)
{
    auto data = pReply->readAll();

    // TODO : check response code

    //emit a signal
    pReply->deleteLater();
    emit downloaded(data);
}

void HtmlDownloader::download(QUrl url)
{
    QNetworkRequest request(url);
    m_webCtrl.get(request);
}
