#include "polinom.h"

#include <iostream>

int main()
{
    {
        Polinom test({ 5, 3, 2, {}, Polinom::UNKNOWN, 2 });
        std::cout << test.toString() << std::endl;
    }
    std::cout << std::endl;
    {
        Polinom test;
        std::cout << test.toString() << std::endl;
    }
    std::cout << std::endl;
    {
        Polinom test({ 5, 3, 2, {}, Polinom::UNKNOWN, 2 });
        Polinom test2({ 1, 2, 3 });
        test = test2;
        std::cout << test.toString() << std::endl;
        std::cout << test2.toString() << std::endl;
    }
    std::cout << std::endl;
    {
        auto func = [](Polinom test) { std::cout << test.toString() << std::endl; };
        Polinom test({ 5, 3, 2, {}, Polinom::UNKNOWN, 2 });
        func(test);
    }
    std::cout << std::endl;
    {
        Polinom test({ 5, 3, 2, {}, Polinom::UNKNOWN, 2 });
        std::cout << test.isDefined(0) << ' ' << test[0] << std::endl;
        std::cout << test.isDefined(3) << ' ' << test[3] << std::endl;
        std::cout << test.toString() << std::endl;
    }
    std::cout << std::endl;
    {
        Polinom test({ 5, 3, 2, {}, Polinom::UNKNOWN, 2 });
        size_t end = test.size();
        for (size_t i = 0; i <= end; ++i) {
            std::cout << test.toString() << std::endl;
            test = test.differentiate();
        }
    }
    return 0;
}
