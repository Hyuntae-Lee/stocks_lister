#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "htmldownloader.h"
#include <QTextCodec>
#include <fstream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_downloader(this)
{
    ui->setupUi(this);
    connect(&m_downloader, SIGNAL(downloaded(QByteArray)),
            this, SLOT(on_downloadedFinished(QByteArray)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_search_clicked()
{
    // TEST
    m_downloader.download(QUrl("https://finance.naver.com/item/main.nhn?code=005930"));
}

void MainWindow::on_downloadedFinished(QByteArray data)
{
    auto codec = QTextCodec::codecForName("EUC-KR");
    QString strHtml = codec->toUnicode(data);

    std::ofstream outFile("D:\\TTT\\ttt.html");
    outFile << strHtml.toStdString();
    outFile.close();
}
