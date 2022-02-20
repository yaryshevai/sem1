#include <iostream>
#include <chrono>
#include <random>
#include <map>

std::multimap<std::string, int> phonebook;
void show_phonebook(){
    for(const auto& [surname, phone]: phonebook) {
        std::cout << surname << ": " << phone << std::endl;
    }
}
void search_by_surname(std::string surname)
{
    auto something =phonebook.find(surname);
    std::cout << something->second << std::endl;
}

int get_random_number(int max){
    auto current_timestamp = std::chrono::steady_clock::now().time_since_epoch().count();
    auto generator = std::mt19937_64(current_timestamp);
    auto distribution = std::uniform_int_distribution(0, max-1);
    return distribution(generator);
}
void get_random(){
    auto it = phonebook.begin();
    int size = phonebook.size();
    int number = get_random_number(size);
    auto something = std::next(it,number);
    std::cout <<something->first<<": "<<something->second << std::endl;
}


int main(){
    phonebook.emplace("Man1", 1);
    phonebook.emplace("Man2", 2);
    phonebook.emplace("Man3", 3);
    phonebook.emplace("Man4", 4);
    phonebook.emplace("Man5", 5);
    phonebook.emplace("Man6", 6);
    phonebook.emplace("Yarysheva",7);
    phonebook.emplace("Yaryshev", 13);

    show_phonebook();
    search_by_surname("Man1");
    search_by_surname("Yarysheva");
    get_random();

    return 0;
}