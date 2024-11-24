//
// Created by Singh, Nitesh on 24/11/24.
//
#include<iostream>
using namespace std;

int f(int n)
{
    // base case
    if (n <= 1)
    {
        return n;
    }
    // recursive task
    int last = f(n-1);
    int slast = f(n-2);

    // recursive call
    return last + slast;
}

int main()
{
    cout << f(4);
}