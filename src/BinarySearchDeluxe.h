#pragma once

#include <algorithm>
#include "Term.h"

class BinarySearchDeluxe
{
public:
    static BinarySearchDeluxe &instance()
    {
        static BinarySearchDeluxe bsd;
        return bsd;
    }

    template<typename Func>
    int first_index_of(Term const terms[], size_t size, const Term &key, Func comparator)
    {
        Term const *first_ptr = std::lower_bound(terms, terms + size, key, comparator);
        return std::distance(terms, first_ptr);
    }

    template<typename Func>
    int last_index_of(Term const terms[], size_t size, const Term &key, Func comparator)
    {
        Term const *last_ptr = std::upper_bound(terms, terms + size, key, comparator);
        return std::distance(terms, last_ptr);
    }

private:
    BinarySearchDeluxe() = default;

    BinarySearchDeluxe(const BinarySearchDeluxe &bsd) = default;

    BinarySearchDeluxe &operator=(const BinarySearchDeluxe &bsd) = default;

};
