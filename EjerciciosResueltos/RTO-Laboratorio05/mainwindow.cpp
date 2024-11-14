#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), mTasks()
{
    ui->setupUi(this);
    // Conectar señal para agregar tarea apartir del boton
    connect(ui->addTaskButton, &QPushButton::clicked, this, &MainWindow::addTask);
}
void MainWindow::addTask(){
    Task *newTask = new Task(this);
    mTasks.push_back(newTask);

    // Conectar señal de eliminar de la nueva tarea a removeTask
    connect(newTask, &Task::removed, this, &MainWindow::removeTask);

    std::cout << "Agregando Tarea a layer ..." << std::endl;

    // Agregar task al layout
    ui->tasksLayout->addWidget(newTask);
}
void MainWindow::removeTask(Task* task){
    // Eliminar task del vector
    mTasks.removeOne(task);
    ui->tasksLayout->removeWidget(task);

    std::cout<< "Eliminando Tarea ... " << std::endl;

    // Liberar memoria
    task->deleteLater();
}
MainWindow::~MainWindow()
{
    delete ui;
}
