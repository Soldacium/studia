#include <iostream>
#include <math.h>
using namespace std;

struct simple_compare {
    template <typename A, typename B>
    bool operator()(A const& a, B const& b) const {
        return a > b;
    }
};

template <typename T, typename Predicate = simple_compare>
bool compare(T a, T b, Predicate pred = {}) {
    return pred(a, b);
}