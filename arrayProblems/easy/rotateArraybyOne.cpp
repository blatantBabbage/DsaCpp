//
// Created by Singh, Nitesh on 09/12/24.
//
#include<iostream>
using namespace std;

vector<int> rotateArray(vector<int> &arr, int n)
{
    int temp = arr[0];
    for(int i = 1; i<n; i++)
    {
        arr[i-1] = arr[i];
    }
    arr[n-1] = temp;
    return arr;
}