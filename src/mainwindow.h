#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <memory>
#include <htmldownloader.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_search_clicked();
    void on_downloadedFinished(QByteArray data);

private:
    Ui::MainWindow *ui;
    HtmlDownloader m_downloader;
};

#endif // MAINWINDOW_H
