#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QMap>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onCountrySelected(QListWidgetItem *item); // Slot que maneja la selección de un país.

private:
    Ui::MainWindow *ui;
    QMap<QString, QPair<QString, QString>> countryData; // Mapa que almacena información de países (capital e idioma).
};

#endif // MAINWINDOW_H
