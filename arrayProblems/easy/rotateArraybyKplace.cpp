//
// Created by Singh, Nitesh on 09/12/24.
//
#include<iostream>
using namespace std;

void rotateArraybyK(int arr[], int n, int k)
{
    // As after every n rotation the rotated array will be exactly same as the original array, we will find how many rotation
    // are needed to be done on top of that
    k = k%n;

    // input the temp array with value that will be rotated
    int temp[k];
    for (int i=0; i<k; i++)
    {
        temp[i] = arr[i];
    }

    // shift the array elements
    for (int i = k; i<n; i++)
    {
        arr[i-k] = arr[i];
    }

    // put the array elements to be rotated at the back of array
    for (int i = n-k; i<n; i++)
    {
        arr[i] = temp[i - (n-k)];
    }
}

int main()
{
    int n;
    cin>> n;
    int k;
    cin>> k;
    int arr[n];
    for (int i = 0; i<n; i++)
    {
        cin>> arr[i];
    }

    for(int i = 0; i<n; i++)
    {
        cout << "Original Array : " << arr[i] << ", ";
    }
    rotateArraybyK(arr, n, k);
    for(int i = 0; i<n; i++)
    {
        cout << "Rotated array : " << arr[i] << ", ";
    }
    return 0;
}