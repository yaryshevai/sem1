#include <array>
#include <chrono>
#include <deque>
#include <iostream>
#include<forward_list>
#include <list>
#include <random>
#include <vector>

using namespace std::chrono;

template <typename T>
class Timer{
public:
    Timer(): start(steady_clock::now()) {}
    ~Timer() {
        std::cout << "duration is " <<
                  duration_cast<T>(steady_clock::now() - start).count()
                  << std::endl;
    }

private:
    steady_clock::time_point start;
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
        std::cout<<"Vector_";
        Timer<microseconds> t;
        std::sort(vector.begin(), vector.end());
    }

    std::array<int,100000> array{};
    std::generate_n(array.begin(), 100000,[&distribution, &generator](){
        return distribution(generator);
    });
    {
        std::cout<<"Array_";
        Timer<microseconds> t1;
        std::sort(array.begin(), array.end());
    }

    std::deque<int> deque;
    std::generate_n(std::back_inserter(deque), 100000,[&distribution, &generator](){
        return distribution(generator);
    });
    {
        std::cout<<"Deque_";
        Timer<microseconds> t2;
        std::sort(deque.begin(), deque.end());
    }

    std::forward_list<int> forwardList;
    std::generate_n(std::front_inserter(forwardList), 100000,[&distribution, &generator](){
        return distribution(generator);});
    {
        std::cout<<"Forward_list_";
        Timer<microseconds> t3;
        forwardList.sort();
    }

    std::list<int> list;
    std::generate_n(std::front_inserter(list), 100000,
                    [&distribution, &generator](){
                        return distribution(generator);});
    {
        std::cout<<"List_";
        Timer<microseconds> t4;
        list.sort();
    }

    return 0;
}