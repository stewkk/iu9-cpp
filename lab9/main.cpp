#include "sparce_array.hpp"

#include <iostream>

int main()
{
    {
        struct T {
            T() = delete;
        };
        /* constraints not satisfied: default_initializable */
        /* lab9::SparceArray<T> arr; */
    }
    {
        lab9::SparceArray<std::string> arr = {
            { 0, "a" },
            { 2, "b" },
            { 4, "c" },
            { 5, "d" },
            { 6, "e" },
            { 7, "f" },
        };

        auto subarr = arr(3, 6);
        std::cout << arr << '\n'
                  << subarr << '\n';

        /* range_error */
        /* auto subarr2 = arr(6, 5); */

        /* OK */
        auto subarr3 = arr(10, 20);
        std::cout << subarr3 << '\n';

        std::cout << (subarr == arr) << ' ' << (arr != arr) << '\n';
    }
    return 0;
}
