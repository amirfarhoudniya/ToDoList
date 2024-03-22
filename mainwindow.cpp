#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDrag>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QStringListModel>


MainWindow::MainWindow(QWidget *parent)
   : QMainWindow(parent)
   , ui(new Ui::MainWindow)
{
   ui->setupUi(this);
   this->setWindowTitle("toDoList");
   this->setStyleSheet("background-color:lightgray; color:black");


   ui->pendingList->setDragEnabled(true);
   ui->pendingList->setDropIndicatorShown(true);
   ui->pendingList->setAcceptDrops(true);
   ui->pendingList->setDefaultDropAction(Qt::MoveAction);
   ui->pendingList->setStyleSheet("QListView {font-size:18pt;}"
                                  "QListView::item {background-color:#E74C3C;padding:10%;"
                                  "border:1px solid #E74C3C; border-radius:15px;}"
                                  "QListView::item:hover{background-color:#E74C3C}"
                                  "font: Times New Roman");



    ui->completedList->setDragEnabled(true);
    ui->completedList->setDropIndicatorShown(true);
    ui->completedList->setAcceptDrops(true);
    ui->completedList->setDefaultDropAction(Qt::MoveAction);
    ui->completedList->setStyleSheet("QListView {font-size:18pt; }"
                                   "QListView::item {background-color:#27AE60;padding:10%;"
                                   "border:1px solid #27AE60; border-radius:15px;}"
                                   "QlistView::item::hover{background-color:#27AE60}"
                                     "font: Times New Roman");

    ui->pendingList->setModel(new QStringListModel());
    ui->completedList->setModel(new QStringListModel());

}

MainWindow::~MainWindow()
{
   delete ui;
}


void MainWindow::on_pushButton_clicked()
{
   ui->pendingList->model()->insertRow(ui->pendingList->model()->rowCount());
   QModelIndex index = ui->pendingList->model()->index(ui->pendingList->model()->rowCount() - 1 , 0);

   ui->pendingList->edit(index);
}


void MainWindow::on_pushButton_2_clicked()
{
   QModelIndex index = ui->pendingList->currentIndex();
   ui->pendingList->model()->removeRow(index.row());
}




