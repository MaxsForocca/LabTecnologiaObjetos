#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->addTaskButton, &QPushButton::clicked,
            QApplication::instance(), &QApplication::quit);

    connect(ui->addTaskButton, &QPushButton::clicked,
            this, &MainWindow::addTask);
}

void MainWindow::addTask(){
    qDebug()
    << "Slot corresponde al clic en el boton ...";
}

MainWindow::~MainWindow()
{
    delete ui;
}
