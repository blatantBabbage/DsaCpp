//
// Created by Singh, Nitesh on 25/11/24.
//
#include<iostream>
#include<map>

using namespace std;

int main()
{
    // get inputs
    string s;
    cin >> s;

    // pre-compute
    map<char, int> mapHash;
    for (int i=0; i<s.size(); i++)
    {
        mapHash[s[i]]++;
    }

    int queries;
    cin >> queries;
    while(queries--)
    {
        char searchChar;
        cin >> searchChar;
        //fetch
        cout << mapHash[searchChar] << "\n";
    }
    return 0;
}