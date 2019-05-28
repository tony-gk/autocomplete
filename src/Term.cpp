
#include "Term.h"

Term::Term() : term_str_(""), weight_(0)
{}

Term::Term(std::string term, size_t weight) : term_str_(std::move((term))), weight_(weight)
{}

bool Term::operator<(const Term &t) const
{
    return term_str_ < t.term_str_;
}

bool Term::operator>(const Term &t) const
{
    return term_str_ > t.term_str_;
}

bool Term::operator==(const Term &t) const
{
    return term_str_ == t.term_str_;
}

bool Term::operator!=(const Term &t) const
{
    return term_str_ != t.term_str_;
}

std::string Term::to_string() const
{
    return std::to_string(weight_) + " " + term_str_;
}

std::ostream &operator<<(std::ostream &os, const Term &t)
{
    os << t.to_string();
    return os;
}

bool Term::WeightFunctor::operator()(const Term &lhs, const Term &rhs)
{
    return lhs.weight_ > rhs.weight_;
}

Term::PrefixFunctor::PrefixFunctor(size_t len) : prefix_len(len)
{}

bool Term::PrefixFunctor::operator()(const Term &lhs, const Term &rhs)
{
    return lhs.term_str_.compare(0, prefix_len, rhs.term_str_, 0, prefix_len) < 0;
}
