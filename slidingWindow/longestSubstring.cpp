//
// Created by Singh, Nitesh on 01/04/25.
//

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

/**
Longest Substring Without Repeating Characters
Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.


Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.
 */

int longestSubstringBruteForce(string s)
{
    // Variable to store the maximum length of substring found
    int maxSubStringLength = 0;
    // loop alpha to hold 1st char of substring, to basically Loop over each possible starting index for the substring
    for (int i = 0; i < s.size(); i++)
    {
        // loop beta to hold 2nd char of substring, to basically Loop over each possible ending index for the substring starting at i
        for (int j = i; j <s.size(); j++)
        {
            // as we loop through string to find unique substring we'd want to track char we are visiting, so we store it in this set(automatically handles duplicates)
            unordered_set<char> visitedChars;

            // Flag to check if current substring has unique characters, since if we have duplicates then we will not bother calculating the max length
            bool unique = true;

            // loop gamma to run between 1st and 2nd char, to basically check every character in the substring from index i to j
            for (int k = i; k < j; k++)
            {
                // check if any char in gamma is present in charset, if yes then break-out of loop-gamma, as it means a duplicate is found
                if (visitedChars.find(s[k]) != visitedChars.end())
                {
                    unique = false;
                    // No need to check further for this substring
                    break;
                }
                // if no duplicate then add the char to charset
                visitedChars.insert(s[k]);
            }
            // update max as {max, j-i+1}
            if (unique)
            {
                maxSubStringLength = max(maxSubStringLength, j - i + 1);
            }
        }
    }
    return maxSubStringLength;
}

int longestSubstringOptimal(string s)
{
    // initialize left boundary index of sliding window
    int left = 0;
    // initialize a max variable
    int maxSubStringLength = 0;
    // Map to store the most recent index of each character
    unordered_map<char, int> visitedCharsIndexMap;

    // Loop over the string with index 'right' representing the right boundary of the window
    for (int right = 0; right < s.size(); right++)
    {
        // If the character is found in the map and its index is not before the current left boundary
        if (visitedCharsIndexMap.find(s[right]) != visitedCharsIndexMap.end() && visitedCharsIndexMap[s[right]] >= left)
        {
            // if yes then move left end to next position of right and return max length
            left = visitedCharsIndexMap[s[right]] + 1;
        }
        // otherwise store current right element into set for tracking and return max length
        visitedCharsIndexMap[s[right]] = right;
        maxSubStringLength = max(maxSubStringLength, right - left + 1);
    }
    return maxSubStringLength;
}

int main()
{
    string s = "pwwkew";
    cout << "Longest Substring Length (Brute): " << longestSubstringBruteForce(s) << endl;
    cout << "Longest Substring Length (Optimal): " << longestSubstringOptimal(s) << endl;
    return 0;
}

