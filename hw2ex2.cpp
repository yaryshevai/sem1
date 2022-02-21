#include <iostream>
#include <chrono>
#include <random>
#include <map>

class phonebook {
public:
    phonebook() = default;

    virtual ~phonebook() {
    };

    const std::multimap<std::string, int> &getMap() const {
        return map;
    }

    void setMap(const std::multimap<std::string, int> &map) {
        phonebook::map = map;
    }

    void show_phonebook() {
        for (const auto&[surname, phone]: map) {
            std::cout << surname << ": " << phone << std::endl;
        }
    }

    void search_by_surname(std::string surname) {
        auto something = map.find(surname);
        std::cout << something->second << std::endl;
    }

    int get_random_number(int max) {
        auto current_timestamp = std::chrono::steady_clock::now().time_since_epoch().count();
        auto generator = std::mt19937_64(current_timestamp);
        auto distribution = std::uniform_int_distribution(0, max - 1);
        return distribution(generator);
    }

    void get_random() {
        auto it = map.begin();
        int size = map.size();
        int number = get_random_number(size);
        auto something = std::next(it, number);
        std::cout << something->first << ": " << something->second << std::endl;
    }
    void add(std::string surname, int number){
        map.emplace(surname, number);
    }

private:
    std::multimap<std::string, int> map;

};

int main(){
    phonebook ph1;
    ph1.add("Man1", 1);
    ph1.add("Man2", 2);
    ph1.add("Man3", 3);
    ph1.add("Man4", 4);
    ph1.add("Man5", 5);
    ph1.add("Man6", 6);
    ph1.add("Yarysheva",7);
    ph1.add("Yaryshev", 13);

    ph1.show_phonebook();
    ph1.search_by_surname("Man1");
    ph1.search_by_surname("Yarysheva");
    ph1.get_random();

    return 0;
}