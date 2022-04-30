#include "set_sequence.hpp"

#include <iostream>

int main()
{
    lab10::SetSeq<int> test { { 1, 2, 3 }, { 3, 4, 5 }, { 4 }, { 1, 2, 3 }, { 1 } };
    std::cout << "intersections:\n";
    for (auto& intersection : test) {
        for (auto& el : intersection) {
            std::cout << el << ' ';
        }
        std::cout << '\n';
    }
    std::cout << "test[1]: ";
    for (auto& el : (std::set<int>)test[1]) {
        std::cout << el << ' ';
    }
    std::cout << '\n';

    test[1].insert(2);

    std::cout << "test[1], after insert(2): ";
    for (auto& el : (std::set<int>)test[1]) {
        std::cout << el << ' ';
    }
    std::cout << '\n';

    std::cout << "intersections:\n";
    for (auto& intersection : test) {
        for (auto& el : intersection) {
            std::cout << el << ' ';
        }
        std::cout << '\n';
    }
    return 0;
}
