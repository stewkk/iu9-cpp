#ifndef LAB9_SPARCE_ARRAY_HPP_
#define LAB9_SPARCE_ARRAY_HPP_

#include <concepts>
#include <iostream>
#include <ranges>
#include <stdexcept>
#include <unordered_map>

namespace lab9 {

template <std::default_initializable T>
class SparceArray;

template <std::default_initializable T>
bool operator==(const SparceArray<T>& lhs, const SparceArray<T>& rhs);

template <std::default_initializable T>
std::ostream& operator<<(std::ostream& out, const SparceArray<T>& arr);

template <std::default_initializable T>
class SparceArray {
public:
    using key_t = std::size_t;
    using container_t = std::unordered_map<key_t, T>;

private:
    container_t map;

public:
    SparceArray() = default;
    SparceArray(const container_t&);

    T& operator[](std::size_t idx);
    const T& operator[](std::size_t idx) const;
    SparceArray operator()(key_t l, key_t r) const;

    friend bool operator==<>(const SparceArray& lhs, const SparceArray& rhs);
    friend std::ostream& operator<<<>(std::ostream& out, const SparceArray& arr);
};

template <std::default_initializable T>
using key_t = typename SparceArray<T>::key_t;

template <std::default_initializable T>
using container_t = typename SparceArray<T>::container_t;

template <std::default_initializable T>
SparceArray<T>::SparceArray(const container_t& inputMap)
    : map(inputMap)
{
}

template <std::default_initializable T>
T& SparceArray<T>::operator[](std::size_t idx)
{
    return map[idx];
}

template <std::default_initializable T>
const T& SparceArray<T>::operator[](std::size_t idx) const
{
    return map[idx];
}

template <std::default_initializable T>
SparceArray<T> SparceArray<T>::operator()(key_t l, key_t r) const
{
    if (l > r) {
        throw std::range_error("SparceArray<T>::operator()");
    }
    auto elems = map | std::views::filter([&l, &r](const auto& el) -> bool { return el.first >= l && el.first <= r; });
    return container_t(std::ranges::begin(elems), std::ranges::end(elems));
}

template <std::default_initializable T>
bool operator==(const SparceArray<T>& lhs, const SparceArray<T>& rhs)
{
    return lhs.map == rhs.map;
}

template <std::default_initializable T>
std::ostream& operator<<(std::ostream& out, const SparceArray<T>& arr)
{
    std::string delimeter = " ";
    out << '{';
    for (auto&& [key, value] : arr.map) {
        out << delimeter << key << ":" << value;
        delimeter = ", ";
    }
    out << " }";
    return out;
}

}; // lab9

#endif // LAB9_SPARCE_ARRAY_HPP_
