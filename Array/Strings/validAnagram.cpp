#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
class Solution
{
public:
    bool validAnagram(string s,string t)
    {
        bool flag = false;
        sort(s.begin(), s.end());
        sort(t.begin(),t.end());
        return s==t;
    }
};