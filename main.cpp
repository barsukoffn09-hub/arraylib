#include <iostream>
#include <algorithm>
#include <cstddef>
#include <vector>
#include "arraylib.h"
using namespace std;

int main() {
    int data[]={5, 3,8, 1, 9, 2};
    size_t n=sizeof(data)/sizeof(data[0]);
    cout << "Sum: " << arr_sum(data, n) << '\n';
    cout << "Max: " << arr_max(data, n) << '\n';
    cout << "Min: " << arr_min(data, n) << '\n';
    cout << "Average: " << arr_average(data, n) << '\n';
    cout << "Positive: " << arr_count_positive(data, n) << '\n';
    cout << "Negative: " << arr_count_negative(data, n) << '\n';
    cout << "Zeros: " << arr_count_zero(data, n) << '\n';
    cout << "Product: " << arr_product(data, n) << '\n';
    cout << "Median: " << arr_median(data, n) << '\n';
    return 0;
}