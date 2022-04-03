#include "polinom.h"

#include <algorithm>
#include <sstream>
#include <string>

Polinom::Polinom()
{
    data[0] = 0;
}

Polinom::Polinom(std::initializer_list<data_type> arr)
    : sz(arr.size())
    , data(std::make_unique<data_type[]>(sz))
{
    if (sz == 0) {
        sz = 1;
        data = std::make_unique<data_type[]>(1);
        data[0] = 0;
    }
    std::copy(arr.begin(), arr.end(), data.get());
}

Polinom::Polinom(size_t n)
    : sz(n)
    , data(std::make_unique<data_type[]>(sz))
{
    std::fill(this->begin(), this->end(), data_type {});
}

Polinom::Polinom(const Polinom& p)
    : sz(p.size())
    , data(std::make_unique<data_type[]>(sz))
{
    std::copy(p.begin(), p.end(), this->begin());
}

Polinom&
Polinom::operator=(const Polinom& p)
{
    sz = p.size();
    data = std::make_unique<data_type[]>(sz);
    std::copy(p.begin(), p.end(), this->begin());
    return *this;
}

std::string
Polinom::toString() const
{
    std::stringstream res;
    std::uint32_t unknown_counter = 0;
    for (const auto& el : *this) {
        if (!el) {
            res << 'x' << std::to_string(unknown_counter) << ' ';
            unknown_counter++;
            continue;
        }
        res << std::to_string(*el) << ' ';
    }
    return res.str();
}

Polinom::data_type*
Polinom::begin() const
{
    return data.get();
}

Polinom::data_type*
Polinom::end() const
{
    return data.get() + sz;
}

size_t
Polinom::size() const
{
    return sz;
}

bool Polinom::isDefined(size_t i) const
{
    return data[i].has_value();
}

Polinom::coefficient_type&
Polinom::operator[](size_t i)
{
    if (!data[i]) {
        data[i] = 0;
    }
    return *data[i];
}

Polinom
Polinom::differentiate() const
{
    if (sz == 1) {
        return Polinom();
    }
    Polinom res(sz - 1);
    for (size_t i = 1; i < sz; ++i) {
        if (!data[i]) {
            res.data[i - 1] = UNKNOWN;
            continue;
        }
        res.data[i - 1] = *data[i] * i;
    }
    return res;
}

std::ostream& operator<<(std::ostream& out, const Polinom& p) {
    std::uint32_t unknown_counter = 0;
    for (const auto& el : p) {
        if (!el) {
            out << 'x' << std::to_string(unknown_counter) << ' ';
            unknown_counter++;
            continue;
        }
        out << *el << ' ';
    }
    return out;
}
