//
// Created by Singh, Nitesh on 11/12/24.
//
#include<iostream>
using namespace std;

void reverseArray(int n, int a[])
{
    int i = 0;
    int j = n-1;
    int temp = 0;
    while(i<j)
    {
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
        i++;
        j--;
    }
}