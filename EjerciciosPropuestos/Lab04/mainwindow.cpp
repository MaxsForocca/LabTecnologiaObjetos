#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Intenta abrir el archivo JSON que contiene datos de países, con ruta absoluta.
    QFile file("C:\\Universidad\\UNSA\\2024B\\LAB TO C\\LabTecnologiaObjetos\\EjerciciosPropuestos\\Lab04\\paises2.json");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "No se puede abrir el archivo. "+ file.errorString());
        return; // Sale del constructor si el archivo no se puede abrir.
    }

    QByteArray fileData = file.readAll(); // Leer todo el contenido del archivo.
    file.close();

    // Procesa el contenido JSON.
    QJsonDocument document = QJsonDocument::fromJson(fileData);
    QJsonArray countriesArray = document.array(); // Convertir el documento JSON a un arreglo.

    // Recorrer cada pais en el arreglo JSON.
    for (const QJsonValue &countryValue : countriesArray) {
        QJsonObject countryObject = countryValue.toObject();
        QString countryName = countryObject["name"].toObject()["common"].toString(); // Extraer el nombre del pas.
        QString capital = countryObject["capital"].toArray().first().toString(); // Extraer la capital
        QString language = countryObject["languages"].toObject().begin().value().toString(); // Extraer el primer idioma.

        countryData[countryName] = qMakePair(capital, language); // Almacenar los datos en el mapa.

        ui->listWidget_paises->addItem(countryName); // Agregar el nombre del pais a la lista.
    }

    connect(ui->listWidget_paises, &QListWidget::itemClicked, this, &MainWindow::onCountrySelected); // Conectar la señal de clic a la funcion correspondiente.
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Slot que maneja la selección de un pais.
void MainWindow::onCountrySelected(QListWidgetItem *item)
{
    QString countryName = item->text(); // Obtener el nombre del pais seleccionado.
    if (countryData.contains(countryName)) { // Verificar si el pais existe en el mapa.
        QString capital = countryData[countryName].first; // Obtener la capital
        QString language = countryData[countryName].second; // Obtener el idioma

        // Actualizar las etiquetas de la interfaz
        ui->label_pais->setText(countryName);
        ui->label_capital->setText(capital);
        ui->label_idioma->setText(language);
    }
}
