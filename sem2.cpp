#include <iostream>
#include <vector>
#include <list>

struct Fraction{
    int numerator;
    unsigned denominator;

    Fraction(int numerator, unsigned int denominator) : numerator(numerator), denominator(denominator) {}
};

int main(){
std::vector<Fraction> fractions;
fractions.emplace_back(1, 2);
std::list<int> numbers {1,2,3,4};
std::list<int> other_numbers{-1,-2,-3,-4};
numbers.splice(std::next(std::begin(other_numbers),2), other_numbers, std::prev(std::end(other_numbers)));
for (auto number: numbers){
    std::cout<<number<<' ';
}
return 0;
}