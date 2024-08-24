#include <bits/stdc++.h>
#include <algorithm>
#include<string>
using namespace std;
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};

int main(){
    Solution solution;
    string s="anagram";
    string t="nagaram";
    bool result=solution.isAnagram(s,t);
    return 0;
}