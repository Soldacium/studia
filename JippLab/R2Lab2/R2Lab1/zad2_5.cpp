#include <iostream>
#include <math.h>
using namespace std;

template<typename T, typename U>
auto subtract(T t, U u) -> decltype(t + u) {
    return t - u;
}