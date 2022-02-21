#include <iostream>
#include <chrono>
#include <cmath>

using namespace std::chrono;

template <typename T>
class Timer{
public:
    Timer(): start(steady_clock::now()) {}
    ~Timer() {}
    void time(){
        std::cout << "Duration is " << duration_cast<T>(steady_clock::now() - start).count() - duration_cast<T>(point2 - point1).count()<< std::endl;
    }
    void point(){
        point1 = steady_clock::now();
    }
    void restart(){
        point2 = steady_clock::now();
    }

private:
    steady_clock::time_point start;
    steady_clock::time_point point1;
    steady_clock::time_point point2;
};


int main() {
    auto result = 0.;
    {
        Timer<microseconds> t;
        t.time();
        for(auto i = 0u; i < 1'000'000u; i++) {
            result += sin(i) * cos(i);
        }

    }
    {
        Timer<microseconds> t;
        t.time();
        for(auto i = 0u; i < 1'000'000u; i++) {
            result += sin(i) * cos(i);
            if (i==1'000u) t.point();
            if (i==501'000u) t.restart();
        }
    }
    return 0;
}