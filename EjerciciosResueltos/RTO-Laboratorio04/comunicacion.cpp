#include "comunicacion.h"
#include <QDebug>

Comunicacion::Comunicacion(QObject *parent)
    : QObject{parent}
{

}
void Comunicacion::escuchar(const QString &str){
    qDebug() << "estoy escuchando...."<<str;
}

void Comunicacion::conversar(const QString &conversa){
    //emitir la senial
    emit enviarmensaje(conversa);

}
