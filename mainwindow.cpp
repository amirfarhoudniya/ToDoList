 #include "mainwindow.h"
#include "ui_mainwindow.h"




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("toDoList");

        //fix the size of window
        this->setFixedSize(this->geometry().width(),this->geometry().height());

        //pendingList dragAndDrop enable
        ui->pendingList->setEnabled(true);
        ui->pendingList->setDragEnabled(true);
        ui->pendingList->setDropIndicatorShown(true);
        ui->pendingList->setAcceptDrops(true);
        ui->pendingList->setDefaultDropAction(Qt::MoveAction);
        //pendingList styleSheet design
        ui->pendingList->setStyleSheet("QListView {font-size:12pt;}"
                                       "QListView::item {background-color:orange;"
                                       "border:1px solid black;}"
                                       "QListView::item:selected:active{background-color: blue;}");

        //completedList dragAndDrop enable
        ui->completedList->setEnabled(true);
        ui->completedList->setDragEnabled(true);
        ui->completedList->setDropIndicatorShown(true);
        ui->completedList->setAcceptDrops(true);
        ui->completedList->setDefaultDropAction(Qt::MoveAction);
        //completedList styleSheet design
        ui->completedList->setStyleSheet("QListView {font-size:12pt;}"
                                        "QListView::item {background-color:green;"
                                        "border:1px solid black;}"
                                        "QListView::item:selected:active{background-color: blue;}");

    //set listViews as QstringListModel
    ui->pendingList->setModel(new QStringListModel());
    ui->completedList->setModel(new QStringListModel());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_add_pushButton_clicked()
{
    ui->pendingList->model()->insertRow(ui->pendingList->model()->rowCount());
    QModelIndex index = ui->pendingList->model()->index(ui->pendingList->model()->rowCount() - 1 , 0);
    ui->pendingList->edit(index);
}


void MainWindow::on_delete_pushButton_clicked()
{
    QModelIndex index = ui->pendingList->currentIndex();
    ui->pendingList->model()->removeRow(index.row());
}

