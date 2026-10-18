
#include "arraylib.h"
#include <cstddef>
#include <iomanip>
#include <iostream>
int main() {
    int scores[] = {72, 85, 91, 64, 78, 88, 95, 69, 84, 76};
    const std::size_t n = sizeof(scores) / sizeof(scores[0]);
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Results: ";
    for (std::size_t i = 0; i < n; ++i) {
        std::cout << scores[i] << ' ';
    }
    std::cout << '\n';
    std::cout << "Average score: " << arr_average(scores, n) << '\n';
    std::cout << "Maximum score: " << arr_max(scores, n) << '\n';
    std::cout << "Minimum score: " << arr_min(scores, n) << '\n';
    std::size_t count = 0;
    for (std::size_t i = 0; i < n; ++i) {
        if (scores[i] >= 80) {
            ++count;
        }
    }
    std::cout << "Scores not lower than 80: " << count << '\n';
    std::cout << "Median score: " << arr_median(scores, n) << '\n';
    return 0;
}
