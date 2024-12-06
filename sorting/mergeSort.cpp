//
// Created by Singh, Nitesh on 07/12/24.
//
#include<iostream>
using namespace std;

// merge function algorithm
void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid+1;
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while(right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    // update original array to sort it
    for(int i = low; i <=high; i++)
    {
        arr[i] = temp[i-low];
    }
}
// sorting algorithm using recursion
void ms(vector<int> &arr, int low, int high)
{
    // base case
    if(low == high)
    {
        return;
    }
    // middle index to divide the array
    int mid = (low + high)/2;
    ms(arr,low, mid);
    ms(arr, mid+1,high);
    merge(arr, low, mid, high);
}

// function to call mergeSorting algorithm
void mergeSort(vector<int> &arr, int n)
{
    ms(arr, 0, n-1);
}