/**
 * Dryrun
 * Let's walk through the optimal solution (sliding window technique) with a dry run using the input string `"pwwkew"`.

---

### **Initial Setup**

- **Input String:** `s = "pwwkew"`
- **n:** Length of the string, which is `6`
- **left:** Starts at `0` — marks the beginning of our current window.
- **maxLength:** Starts at `0` — keeps track of the longest valid substring found.
- **charIndexMap:** Initially empty — this will store the most recent index of each character.

---

### **Dry Run: Iterating Through the String**

We'll iterate over the string with a variable `right` that represents the end of our current window.

#### **Iteration 1: `right = 0`**
- **Current Character:** `s[0] = 'p'`
- **Check:** `'p'` is not in `charIndexMap`.
- **Update Map:** Add `'p'` with index `0`.
  *`charIndexMap = { 'p' : 0 }`*
- **Update Window:** No duplicate, so window remains from index `left = 0` to `right = 0`.
- **Update maxLength:**
  `maxLength = max(0, 0 - 0 + 1) = 1`
- **State after iteration:**
  - **left:** 0
  - **right:** 0
  - **maxLength:** 1
  - **Map:** { 'p': 0 }

---

#### **Iteration 2: `right = 1`**
- **Current Character:** `s[1] = 'w'`
- **Check:** `'w'` is not in `charIndexMap`.
- **Update Map:** Add `'w'` with index `1`.
  *`charIndexMap = { 'p' : 0, 'w' : 1 }`*
- **Update Window:** Window now spans indices 0 to 1.
- **Update maxLength:**
  `maxLength = max(1, 1 - 0 + 1) = 2`
- **State after iteration:**
  - **left:** 0
  - **right:** 1
  - **maxLength:** 2
  - **Map:** { 'p': 0, 'w': 1 }

---

#### **Iteration 3: `right = 2`**
- **Current Character:** `s[2] = 'w'`
- **Check:** `'w'` is found in `charIndexMap` with value `1`, which is >= `left` (0).
- **Move left:** Since we have a duplicate, update `left` to one position after the last occurrence of `'w'`.
  `left = charIndexMap['w'] + 1 = 1 + 1 = 2`
- **Update Map:** Update the index for `'w'` to the current index `2`.
  *`charIndexMap = { 'p': 0, 'w': 2 }`*
- **Update maxLength:**
  Now, window is from index 2 to 2, so `maxLength = max(2, 2 - 2 + 1) = max(2, 1) = 2`
- **State after iteration:**
  - **left:** 2
  - **right:** 2
  - **maxLength:** 2
  - **Map:** { 'p': 0, 'w': 2 }

---

#### **Iteration 4: `right = 3`**
- **Current Character:** `s[3] = 'k'`
- **Check:** `'k'` is not in `charIndexMap`.
- **Update Map:** Add `'k'` with index `3`.
  *`charIndexMap = { 'p': 0, 'w': 2, 'k': 3 }`*
- **Update Window:** Window now spans indices 2 to 3.
- **Update maxLength:**
  `maxLength = max(2, 3 - 2 + 1) = max(2, 2) = 2`
- **State after iteration:**
  - **left:** 2
  - **right:** 3
  - **maxLength:** 2
  - **Map:** { 'p': 0, 'w': 2, 'k': 3 }

---

#### **Iteration 5: `right = 4`**
- **Current Character:** `s[4] = 'e'`
- **Check:** `'e'` is not in `charIndexMap`.
- **Update Map:** Add `'e'` with index `4`.
  *`charIndexMap = { 'p': 0, 'w': 2, 'k': 3, 'e': 4 }`*
- **Update Window:** Window now spans indices 2 to 4.
- **Update maxLength:**
  `maxLength = max(2, 4 - 2 + 1) = max(2, 3) = 3`
- **State after iteration:**
  - **left:** 2
  - **right:** 4
  - **maxLength:** 3
  - **Map:** { 'p': 0, 'w': 2, 'k': 3, 'e': 4 }

---

#### **Iteration 6: `right = 5`**
- **Current Character:** `s[5] = 'w'`
- **Check:** `'w'` is in `charIndexMap` with value `2`. Check if `2 >= left` (left is currently `2`): Yes, it is.
- **Move left:** Update `left` to one position after the last occurrence of `'w'`.
  `left = charIndexMap['w'] + 1 = 2 + 1 = 3`
- **Update Map:** Update the index for `'w'` to `5`.
  *`charIndexMap = { 'p': 0, 'w': 5, 'k': 3, 'e': 4 }`*
- **Update maxLength:**
  Now, window spans indices 3 to 5, so window size = `5 - 3 + 1 = 3`.
  `maxLength = max(3, 3) = 3`
- **State after iteration:**
  - **left:** 3
  - **right:** 5
  - **maxLength:** 3
  - **Map:** { 'p': 0, 'w': 5, 'k': 3, 'e': 4 }

---

### **Final Outcome**

After iterating through the string:
- The longest substring found without repeating characters has a length of **3**.
- For the input `"pwwkew"`, the optimal solution correctly identifies `"wke"` as one of the longest substrings without duplicates.

---

### **Summary Table**

| Iteration (`right`) | Character | Action Taken                                 | Updated `left` | `charIndexMap`                      | Window (Indices) | Window String | `maxLength` |
|---------------------|-----------|----------------------------------------------|----------------|-------------------------------------|------------------|---------------|-------------|
| 0                   | 'p'       | Add to map                                   | 0              | { 'p': 0 }                          | 0-0              | "p"           | 1           |
| 1                   | 'w'       | Add to map                                   | 0              | { 'p': 0, 'w': 1 }                  | 0-1              | "pw"          | 2           |
| 2                   | 'w'       | Duplicate found, move `left` to index 2      | 2              | { 'p': 0, 'w': 2 }                  | 2-2              | "w"           | 2           |
| 3                   | 'k'       | Add to map                                   | 2              | { 'p': 0, 'w': 2, 'k': 3 }          | 2-3              | "wk"          | 2           |
| 4                   | 'e'       | Add to map                                   | 2              | { 'p': 0, 'w': 2, 'k': 3, 'e': 4 }  | 2-4              | "wke"         | 3           |
| 5                   | 'w'       | Duplicate found, move `left` to index 3      | 3              | { 'p': 0, 'w': 5, 'k': 3, 'e': 4 }  | 3-5              | "kew"         | 3           |

---

 */


