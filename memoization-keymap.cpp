
#include <iostream>
#include <unordered_map>
#include <chrono>

// Memoization cache
std::unordered_map<std::string, int> cache;

// Function to add a key-value pair to the cache
void addToCache(const std::string& key, int value) 
{
    auto start = std::chrono::high_resolution_clock::now();
    cache[key] = value;
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    std::cout << "Time taken to add key-value pair: " << duration << " ms" << std::endl;
}

// Function to delete a key-value pair from the cache
void deleteFromCache(const std::string& key) 
{
    auto start = std::chrono::high_resolution_clock::now();
    cache.erase(key);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    std::cout << "Time taken to delete key-value pair: " << duration << " ms" << std::endl;
}

// Function to display the cache
void displayCache() 
{
    auto start = std::chrono::high_resolution_clock::now();
    for (const auto& pair : cache) 
    {
        std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    std::cout << "Time taken to display cache: " << duration << " ms" << std::endl;
}

int main() 
{
    addToCache("key1", 10);
    addToCache("key2", 20);
    addToCache("key3", 30);
    displayCache();
    deleteFromCache("key2");
    displayCache();

    return 0;
}
