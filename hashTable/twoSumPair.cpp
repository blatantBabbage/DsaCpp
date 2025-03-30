//
// Created by Singh, Nitesh on 29/03/25.
//
#include <iostream>
#include <vector>

using namespace std;

/**
* Two Sum : Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

Example 1:
-----------
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]


Constraints:
------------
2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.


Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?
*/

vector<int> twoSumBruteForce(vector<int>& nums, int target)
{
    // loop through given array, where i is the index of the first number in pair
    for(int i = 0; i < nums.size(); i++)
    {
        // loop through all the elements after current number i, where j is the index of the second number
        for(int j = i+1; j < nums.size(); j++)
        {
            // Check if the sum of the numbers at indices i and j equals the target
            if(nums[i] + nums[j] == target)
            {
                // Return the pair of indices if they sum to the target, Found the answer; return indices immediately
                return {i,j};
            }
        }
    }
    return {};
}

vector<int> twoSumOptimal (vector<int>& nums, int target)
{
    // initialize hashtable to store number and its index
    unordered_map<int, int> numsMap;

    // loop through array element once
    for(int i = 0; i < nums.size(); i++)
    {
        // Calculate the number needed to reach target
        int complement = target - nums[i];

        // check if the required(complement) element; = target - current element is in the hash table or not
        if (numsMap.find(complement) != numsMap.end())
        {
            // If yes then return index of current element and required(complement) element
            return {numsMap[complement], i};
        }
        else
        {
            // else store the current element in with its index in hash table
            numsMap[nums[i]] = i;
        }
    }
    // Return an empty vector if no solution is found (should not happen)
    return {};
}

int main()
{
    // Example array
    vector<int> nums = {2, 7, 11, 15};

    // Target sum to find
    int target = 9;

    // call the brute force function to find the index pair
    vector<int> resultBrute = twoSumBruteForce(nums, target);

    // print the index pair
    cout << "Indexes are : " << resultBrute[0] << ", " << resultBrute[1] << endl;

    // call optimal function to find index par
    vector<int> resultOptimal = twoSumOptimal(nums, target);

    // print the index
    cout << "Indexes are : " << resultOptimal[0] << ", " << resultOptimal[1] << endl;

    return 0;
}