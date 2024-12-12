//
// Created by Singh, Nitesh on 12/12/24.
//
#include<iostream>
using namespace std;

int maxConsecutive(int a[], int n)
{
    int max = 0;
    int count = 0;
    for(int i = 0; i < n; i++)
    {
        if(a[i] == 1)
        {
            count++;
            if (count > max)
            {
                max = count;
            }
        }
        else
        {
            count = 0;
        }
    }

    return max;
}