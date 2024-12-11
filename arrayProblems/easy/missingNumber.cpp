//
// Created by Singh, Nitesh on 11/12/24.
//
#include<iostream>
using namespace std;

/*
 *  Problem statement
    Given an array ‘a’ of size ‘n’-1 with elements of range 1 to ‘n’. The array does not contain any duplicates.
    Your task is to find the missing number.

    For example:
    Input:
    'a' = [1, 2, 4, 5], 'n' = 5

    Output : 3
 */

// Using optimal XOR approach
int missingNumber(int a[], int n)
{

    // Initialize XOR1, to n natural number
    int xor1 = 0;

    // Initialize XOR2, by looping on array which missing number
    int xor2 = 0;

    for(int i = 0; i<n-1; i++)
    {
        xor2 = xor2^a[i];
        xor1 = xor1^(i+1);
    }

    // as the loop is ending at n-1, but we need xor1 till n natural number for the final xor number we will get it as below
    xor1 = xor1^n;

    return xor1^xor2;
}