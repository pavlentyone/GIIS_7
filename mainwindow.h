#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QString>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlTableModel>
#include <QSqlError>
#include <QSqlQuery>
#include <QImage>
#include <QBuffer>
#include <QPushButton>
#include <QTabWidget>
#include <QModelIndex>
#include <QModelIndexList>
#include <QAbstractItemModel>
#include <QVariant>
#include <QDebug>

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
    void on_pbOpen_clicked();

    void on_pbAdd_clicked();

    void on_pbRemove_clicked();

    void on_pbAbout_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
    QSqlTableModel *tm1;
    QSqlTableModel *tm2;
    QSqlTableModel *tm3;
    void SavePhoto();
};

#endif // MAINWINDOW_H
