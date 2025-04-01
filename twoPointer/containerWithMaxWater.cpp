//
// Created by Singh, Nitesh on 02/04/25.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
Container With Most Water
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.
Return the maximum amount of water a container can store.

Notice that you may not slant the container.

Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
Example 2:

Input: height = [1,1]
Output: 1


Constraints:

n == height.length
2 <= n <= 105
0 <= height[i] <= 104
 */
int maxWaterBrute (vector<int>& height)
{
    int maxWater = 0;
    for (int i = 0; i < height.size(); i++)
    {
        for (int j = i+1; j < height.size(); j++)
        {
            int width = j - i;
            // The container height is determined by the shorter line to avoid water spillage
            int containerHeight = min(height[i], height[j]);
            int currentWaterArea = containerHeight * width;
            // Update maxArea if we find a larger area
            maxWater = max(maxWater, currentWaterArea);
        }
    }
    // Return the maximum area found
    return maxWater;
}

int maxWaterOptimal (vector<int>& height)
{
    int maxWater = 0;
    // Initialize two pointers at the extreme ends
    int left = 0;
    int right = height.size() - 1;
    while(left<right)
    {
        int width = right - left;
        // The container height is determined by the shorter line to avoid water spillage
        int containerHeight = min(height[right], height[left]);
        int currentWaterArea = containerHeight * width;

        // Update maxArea if we find a larger area
        maxWater = max(maxWater, currentWaterArea);
        // Move the pointer that has the smaller height inward, We move the pointer with the smaller height inward because moving the taller one won’t help us get a bigger area.
        if (height[left] < height[right])
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    // Return the maximum area found
    return maxWater;
}

int main()
{
    vector<int>& height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << "Max water brute is : " << maxWaterBrute(height) << endl;
    cout << "Max water optimal is : " << maxWaterOptimal(height) << endl;
    return 0;
}