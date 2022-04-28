#ifndef LAB9_SPARCE_ARRAY_HPP_
#define LAB9_SPARCE_ARRAY_HPP_

#include <algorithm>
#include <concepts>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <unordered_map>

namespace lab9 {

template <std::default_initializable T>
class SparceArray : public std::unordered_map<std::size_t, T> {
public:
    using key_t = std::size_t;
    using std::unordered_map<key_t, T>::unordered_map;

    SparceArray operator()(key_t l, key_t r) const
    {
        if (l > r) {
            throw std::range_error("SparceArray::operator()");
        }
        auto res = SparceArray();
        std::ranges::copy_if(*this, std::inserter(res, res.end()), [&l, &r](auto x) { return x.first >= l && x.first <= r; });
        return res;
    }

    friend std::ostream& operator<<(std::ostream& out, const SparceArray& arr)
    {
        std::string delimeter = " ";
        out << '{';
        for (auto&& [key, value] : arr) {
            out << delimeter << key << ":" << value;
            delimeter = ", ";
        }
        out << " }";
        return out;
    }
};

}; // lab9

#endif // LAB9_SPARCE_ARRAY_HPP_
