//
// Created by Singh, Nitesh on 11/12/24.
//
#include<iostream>
using namespace std;
vector<int> moveZero(int n, vector<int> a)
{
    // we will use 2 pointer approach; using i, j
    // j will be placed where we find the first zero element
    // i will be placed next to the first zero element
    // step 1: find index to store j
    int j = -1;
    for(int i=0; i<n; i++)
    {
        if(a[i] == 0)
        {
            j == i;
            break;
        }
    }

    // step 2: start a loop from the index next to j lets say i=j+1, and then swap whenever a[i] !=0 with a[i],
    // further increment j else, if a[i] = 0, then keep looping
    int temp = -1;
    for(int i = j+1; i<n; i++)
    {
        if(a[i] != 0)
        {
            // swap(a[i], a[j])
            temp = a[j];
            a[j] = a[i];
            a[i] = temp;
            j++;
        }
    }
    return a;
}