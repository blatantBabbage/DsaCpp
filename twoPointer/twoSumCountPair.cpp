//
// Created by Singh, Nitesh on 30/03/25.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * Question : "Two Sum Pair Count"
 * Given an array of doubles, return the count pairs whose sum is less than or equal to the target number.
 */

int countPairBruteForce(const vector<double>& arr, double target)
{
    // initialize counter for counting pairs whose sum is <= target
    int count = 0;

    // loop through given array, where i is the index of the first number in pair
    for (int i = 0; i <arr.size(); i++)
    {
        // loop through all the elements after current number i, where j is the index of the second number
        for (int j = i; j < arr.size(); j++)
        {
            // check if sum is <= target
            if (arr[i] + arr[j] <= target)
            {
                count++;
            }
        }
    }
    return count;
}

int countPairOptimal(const vector<double>& arr, double target)
{
    // sort array in non-decreasing order
    sort(arr.begin(), arr.end());

    // initialize counter for pairs whose sum <= target
    int count = 0;

    // initialize left pointer(index)
    int left = 0;

    // initialize right pointer(index)
    int right = arr.size() - 1;

    // loop on sorted array until pointers collide, since that would mean we've traversed the whole array
    while(left < right)
    {
        // check if sum of left + right <= target
        if (arr[left] + arr[right] <= target)
        {
            // every element between left and right (when paired with arr[left]) will also be valid because the array is sorted.
            // Thus, we add (right - left) to our count.
            count += right-left;
            // Move the left pointer to the right to explore new pairs.
            left++;
        }
        else
        {
            // as sum is too high, we move the right pointer leftward to try and lower the sum.
            right--;
        }
    }
    return count;
}

int main()
{
    // initialize double array
    vector<double>& arr = {1.0, 2.0, 3.0, 4.0};

    // initialize target
    double target = 5.0;

    // call brute force method to count pairs
    int resultBrute = countPairBruteForce(arr, target);

    // call optimal method to count pairs
    int resultOptimal = countPairOptimal(arr, target);

    // print result
    cout << "Brute Force Count of pairs : " << resultBrute;

    // print result
    cout << "Optimal Count of pairs : " << resultOptimal;
}