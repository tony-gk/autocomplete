#include "Autocomplete.h"

Autocomplete::Autocomplete() : terms_(nullptr), size_(0), bsd_(BinarySearchDeluxe::instance())
{};

Autocomplete::Autocomplete(Term const *terms, size_t size) : size_(size), bsd_(BinarySearchDeluxe::instance())
{
    terms_ = new Term[size_];
    for (size_t i = 0; i < size_; ++i)
        terms_[i] = terms[i];
    std::sort(terms_, terms_ + size_);
}

Autocomplete::~Autocomplete()
{
    delete[]terms_;
}

Autocomplete::Autocomplete(Autocomplete const &other) : Autocomplete(other.terms_, other.size_)
{}

Autocomplete &Autocomplete::operator=(Autocomplete const &other)
{
    Autocomplete tmp(other);
    std::swap(tmp.terms_, terms_);
    std::swap(tmp.size_, size_);
    return *this;
}

Term *Autocomplete::all_matches(std::string const &prefix)
{
    auto[left, right] = get_bounds(prefix);
    Term *matches = new Term[right - left];
    for (size_t i = left; i < right; ++i)
        matches[i - left] = terms_[i];
    std::sort(matches, matches + right - left, Term::by_reverse_weight_order());
    return matches;
}

int Autocomplete::number_of_matches(std::string const &prefix)
{
    auto[left, right] = get_bounds(prefix);
    return right - left;
}

std::pair<int, int> Autocomplete::get_bounds(std::string const &prefix)
{
    auto cmp_by_prefix = Term::by_prefix_order(prefix.size());
    Term key(prefix, 0);
    int left = bsd_.first_index_of(terms_, size_, key, cmp_by_prefix);
    int right = bsd_.last_index_of(terms_, size_, key, cmp_by_prefix);
    return {left, right};
}
