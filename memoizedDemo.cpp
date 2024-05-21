
#include <iostream>
#include <cmath>
#include <chrono>

// Non-memoized function
double deg2rad(double deg) 
{
    return deg * M_PI / 180.0;
}

double rad2deg(double rad) 
{
    return rad * 180.0 / M_PI;
}

// Memoized functions
double memoized_deg2rad(double deg, std::unordered_map<double, double>& memo) 
{
    auto it = memo.find(deg);
    if (it != memo.end()) 
    {
        return it->second;
    }
    double rad = deg * M_PI / 180.0;
    memo[deg] = rad;
    return rad;
}

double memoized_rad2deg(double rad, std::unordered_map<double, double>& memo) 
{
    auto it = memo.find(rad);
    if (it != memo.end()) 
    {
        return it->second;
    }
    double deg = rad * 180.0 / M_PI;
    memo[rad] = deg;
    return deg;
}

int main() 
{
    double deg = 45.0;
    double rad = M_PI / 4.0;

    // Non-memoized
    auto start = std::chrono::high_resolution_clock::now();
    double rad_non_memo = deg2rad(deg);
    double deg_non_memo = rad2deg(rad);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration_non_memo = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

    std::cout << "Non-memoized:\n";
    std::cout << deg << " degrees = " << rad_non_memo << " radians\n";
    std::cout << rad << " radians = " << deg_non_memo << " degrees\n";
    std::cout << "Time taken (non-memoized): " << duration_non_memo << " ns\n\n";

    // Memoized
    std::unordered_map<double, double> memo_deg2rad, memo_rad2deg;
    start = std::chrono::high_resolution_clock::now();
    double rad_memo = memoized_deg2rad(deg, memo_deg2rad);
    double deg_memo = memoized_rad2deg(rad, memo_rad2deg);
    end = std::chrono::high_resolution_clock::now();
    auto duration_memo = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

    std::cout << "Memoized:\n";
    std::cout << deg << " degrees = " << rad_memo << " radians\n";
    std::cout << rad << " radians = " << deg_memo << " degrees\n";
    std::cout << "Time taken (memoized): " << duration_memo << " ns\n";

    return 0;
}
