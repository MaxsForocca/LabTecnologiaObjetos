/*
 * Aplicación en C++ que simula la implementación
 * de procesos paralelos por hilos, utilizando <thread>
*/
/*
#include <QDebug>
#include <cstdlib>
#include <thread>
//#include <sstream>
#include <chrono>
#include <ctime>

void ExecuteThread (int id) {
    auto nowTime = std::chrono::system_clock::now();
    std::time_t sleepTime = std::chrono::system_clock::to_time_t(nowTime);

    // Zona horaria local

    tm myLocalTime = *localtime(&sleepTime);

    qDebug() << "Thread: " << id << " sleep Time: " << std::ctime(&sleepTime);// << "\n"
    qDebug() << "Month: " << (myLocalTime.tm_mon)+1;// << "\n"
    qDebug() << "Day: " << myLocalTime.tm_mday;// << "\n"
    qDebug() << "Year: " << myLocalTime.tm_year;// << "\n"
    qDebug() << "Hours: " << myLocalTime.tm_hour;// << "\n"
    qDebug() << "Minutes: " << myLocalTime.tm_min;// << "\n"
    qDebug() << "Seconds: " << myLocalTime.tm_sec;// << "\n"

    // Sleeps por 3 segundos

    std::this_thread::sleep_for(std::chrono::seconds(3));
    nowTime = std::chrono::system_clock::now();
    sleepTime = std::chrono::system_clock::to_time_t(nowTime);
    qDebug() << "Thread " << id << "Awake Time: " << std::ctime(&sleepTime) << "\n";
}

int main() {

    std::thread th1 (ExecuteThread, 1);
    th1.join();
    std::thread th2 (ExecuteThread, 2);
    th2.join();
    return 0;
}
*/
