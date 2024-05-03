#include <iostream>
#include <vector>
#include <chrono>
#include <thread>

// Function to perform bubble sort
void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        // Last i elements are already in place, so we don't need to compare them
        for (int j = 0; j < n - i - 1; ++j) {
            // Swap adjacent elements if they are in the wrong order
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);

                // Visualize the swapping with ASCII art and colors
                system("clear");
                std::cout << "\033[1;36m"; // Cyan color
                std::cout << "Sorting in progress:\n";
                for (int num : arr) {
                    std::cout << "\033[1;33m"; // Yellow color
                    for (int k = 0; k < num; ++k) {
                        std::cout << u8"\u2588"; // Unicode block character
                    }
                    std::cout << " ";
                }
                std::cout << "\033[0m"; // Reset color
                std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Add delay for animation
            }
        }
    }
}

int main() {
    std::vector<int> nums = {12, 7, 9, 4, 2, 15, 6};

    std::cout << "\033[1;36m"; // Cyan color
    std::cout << "Original array:\n";
    for (int num : nums) {
        std::cout << "\033[1;33m"; // Yellow color
        for (int i = 0; i < num; ++i) {
            std::cout << u8"\u2588"; // Unicode block character
        }
        std::cout << " ";
    }
    std::cout << std::endl;

    bubbleSort(nums);

    std::cout << "\033[1;36m"; // Cyan color
    std::cout << "\nSorted array:\n";
    for (int num : nums) {
        std::cout << "\033[1;33m"; // Yellow color
        for (int i = 0; i < num; ++i) {
            std::cout << u8"\u2588"; // Unicode block character
        }
        std::cout << " ";
    }
    std::cout << std::endl;

    return 0;
}
