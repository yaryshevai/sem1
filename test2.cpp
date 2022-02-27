#include <array>
#include <chrono>
#include <iostream>
#include <iterator>
#include<forward_list>
#include <list>
#include <random>
#include <vector>

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

int main(){
    auto current_timestamp = std::chrono::steady_clock::now().time_since_epoch().count();
    auto generator = std::mt19937_64(current_timestamp);
    auto distribution = std::uniform_int_distribution(1, 10);


    std::vector<int> vector;
    std::generate_n(std::back_inserter(vector), 100000,
                    [&distribution, &generator](){
                        return distribution(generator);
                    });
    {
        Timer<nanoseconds> t;
        t.time();
        std::sort(vector.begin(), vector.end());
    }
    /*std::array<int, 100000> array{};
    std::generate_n(array.begin(), 100000,[&distribution, &generator](){
        return distribution(generator);
    });
     {
        Timer<nanoseconds> t;
        t.time();
        std::sort(array.begin(), array.end());
    }
    */

/*
    std::forward_list<int> forwardList;
    std::generate_n(forwardList.begin(), 10000, [&distribution, &generator](){
        return distribution(generator);
    });

    std::list<int> list;
    std::generate_n(list.begin(), 10000,[&distribution, &generator](){
        return distribution(generator);});
    {
        Timer<nanoseconds> t;
        t.time();
        forwardList.sort();
    }
    {
        Timer<nanoseconds> t;
        t.time();
        list.sort();
    }
*/
    return 0;
}

