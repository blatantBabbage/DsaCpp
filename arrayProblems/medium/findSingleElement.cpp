//
// Created by Singh, Nitesh on 12/12/24.
//
#include<iostream>
using namespace std;

/*
 * Problem statement : You are given a sorted array 'arr' of positive integers of size 'n'.
 * It contains each number exactly twice except for one number, which occurs exactly once.
 * Problem link - https://www.naukri.com/code360/problems/find-the-single-element_6680465
 *
 * Find the number that occurs exactly once.
 *  Example :
 *      Input: ‘arr’ = {1, 1, 2, 3, 3, 4, 4}.
 *      Output: 2
 *  Explanation: 1, 3, and 4 occur exactly twice. 2 occurs exactly once. Hence the answer is 2.
 */

int findSingleElementOnly(vector<int> arr)
{
    int xorSingle = 0;
    for(int i = 0; i < arr.size(); i++)
    {
        xorSingle = xorSingle^arr[i];
    }
    return xorSingle;
}
