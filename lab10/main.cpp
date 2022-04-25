#include "set_sequence.hpp"

#include <iostream>

int main()
{
    lab10::SetSeq<int> test { { 1, 2, 3 }, { 3, 4, 5 }, { 4 }, { 1, 2, 3 }, { 1 } };
    for (auto it = test.cbeginIntersections(); it != test.cendIntersections(); ++it) {
        for (auto& el : *it) {
            std::cout << el << ' ';
        }
        std::cout << '\n';
    }
    std::cout << "\ntest[1]: ";
    for (auto& el : test[1]) {
        std::cout << el << ' ';
    }
    std::cout << '\n';
    return 0;
}
