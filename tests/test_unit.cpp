#ifndef ARRAYLIB_H
#define ARRAYLIB_H

#include <cstddef>

#if defined(_WIN32)
  #if defined(ARRAYLIB_BUILD)
    #define ARRAYLIB_API __declspec(dllexport)
  #else
    #define ARRAYLIB_API __declspec(dllimport)
  #endif
#else
  #define ARRAYLIB_API
#endif

ARRAYLIB_API int arr_sum(const int* arr, std::size_t n);
ARRAYLIB_API int arr_max(const int* arr, std::size_t n);
ARRAYLIB_API int arr_min(const int* arr, std::size_t n);
ARRAYLIB_API double arr_average(const int* arr, std::size_t n);
ARRAYLIB_API int arr_count_positive(const int* arr, std::size_t n);
ARRAYLIB_API int arr_count_negative(const int* arr, std::size_t n);
ARRAYLIB_API int arr_count_zero(const int* arr, std::size_t n);
ARRAYLIB_API int arr_product(const int* arr, std::size_t n);
ARRAYLIB_API double arr_median(const int* arr, std::size_t n);

#endif#include "arraylib.h"
#include <cassert>
#include <cmath>
#include <iostream>
static bool close(double a, double b, double eps = 1e-9) {
    return std::fabs(a - b) < eps;
}
int main() {
    int a[] = {-5, 0, 3, 3, 8, -2};
    const std::size_t n = sizeof(a) / sizeof(a[0]);
    assert(arr_sum(a, n) == 7);
    assert(arr_max(a, n) == 8);
    assert(arr_min(a, n) == -5);
    assert(arr_count_positive(a, n) == 3);
    assert(arr_count_negative(a, n) == 2);
    assert(arr_count_zero(a, n) == 1);
    assert(arr_product(a, n) == 0);
    assert(close(arr_average(a, n), 7.0 / 6.0));
    int b[] = {7, 1, 9, 3};
    assert(close(arr_median(b, 4), 5.0));
    int c[] = {5, 1, 3};
    assert(close(arr_median(c, 3), 3.0));
    int src[] = {7, 1, 9, 3};
    int src_copy[] = {7, 1, 9, 3};
    arr_median(src, 4);
    for (std::size_t i = 0; i < 4; ++i) {
        assert(src[i] == src_copy[i]);
    }
    int d[] = {1, 2, 3, 4};
    assert(arr_product(d, 4) == 24);
    std::cout << "[unit] All tests passed\n";
    return 0;
}