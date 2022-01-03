#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    db.close();
}

void MainWindow::on_pbOpen_clicked()
{
    if(db.isOpen())
        db.close();
    else
        db = QSqlDatabase::addDatabase("QSQLITE");
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open a database"), "/home", tr("Database files (*.sqlite *.sql *.database *.db)"));
    //mydatabase.sqlite – путь к базе данных[путь/имя.расширение]
    if(fileName != "")
        db.setDatabaseName(fileName);
    if(!db.open())
       QMessageBox::warning(this, tr("Warning"), db.lastError().text());
    if(db.isOpen()){
        tm1 = new QSqlTableModel(this, db);
        tm1->setTable("employees");
        tm1->select();
        ui->tvFirst->setModel(tm1);
        ui->tvFirst->show();
        ui->tvFirst->setColumnHidden(0, true);
        ui->tabWidget->setTabText(0, "employees");

        tm2 = new QSqlTableModel(this, db);
        tm2->setTable("minerals");
        tm2->select();
        ui->tvSecond->setModel(tm2);
        ui->tvSecond->show();
        ui->tvSecond->setColumnHidden(0, true);
        ui->tabWidget->setTabText(1, "minerals");

        tm3 = new QSqlTableModel(this, db);
        tm3->setTable("buyers");
        tm3->select();
        ui->tvThird->setModel(tm3);
        ui->tvThird->show();
        ui->tvThird->setColumnHidden(0, true);
        ui->tabWidget->setTabText(2, "buyers");
    }
}

void MainWindow::on_pbAdd_clicked()
{
    QModelIndexList modelIndexList;

    bool check = true;

    switch(ui->tabWidget->currentIndex()){
        case 0:
            modelIndexList = ui->tvFirst->selectionModel()->selectedIndexes();
            if(modelIndexList.count() > 0){
                ui->tvFirst->model()->insertRow(modelIndexList.back().row() + 1);
                check = false;
            }

            modelIndexList = ui->tvFirst->selectionModel()->selectedRows();
            if(modelIndexList.count() > 0){
                ui->tvFirst->model()->insertRow(modelIndexList.back().row() + 1);
                check = false;
            }

            if(check)
                ui->tvFirst->model()->insertRow(0);

            break;
        case 1:
            modelIndexList = ui->tvSecond->selectionModel()->selectedIndexes();
            if(modelIndexList.count() > 0){
                ui->tvSecond->model()->insertRow(modelIndexList.back().row() + 1);
                check = false;
            }

            modelIndexList = ui->tvSecond->selectionModel()->selectedRows();
            if(modelIndexList.count() > 0){
                ui->tvSecond->model()->insertRow(modelIndexList.back().row() + 1);
                check = false;
            }

            if(check)
                ui->tvSecond->model()->insertRow(0);

            break;
        case 2:
            modelIndexList = ui->tvThird->selectionModel()->selectedIndexes();
            if(modelIndexList.count() > 0){
                ui->tvThird->model()->insertRow(modelIndexList.back().row() + 1);
                check = false;
            }

            modelIndexList = ui->tvThird->selectionModel()->selectedRows();
            if(modelIndexList.count() > 0){
                ui->tvThird->model()->insertRow(modelIndexList.back().row() + 1);
                check = false;
            }

            if(check)
                ui->tvThird->model()->insertRow(0);

            break;
        default:
            QMessageBox::warning(this, "Warning", "This index does not exist");
            break;
    }
}

void MainWindow::on_pbRemove_clicked()
{
    QModelIndexList modelIndexList;
    switch(ui->tabWidget->currentIndex()){
        case 0:
            modelIndexList = ui->tvFirst->selectionModel()->selectedRows();
            if(modelIndexList.count() > 0)
                ui->tvFirst->model()->removeRows(modelIndexList.front().row(), modelIndexList.count());

            break;
        case 1:
            modelIndexList = ui->tvSecond->selectionModel()->selectedRows();
            if(modelIndexList.count() > 0)
                ui->tvSecond->model()->removeRows(modelIndexList.front().row(), modelIndexList.count());

            break;
        case 2:
            modelIndexList = ui->tvThird->selectionModel()->selectedRows();
            if(modelIndexList.count() > 0)
                ui->tvThird->model()->removeRows(modelIndexList.front().row(), modelIndexList.count());

            break;
        default:
            QMessageBox::warning(this, "Warning", "This index does not exist");
            break;
    }
}

void MainWindow::on_pbAbout_clicked()
{
    QMessageBox::aboutQt(this);
}
