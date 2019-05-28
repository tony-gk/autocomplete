#pragma once

#include "Term.h"
#include "BinarySearchDeluxe.h"

#include <algorithm>

class Autocomplete
{
public:
    Autocomplete();

    Autocomplete(Term const *terms, size_t size);

    ~Autocomplete();

    Autocomplete(Autocomplete const &other);

    Autocomplete &operator=(Autocomplete const &other);

    Term *all_matches(std::string const &prefix);

    int number_of_matches(std::string const &prefix);

private:

    std::pair<int, int> get_bounds(std::string const &prefix);

    Term *terms_;
    size_t size_;
    BinarySearchDeluxe &bsd_;
};