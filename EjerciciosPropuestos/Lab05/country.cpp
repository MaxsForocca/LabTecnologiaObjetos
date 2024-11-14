#include "country.h"
#include "ui_country.h"
#include <iostream>
#include <QInputDialog>
Country::Country(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Country)
{
    ui->setupUi(this);
    connect(ui->removeButton, &QPushButton::clicked, [this]{emit remove(this);} );
    connect(ui->editButton, &QPushButton::clicked, this, &Country::edit);
}
QString Country::getCountry() const {
    return ui->countryLabel->text();
}
QString Country::getCapital() const {
    return ui->capitalLabel->text();
}
void Country::setCountry(const QString & country){
    ui->countryLabel->setText(country);
}
void Country::setCapital(const QString & capital){
    ui->capitalLabel->setText(capital);
}
void Country::edit(){
    std::cout << "Se presiono el boton de editar ..." << std::endl;
    bool ok;
    QString country = QInputDialog::getText(this, tr("Editar Pais"), tr("Pais: "), QLineEdit::Normal, getCountry(), &ok);
    if(ok && !country.isEmpty()){
        setCountry(country);
    }
    QString capital = QInputDialog::getText(this, tr("Editar Capital"), tr("Capital: "), QLineEdit::Normal, getCapital(), &ok);
    if(ok && !capital.isEmpty()){
        setCapital(capital);
    }
}
Country::~Country()
{
    delete ui;
}
