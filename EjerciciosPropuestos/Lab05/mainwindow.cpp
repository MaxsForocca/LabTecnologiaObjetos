#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->addCountryButton, &QPushButton::clicked, this, &MainWindow::addCountry);
}

void MainWindow::addCountry(){
    Country* newCountry = new Country(this);
    mCountries.push_back(newCountry);

    connect(newCountry, &Country::remove, this, &MainWindow::removeCountry);

    std::cout << "Agregando nuevo pais" << std::endl;

    ui->countriesLayout->addWidget(newCountry);
}

void MainWindow::removeCountry(Country* country){
    mCountries.removeOne(country);

    ui->countriesLayout->removeWidget(country);

    std::cout<< "Removiendo pais ... " << std::endl;

    country->deleteLater();
}

MainWindow::~MainWindow()
{
    delete ui;
}
