
#include <iostream>
#include <vector>
#include <unordered_map>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Function to access multidimensional array without memoization
int accessArray(vector<vector<int>>& arr, int i, int j) 
{
    return arr[i][j];
}

// Function to access multidimensional array with memoization
int accessArrayMemoized(vector<vector<int>>& arr, int i, int j, unordered_map<string, int>& memo) 
{
    string key = to_string(i) + "," + to_string(j);
    if (memo.count(key)) {
        return memo[key];
    }
    int value = arr[i][j];
    memo[key] = value;
    return value;
}

int main() 
{
    // Create a large multidimensional array
    int n = 1000;
    vector<vector<int>> arr(n, vector<int>(n, 0));

    // Initialize the array with some values
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            arr[i][j] = i * j;
        }
    }

    // Access array without memoization
    auto start = high_resolution_clock::now();
    int sum = 0;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            sum += accessArray(arr, i, j);
        }
    }
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start).count();
    cout << "Time taken without memoization: " << duration << " ms" << endl;

    // Access array with memoization
    unordered_map<string, int> memo;
    start = high_resolution_clock::now();
    sum = 0;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            sum += accessArrayMemoized(arr, i, j, memo);
        }
    }
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start).count();
    cout << "Time taken with memoization: " << duration << " ms" << endl;

    return 0;
}
