#include "task.h"
#include "ui_task.h"
#include <iostream>
Task::Task(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Task)
{
    ui->setupUi(this);
    connect(ui->removeButton, &QPushButton::clicked, [this]{emit removed(this);});
    connect(ui->editButton, &QPushButton::clicked, this, &Task::edit);
}
void Task::edit(){
    std::cout << "Se presiono el boton de editar tarea" << std::endl;
}

Task::~Task()
{
    delete ui;
}
