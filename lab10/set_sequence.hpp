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
private:
    /* Последовательность множеств */
    Container seq = Container();
    /* Пересечения соседних множеств */
    Container pairsIntersections;

    /* Вычисление всех пересечений */
    void calcIntersections()
    {
        std::ranges::transform(seq | std::ranges::views::take(seq.size() - 1),
            seq | std::ranges::views::drop(1),
            std::back_inserter(pairsIntersections),
            [](const auto& a, const auto& b) {
                std::set<T> res;
                std::ranges::set_intersection(a, b, std::inserter(res, res.end()));
                return res;
            });
    }

    /* Вычисление пересечений, в которые входит множество под номером index */
    void calcIntersections(std::size_t index)
    {
        if (index != 0) {
            auto& intersection = pairsIntersections[index - 1];
            intersection.clear();
            std::ranges::set_intersection(seq[index - 1], seq[index], std::inserter(intersection, intersection.end()));
        }
        if (index != size() - 1) {
            auto& intersection = pairsIntersections[index];
            intersection.clear();
            std::ranges::set_intersection(seq[index], seq[index + 1], std::inserter(intersection, intersection.end()));
        }
    }

public:
    SetSeq() = default;

    explicit SetSeq(const Container& cont)
        : seq(cont)
    {
        calcIntersections();
    }

    explicit SetSeq(Container&& cont)
        : seq(std::move(cont))
    {
        calcIntersections();
    }

    SetSeq(const SetSeq& other) = default;
    SetSeq(SetSeq&& other) = default;
    SetSeq& operator=(const SetSeq& other) = default;
    SetSeq& operator=(SetSeq&& other) = default;

    SetSeq(std::initializer_list<std::set<T>> init)
        : seq(init)
    {
        calcIntersections();
    }

    auto size() const noexcept
    {
        return seq.size();
    }

    /* Прокси-класс для доступа к элементам последовательности */
    friend class SetProxy;

    class SetProxy {
    private:
        SetSeq& setSeq;
        std::size_t setIndex;

        std::set<T>& get() const
        {
            return setSeq.seq[setIndex];
        }

        void recalcCurrent()
        {
            setSeq.calcIntersections(setIndex);
        }

    public:
        SetProxy(SetSeq& theSetSeq, std::size_t index)
            : setSeq(theSetSeq)
            , setIndex(index)
        {
        }

        /* lvalue */
        SetProxy& operator=(const SetProxy& rhs)
        {
            this->get() = rhs.get();
            recalcCurrent();
        }
        /* lvalue */
        SetProxy& operator=(std::set<T> rhs)
        {
            this->get() = rhs;
            recalcCurrent();
        }

        /* Для rvalue */
        operator std::set<T>() const
        {
            return get();
        }

        std::pair<typename std::set<T>::iterator, bool> insert(const T& value)
        {
            auto [it, isChanged] = get().insert(value);
            if (isChanged) {
                recalcCurrent();
            }
            return { it, isChanged };
        }
    };

    /* Доступ к элементам последовательности */
    const SetProxy operator[](std::size_t index) const
    {
        return SetProxy(const_cast<SetSeq&>(*this), index);
    }
    SetProxy operator[](std::size_t index)
    {
        return SetProxy(*this, index);
    }

    typename Container::const_iterator begin()
    {
        return pairsIntersections.begin();
    }
    typename Container::const_iterator end()
    {
        return pairsIntersections.end();
    }
};

}; // lab10

#endif // LAB10_SET_SEQUENCE_HPP_
