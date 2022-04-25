#ifndef LAB10_SET_SEQUENCE_HPP_
#define LAB10_SET_SEQUENCE_HPP_

#include <algorithm>
#include <iterator>
#include <ranges>
#include <set>
#include <vector>

namespace lab10 {
template <typename T, typename Container = std::vector<std::set<T>>>
class SetSeq {
public:
    using container_type = Container;
    using value_type = typename Container::value_type;
    using size_type = typename Container::size_type;
    using const_reference = typename Container::const_reference;
    using const_iterator = typename Container::const_iterator;

private:
    container_type seq = container_type();
    container_type pairsIntersecions = container_type();

private:
    void calcIntersections()
    {
        std::ranges::transform(seq | std::ranges::views::take(seq.size() - 1),
            seq | std::ranges::views::drop(1),
            std::back_inserter(pairsIntersecions),
            [](const auto& a, const auto& b) {
                value_type res;
                std::ranges::set_intersection(a, b, std::inserter(res, res.end()));
                return res;
            });
    }

public:
    SetSeq() = default;
    explicit SetSeq(const container_type& cont)
        : seq(cont)
    {
        calcIntersections();
    }
    explicit SetSeq(container_type&& cont)
        : seq(std::move(cont))
    {
        calcIntersections();
    }
    SetSeq(const SetSeq& other) = default;
    SetSeq(SetSeq&& other) = default;
    SetSeq& operator=(const SetSeq& other) = default;
    SetSeq& operator=(SetSeq&& other) = default;
    SetSeq(std::initializer_list<value_type> init)
        : seq(init)
    {
        calcIntersections();
    }

    auto size() const noexcept
    {
        return seq.size();
    }

    const_iterator cbegin() noexcept
    {
        return seq.cbegin();
    }
    const_iterator cend() noexcept
    {
        return seq.cend();
    }

    const_iterator cbeginIntersections() const noexcept
    {
        return pairsIntersecions.cbegin();
    }
    const_iterator cendIntersections() const noexcept
    {
        return pairsIntersecions.cend();
    }

    const_reference operator[](size_type pos) const
    {
        return seq[pos];
    }
};

}; // lab10

#endif // LAB10_SET_SEQUENCE_HPP_
