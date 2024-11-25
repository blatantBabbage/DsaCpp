//
// Created by Singh, Nitesh on 25/11/24.
// TO BE USED WHEN the string contains only lowercase
#include<iostream>
using namespace std;

int main()
{
    // get inputs
    string s;
    cin >>s;

    // pre-compute
    int hash[26] = {0};
    for (int i = 0; i<s.size(); i++)
    {
        hash[s[i]-'a']++;
    }

    int queries;
    cin >> queries;
    while (queries--)
    {
        char charToBeSearched;
        cin >> charToBeSearched;
        // fetch
        cout << hash[charToBeSearched - 'a'] << "\n";
    }
    return 0;
}
