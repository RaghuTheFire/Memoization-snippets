
#include <iostream>
#include <string>
#include <unordered_map>
#include <chrono>

std::unordered_map<int, std::string> memo;

std::string getMemoizedString(const std::string arr[], int index) 
{
    if (memo.count(index)) 
    {
        return memo[index];
    }
    memo[index] = arr[index];
    return memo[index];
}

int main() 
{
    std::string arr[] = {"apple", "banana", "cherry", "date", "elderberry"};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Access without memoization
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < n; i++) 
    {
        std::string str = arr[i];
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    std::cout << "Time taken without memoization: " << duration << " ms" << std::endl;

    // Access with memoization
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < n; i++) 
    {
        std::string str = getMemoizedString(arr, i);
    }
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    std::cout << "Time taken with memoization: " << duration << " ms" << std::endl;

    return 0;
}
