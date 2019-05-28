
#include "BinarySearchDeluxe.h"

template<typename Func>
int BinarySearchDeluxe::first_index_of(Term const terms[], size_t size, const Term &key, Func comparator)
{
    Term const *first_ptr = std::lower_bound(terms, terms + size, key, comparator);
    return static_cast<int>(first_ptr - terms);
}


template<typename Func>
int BinarySearchDeluxe::last_index_of(Term const terms[], size_t size, const Term &key, Func comparator)
{
    Term const *last_ptr = std::upper_bound(terms, terms + size, key, comparator);
    return static_cast<int>(last_ptr - terms);
}