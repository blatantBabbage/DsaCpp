//
// Created by Singh, Nitesh on 23/11/24.
//
#include<iostream>
using namespace std;

void reverseCount(int n, int x)
{
    //base case
    if(n <= 0)
    {
        return;
    }
    // perform action
    cout << n << " ";
    reverseCount(n-1, x);
}

int main()
{
    int n;
    cout << "enter a number to get reverse";
    cin>> n;
    // call recursive function
    reverseCount(3,3);
    return 0;
}