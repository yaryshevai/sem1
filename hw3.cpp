#include <algorithm>
#include <chrono>
#include <iostream>
#include <iterator>
#include <numeric>
#include <random>


#define RANGE(container) std::begin(container), std::end(container)

bool IsOdd(int i){return ((i%2)==1);}

constexpr auto Prime(unsigned number){
    unsigned n = number;
    if(n == 1){return false;}
    for(unsigned i = 2u; i <= number / 2;){
        if(n % i == 0){
            return false;
        }
        else i += 1;
    }
    return true;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& vector) {
    std::copy(std::begin(vector), std::prev(std::end(vector)),
              std::ostream_iterator<T>(out, ", "));
    return out << *std::prev(std::end(vector)) ;
}


int main(){
    std::vector<int> numbers(10);
    //ex 1
    std::iota(RANGE(numbers), 1);
    std::cout<< "1) " << numbers << std::endl;
    //ex 2
    int num1,num2;
    std::cout << "Enter numbers" << std::endl;
    std::cin >> num1 >> num2;
    numbers.emplace_back(num1);
    numbers.emplace_back(num2);
    std::cout<< "2) " << numbers << std::endl;
    //ex 3
    std::random_shuffle(RANGE(numbers));
    std::cout<< "3) " << numbers << std::endl;
    //ex4
    std::sort(RANGE(numbers));
    numbers.erase(std::unique(RANGE(numbers)),std::end(numbers));
    std::cout<< "4) "<< numbers << std::endl;
    //ex5
    std::cout<< "5) "<<std::count_if(RANGE(numbers),IsOdd) << std::endl;
    //ex6
    std::cout<< "6) " <<*std::min_element(RANGE(numbers))<<" "<<*std::max_element(RANGE(numbers))<<std::endl;
    //ex7
    std::cout<< "7) "<< *find_if(RANGE(numbers),Prime) << std::endl;
    //ex8
    std::vector<int> squares;
    std::transform(RANGE(numbers), std::begin(numbers),[](auto number) {return number*number;});
    std::cout<< "8) "<< numbers << std::endl;
    //ex9
    auto current_timestamp = std::chrono::steady_clock::now().time_since_epoch().count();
    auto generator = std::mt19937_64(current_timestamp);
    auto distribution = std::uniform_int_distribution(1, 100);
    std::vector<int> numbers2;
    std::generate_n(std::back_inserter(numbers2), std::size(numbers), [&distribution, &generator](){return distribution(generator);});
    std::cout << "9) " << numbers2 << std::endl;
    //ex10
    std::cout << "10) " << std::accumulate(RANGE(numbers2),0) << std::endl;
    //ex11
    std::replace_if(numbers2.begin(), std::next(numbers2.begin(),3),[](auto number){return number;},1);
    std::cout << "11) " << numbers2 << std::endl;
    //ex12
    std::vector<int> numbers3;
    std::transform(RANGE(numbers), std::begin(numbers2), std::back_inserter(numbers3), [](auto lhs, auto rhs) {return lhs-rhs;});
    std::cout << "12) " << numbers3 << std::endl;
    //ex13
    std::replace_if(RANGE(numbers3),[](auto number){return number<0;}, 0);
    std::cout << "13) " << numbers3 << std::endl;
    //ex14
    numbers3.erase(std::remove_if(RANGE(numbers3),[](auto number){return number==0;}),std::end(numbers3));
    std::cout << "14) " << numbers3 << std::endl;
    //ex15
    std::reverse(RANGE(numbers3));
    std::cout << "15) " << numbers3 << std::endl;
    //ex16
    std::vector<int> copy;
    //не думаю, что это то, что подразумевалось в задании :(((
    std::copy(RANGE(numbers3),std::back_inserter(copy));
    std::sort(RANGE(copy), [](int lhs, int rhs) {return lhs>rhs;});
    std::cout << "16) " << copy[0] <<" "<< copy[1] << " " << copy[2] <<std::endl;
    //ex17
    std::sort(RANGE(numbers));
    std::sort(RANGE(numbers2));
    std::cout << "17) " << numbers << std::endl<< numbers2 << std::endl;
    //ex18
    std::vector<int> numbers4;
    std::merge(RANGE(numbers), RANGE(numbers2), std::back_inserter(numbers4));
    std::cout << "18) " << numbers4 << std::endl;
    //ex19
    auto distance = std::distance(std::find_if(RANGE(numbers4),[](auto number){return number>0;}),std::find_if(RANGE(numbers4),[](auto number){return number>1;}));
    std::cout << "19) " << distance << std::endl;
    //ex20
    std::cout << "20) " << numbers << std::endl<< numbers2 << std::endl;
    std::cout << numbers3 << std::endl<< numbers4 << std::endl;
    return 0;
}