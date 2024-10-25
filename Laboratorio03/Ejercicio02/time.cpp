#include <iostream>
#include <iomanip>
#include "time.h"

using namespace std;

// Constructor que asigna valores a la memoria dinámica
Time::Time(const int h, const int m, const int s)
    : hour(make_unique<int>(h)),   
      minute(make_unique<int>(m)), 
      second(make_unique<int>(s)) 
{}

// Método para configurar la hora, minuto y segundo
void Time::setTime(const int h, const int m, const int s) {
    *hour = h;
    *minute = m;
    *second = s;
}

// Método para imprimir la hora en formato HH:MM:SS
void Time::print() const {
    cout << setw(2) << setfill('0') << *hour << ":"
         << setw(2) << setfill('0') << *minute << ":"
         << setw(2) << setfill('0') << *second << "\n";
}

// Método para comparar dos objetos Time
bool Time::equals(const Time &otherTime) {
    return (*hour == *otherTime.hour &&
            *minute == *otherTime.minute &&
            *second == *otherTime.second);
}
