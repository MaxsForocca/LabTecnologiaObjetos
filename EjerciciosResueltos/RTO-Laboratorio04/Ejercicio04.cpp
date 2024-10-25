// #include "comunicacion.h"
#include <QDebug>
#include <QObject>
#include <qcoreapplication.h>

using namespace std;
/*
// 4.b
class adulto : public QObject {
private:
    QString nombre;
public:
    adulto(QObject *base = 0): QObject(base){}
    void setNombre(const QString &nomb){
        nombre = nomb;
    }
    QString getNombre() const{ return nombre; }
    ~adulto(){ qDebug() << "..objeto destruido...";}
};

/*
int main(int argc, char *argv[]){
    /*
    // 4.a

    qDebug() << "Ejercicio 4.a";
    int x=47; double y=3.2478;
    char t = 'O';

    QString qtcadena = QString("%1 %2 %3").arg(t).arg(y).arg(x);

    string cadena = qtcadena.toStdString(); //convertir dato primitive string a QString
    qDebug() << cadena.c_str(); //convertir para mostrar en el debug
    qDebug() << qtcadena;

    qtcadena = "arequipa ciudad blanca 2021";
    qDebug() << qtcadena.contains("ciudad"); //devuelve bool
    qDebug() << qtcadena.indexOf("2021"); //devuelve la posicion.
    */
    /*
    // 4.b
    adulto *papa = new adulto;
    adulto *hijo1 = new adulto(papa);
    adulto *hijo2 = new adulto(papa);
    hijo1->setNombre("manuel");
    hijo2->setNombre("Jose");

    delete papa;
    */
    /*
    // 4.c
    QCoreApplication a(argc, argv);

    QObject *person = new QObject;
    Comunicacion *pepe = new Comunicacion(person);
    Comunicacion *jose = new Comunicacion(person);
    //set....

    QObject::connect(pepe,SIGNAL(enviarmensaje(QString)),jose,SLOT(escuchar(QString)));
    QObject::connect(jose,SIGNAL(enviarmensaje(QString)),pepe,SLOT(escuchar(QString)));
    pepe->conversar("buenos dias");
    jose->conversar("como vas?");
    delete person;

    return 0;

}
*/
