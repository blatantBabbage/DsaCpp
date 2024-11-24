#include <iostream>
using namespace std;

// Problem Statement: Given two integers N1 and N2, find their greatest common divisor.
int findGcd(int n1, int n2)
{
    // 10, 20
    int gcd = 1;
    for (int i = min(n1,n2); i >= 1; i--)
    {
        if (n1%i == 0 && n2%i == 0) gcd = i;
        break;
    }
    return gcd;
    // gcd(a,b) = gcd (a-b, b)
            //  = gcd (a-b-b, b)
            //  = gcd (a%b,b)
}

int findGcdEAlgo(int n1, int n2)
{
    while (n1 > 0 && n2 >0)
    {
        if (n1>n2) n1 = n1%n2;
        else n2 = n2%n1;
    }

    if (n1 == 0) return n2;
    return n1;
}

int main()
{
    findGcd(20,40);
    findGcdEAlgo(20,40);
    return 0;
}