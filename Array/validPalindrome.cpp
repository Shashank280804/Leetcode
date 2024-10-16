/*
Algorithm:
1. Remove Non-Alphanumeric: Filter out non-alphanumeric characters from s.
2. Convert to Lowercase: Transform the string to lowercase for uniformity.
3. Initialize Pointers: Set two pointers, p1 at the start and p2 at the end of the string.
4. Check for Mismatch: While p1 < p2, compare characters at both pointers; return false if they differ.
5. Return True: If all checks are successful, return true.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        // Step 1: Remove non-alphanumeric characters using remove_if and lambda function
        s.erase(remove_if(s.begin(), s.end(), [](char c) { return !isalnum(c); }), s.end());
        // Step 2: Convert the filtered string to lowercase
        transform(s.begin(), s.end(), s.begin(), ::tolower);

        // Step 3: Initialize two pointers at the beginning and end of the string
        int p1 = 0; // Pointer at the start of the string
        int p2 = s.length() - 1; // Pointer at the end of the string

        // Step 4: Loop until the pointers meet or cross
        while (p1 < p2) {
            // Step 5: Check if characters at both pointers are equal
            if (s[p1] != s[p2]) {
                return false; // Return false if they are not equal
            }
            // Step 6: Move the pointers towards the center
            p1++; // Increment p1
            p2--; // Decrement p2
        }

        // Step 7: If all characters matched, return true
        return true;
    }
};
