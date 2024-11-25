//
// Created by Singh, Nitesh on 25/11/24.
//
#include<iostream>
#include<map>
using namespace std;

int main()
{
    // get inputs
    int arrSize;
    cin >> arrSize;
    int arr[arrSize];
    for (int i = 0; i<arrSize; i++)
    {
        cin >> arr[arrSize];
    }

    // pre-compute
    map<int, int> mapHashed;
    for(int i=0; i<arrSize; i++)
    {
        mapHashed[arr[i]]++;
    }

    int queries;
    cin >>queries;
    while (queries--)
    {
        int searchNumber;
        cin >> searchNumber;
        // fetch
        cout << mapHashed[searchNumber] << "\n";
    }

    return 0;
}