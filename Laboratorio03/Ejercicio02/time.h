#ifndef TIME_H
#define TIME_H

#include <memory>  // Necesario para std::unique_ptr

class Time {
private:
    std::unique_ptr<int> hour;   
    std::unique_ptr<int> minute;  
    std::unique_ptr<int> second;  
public:
    Time(const int h = 0, const int m = 0, const int s = 0);  // Constructor

    void setTime(const int h, const int m, const int s);
    void print() const;
    bool equals(const Time&);
};

#endif
