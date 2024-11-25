//
// Created by Singh, Nitesh on 25/11/24.
//
#include<iostream>
using namespace std;

int main()
{
    // get inputs
    int arraySize;
    cin >> arraySize;
    int arr[arraySize];
    for (int i = 0; i<arraySize; i++)
    {
        cin >> arr[i];
    }

    // pre-compute
    int hash[1000000] = {0};
    for (int i = 0; i<arraySize; i++)
    {
        hash[arr[i]]++;
    }

    int noOfQueries;
    cin >> noOfQueries;
    while (noOfQueries--)
    {
        int searchNumber;
        cin >> searchNumber;
        // fetch
        cout << hash[searchNumber] << "\n";
    }
    return 0;
}
