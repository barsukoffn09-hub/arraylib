#include "arraylib.h"
#include <algorithm>
#include <vector>
using namespace std;
int arr_sum(const int* arr, size_t n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}
int arr_max(const int* arr, size_t n) {
    int max=arr[0];
    for (size_t i =1; i<n; ++i) {
        if (arr[i]>max) {
            max=arr[i];
        }
    }
    return max;
}
int arr_min(const int* arr, size_t n) {
    int min=arr[0];
    for (size_t i=1; i<n; ++i) {
        if (arr[i]<min) {
            min=arr[i];
        }
    }
    return min;
}
double arr_average(const int* arr, size_t n) {
    return static_cast<double>(arr_sum(arr, n)) / n;
}
int arr_count_positive(const int* arr, size_t n) {
    int count=0;
    for (size_t i=0; i<n; ++i) {
        if (arr[i]>0) {
            ++count;
        }
    }
    return count;
}
int arr_count_negative(const int* arr, size_t n) {
    int count=0;
    for (size_t i=0; i<n; ++i) {
        if (arr[i]<0) {
            ++count;
        }
    }
    return count;
}

int arr_count_zero(const int* arr, size_t n) {
    int count=0;
    for (size_t i=0; i<n; ++i) {
        if (arr[i]==0) {
            ++count;
        }
    }
    return count;
}
int arr_product(const int* arr, size_t n) {
    int product=1;
    for (size_t i=0; i<n; ++i) {
        product*=arr[i];
    }
    return product;
}
double arr_median(const int* arr, size_t n) {
    vector<int> copy(arr, arr+n);
    sort(copy.begin(), copy.end());
    if (n%2==1) {
        return static_cast<double>(copy[n/2]);
    } 
    else {
        return (static_cast<double>(copy[n/2-1]) + static_cast<double>(copy[n/2])) / 2.0;
    }
}