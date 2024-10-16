/*
Algorithm:
1. Create a frequency array to count characters in chars.
2. For each word in words, initialize a frequency array to count its characters.
3. Check if the character frequency in the word exceeds that in chars.
4. If the word can be formed, add its length to the total result.
5. Return the total length of all valid words.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int>freq(26);
        
        for(int i =0;i<chars.size();i++)
        {
            freq[chars[i]-'a']++;
        }
        int result = 0 ; 
        for(auto w :words)
        {
            int frequency[26]= {};
            bool flag = 0 ;
            for(auto c:w)
            {
                frequency[c-'a']++;
                
                if(frequency[c-'a'] > freq[c-'a'])
                {
                    flag= 1;
                    break;
                }
            }
            if(flag ==0)
            {
                result += w.size();
            }
        }
        return result;
    }
};