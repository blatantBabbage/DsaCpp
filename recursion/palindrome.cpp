//
// Created by Singh, Nitesh on 24/11/24.
//
#include<iostream>
using namespace std;

bool isPalindrome(int i, string &s)
{
    // base case
    if(i >= s.size()/2) return true;
    // recursive task
    if(s[i] != s[s.size() - i -1]) return false;
    // recursive call
    return isPalindrome(i+1, s);
}

int main()
{
    string s = "madam";
    cout << isPalindrome(0, s);
    return 0;
}