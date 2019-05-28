#pragma once

#include <utility>
#include <string>

class Term
{
public:
    Term();

    Term(std::string term, size_t weight);

    Term(const Term &t) = default;

    Term &operator=(const Term &t) = default;

    Term(Term &&t) = default;

    Term &operator=(Term &&t) = default;

    bool operator<(const Term &t) const;

    bool operator>(const Term &t) const;


    bool operator==(const Term &t) const;

    bool operator!=(const Term &t) const;

    std::string to_string() const;

    struct WeightFunctor
    {
        bool operator()(const Term &lhs, const Term &rhs);
    };

    struct PrefixFunctor
    {
        explicit PrefixFunctor(size_t len);

        bool operator()(const Term &lhs, const Term &rhs);

    private:
        size_t prefix_len;
    };

    static WeightFunctor by_reverse_weight_order()
    {
        return WeightFunctor();
    }

    static PrefixFunctor by_prefix_order(size_t len)
    {
        return PrefixFunctor(len);
    }

private:
    std::string term_str_;
    size_t weight_;
};