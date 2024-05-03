#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <functional>
#include <random>

template<typename T>
void bubbleSort(std::vector<T>& arr, std::function<bool(const T&, const T&)> compare = std::less<T>()) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (compare(arr[j + 1], arr[j])) {
                std::swap(arr[j], arr[j + 1]);

                // Visualization with ASCII art and colors
                system("clear");
                std::cout << "\033[1;36m"; // Cyan color
                std::cout << "Sorting in progress:\n";
                for (const T& val : arr) {
                    std::cout << "\033[1;33m"; // Yellow color
                    for (int k = 0; k < val; ++k) {
                        std::cout << u8"\u2588"; // Unicode block character
                    }
                    std::cout << " ";
                }
                std::cout << "\033[0m"; // Reset color
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
            }
        }
    }
}

std::vector<int> generateRandomIntegers(int size, int min, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min, max);

    std::vector<int> randomNumbers(size);
    for (int& num : randomNumbers) {
        num = dis(gen);
    }
    return randomNumbers;
}

int main() {
    int size = 10;
    std::vector<int> nums = generateRandomIntegers(size, 1, 100);

    std::cout << "\033[1;36m"; // Cyan color
    std::cout << "Original array:\n";
    for (int val : nums) {
        std::cout << "\033[1;33m"; // Yellow color
        for (int i = 0; i < val; ++i) {
            std::cout << u8"\u2588"; // Unicode block character
        }
        std::cout << " ";
    }
    std::cout << std::endl;

    bubbleSort(nums);

    std::cout << "\033[1;36m"; // Cyan color
    std::cout << "\nSorted array (ascending order):\n";
    for (int val : nums) {
        std::cout << "\033[1;33m"; // Yellow color
        for (int i = 0; i < val; ++i) {
            std::cout << u8"\u2588"; // Unicode block character
        }
        std::cout << " ";
    }
    std::cout << std::endl;

    bubbleSort(nums, std::greater<int>());

    std::cout << "\033[1;36m"; // Cyan color
    std::cout << "\nSorted array (descending order):\n";
    for (int val : nums) {
        std::cout << "\033[1;33m"; // Yellow color
        for (int i = 0; i < val; ++i) {
            std::cout << u8"\u2588"; // Unicode block character
        }
        std::cout << " ";
    }
    std::cout << std::endl;

    return 0;
}
