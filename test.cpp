#include <iostream>
#include <chrono>
#include <cmath>

using namespace std::chrono;

template <typename T>
class Timer{
public:
    Timer() : start(steady_clock::now()), stop(stop), time(0) {}
    ~Timer() {}

    void Stop(){
        stop = steady_clock::now();
        time = time + steady_clock::duration (stop - start);
        std::cout << "Time now: " << duration_cast<T>(time).count() << std::endl;
    }

    void Continue(){
        start = steady_clock::now();
    }

private:
    steady_clock::time_point start;
    steady_clock::time_point stop;
    steady_clock::duration time;
};

int main() {
    auto result = 0.;
    Timer<milliseconds> t;
    for(auto i = 0u; i < 1'000'000u; i++) {
        result += sin(i) * cos(i);
    }
    t.Stop();
    for(auto i = 0u; i < 1'000'000u; i++) {
        result += sin(i) * cos(i);
    }
    t.Continue();
    for(auto i = 0u; i < 1'000'000u; i++) {
        result += sin(i) * cos(i);
    }
    t.Stop();
    std::cout << "Hello, Niki!" << std::endl;
    return 0;
}

