#ifndef LAB7_POLINOM_H_
#define LAB7_POLINOM_H_

#include <cstdint>
#include <memory>
#include <optional>

class Polinom {
public:
    using coefficient_type = std::int32_t;
    using data_type = std::optional<coefficient_type>;
    constexpr static data_type UNKNOWN = std::nullopt;

    Polinom();
    Polinom(std::initializer_list<data_type>);
    explicit Polinom(size_t);

    Polinom(const Polinom&);
    Polinom& operator=(const Polinom&);

    Polinom(Polinom&&) = default;
    Polinom& operator=(Polinom&&) = default;

    virtual ~Polinom() = default;

    std::string toString() const;
    size_t size() const;
    data_type* begin() const;
    data_type* end() const;

    bool isDefined(size_t i) const;
    coefficient_type& operator[](size_t i);
    Polinom differentiate() const;

private:
    size_t sz = 1;
    std::unique_ptr<data_type[]> data = std::make_unique<data_type[]>(1);
};

#endif // LAB7_POLINOM_H_
