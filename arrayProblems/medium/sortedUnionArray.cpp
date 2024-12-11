//
// Created by Singh, Nitesh on 11/12/24.
//
#include<iostream>
using namespace std;

// optimal solution 2 pointer approach
vector<int> sortedArray(vector<int> a, vector<int> b)
{
    //Size of a and b
    int n1 = a.size();
    int n2 = b.size();

    // Initialize both i and j pointers
    int i = 0;
    int j = 0;

    // Initialize union vector
    vector<int> unionArray;

    while (i < n1 && j < n2)
    {
        // 1. Compare and take the smallest element into union array first
        if (a[i] <= b[j])
        {
            // 2. Before putting element into union array check if it already exists in the latest index
            if (unionArray.size() ==0 || unionArray.back() != a[i])
            {
                unionArray.push_back(a[i]);
            }
            i++;
        }
        else
        {
            // 2. Before putting element into union array check if it already exists in the latest index
            if (unionArray.size() ==0 || unionArray.back() != b[j])
            {
                unionArray.push_back(b[j]);
            }
            j++;
        }
    }

    // 3. If anyone of the array is exhausted then continue to fill in union array with the array that has elements remaining,
    // using the same logic as point 1 & 2
    while (i < n1)
    {
        // 2. Before putting element into union array check if it already exists in the latest index
        if (unionArray.size() ==0 || unionArray.back() != a[i])
        {
            unionArray.push_back(a[i]);
        }
        i++;
    }

    while(j < n2)
    {
        // 2. Before putting element into union array check if it already exists in the latest index
        if (unionArray.size() ==0 || unionArray.back() != b[j])
        {
            unionArray.push_back(b[j]);
        }
        j++;
    }

    return unionArray;
}