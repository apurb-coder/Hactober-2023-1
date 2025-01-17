/*This approach allows you to search for elements in an infinite sorted array efficiently by first finding a suitable search range.
In the problem of searching in an infinite sorted array, the challenge is that the array is infinitely long, 
so you can't use a traditional binary search method where you need to know the size of the array in advance. 
To tackle this problem, you can use an approach that first finds a range where 
the target element might exist and then performs a binary search within that range.*/

/*----------------------------------------------------------------------------------------------------------------------------------------*/
//CODE

#include <iostream>
#include <vector>

using namespace std;

// Function to perform binary search within a range [low, high]
int binarySearch(vector<int>& arr, int low, int high, int target) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid;  // Target element found
        }
        else if (arr[mid] < target) {
            low = mid + 1;  // Adjust the lower bound of the search range
        }
        else {
            high = mid - 1;  // Adjust the upper bound of the search range
        }
    }

    return -1;  // Target element not found in the range
}

// Function to search for a target element in an infinite sorted array
int searchInInfiniteArray(vector<int>& arr, int target) {
    int low = 0;
    int high = 1;

    // Find a range where the target might exist
    while (target > arr[high]) {
        low = high;
        high = 2 * high;
    }

    // Perform binary search within the determined range
    int result = binarySearch(arr, low, high, target);
    return result;
}

int main() {
    vector<int> arr = {1, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30};
    int target = 18;

    int index = searchInInfiniteArray(arr, target);

    if (index != -1) {
        cout << "Element found at index " << index << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}
/*---------------------------------------------------------------------------------------------------------------------------*/
/*
The searchInInfiniteArray function takes a sorted infinite array (arr) and a target element to search for (target).

It starts with low and high set to 0 and 1, respectively.

It increases the high value exponentially (doubling it) while the target is greater than the element at index high in the array. This narrows down 
the range where the target might exist.

Once the range is determined, it calls the binarySearch function to perform a standard binary search within that range.

The binarySearch function performs a binary search within the given range and returns the index of the target element if found, or -1 if not found.

This approach allows you to search for elements in an infinite sorted array efficiently by first finding a suitable search range.
*/
