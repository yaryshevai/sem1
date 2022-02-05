#include <iostream>
#include <chrono>
#include <cmath>

using namespace std::chrono;

class Timer{
public:
    Timer(): start(steady_clock::now()) {}
    ~Timer() {
        std::cout << "Duration is " <<
                  duration_cast<microseconds>(steady_clock::now() - start).count()
                  << std::endl;
    }

private:
    steady_clock::time_point start;
};

int main() {
    auto result = 0.;
    {
        Timer t;
        for(auto i = 0u; i < 1'000'000u; i++) {
            result += sin(i) * cos(i);
        }
    }
    std::cout << "Result is " << result << std::endl;
    std::cout << "Hello, DPQE, DMCP!" << std::endl;
    return 0;
}