//
// Created by Singh, Nitesh on 09/12/24.
//
#include<iostream>
#include<vector>

using namespace std;

/**
 *  
Question : "Reverse String" - Write a function that reverses a string. The input string is given as an array of characters 's'.

You must do this by modifying the input array in-place with O(1) extra memory.

Example 1:

Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
Example 2:

Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
 

Constraints:

1 <= s.length <= 105
s[i] is a printable ascii character.

 */

// Brute Force : function to reverse a string, accepts reference to vector string. TC & SC : O(n) | O(n)
void reverseStringBruteForce(vector<char>& s) 
{

    // initialise a new vector array to copy and store character in reverse order
    vector<char> reversed(s.size());

    // loop to copy char from given array in reverse order
    for(int i=0; i<s.size(); i++) 
    {
        reversed[i] = s[s.size() - 1 - i];
    }

    // loop to overwrite given array with the reversed string 
    for (int i = 0; i < s.size(); i++)
    {
        s[i] = reversed[i];
    }
}

// Optimal : Two pointer approach. TC & SC : O(n) | O(1)
void reverseStringOptimal(vector<char>& s)
{
    // left pointer
    int l = 0;

    // right pointer
    int r = s.size() - 1;

    // we can keep swaping char at left and right pointer until left and right pointer collide
    while(l<r)
    {
        //swap
        char temp = s[l];
        s[l] = s[r];
        s[r] = temp;
        l++;
        r--;
    }
}

int main()
{
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};


    // call brute force string reverse function
    reverseStringBruteForce(s);

    // call optimal string reverse function
    reverseStringOptimal(s);

    // print reversed string
    for (char c : s)
    {
        cout << c << " ";
    }
    cout << endl;

    return 0;
}
