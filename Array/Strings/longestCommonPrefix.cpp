#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
string longestCommonPrefix(vector<string> strs){

    int i=0;
    string s1=strs[0];
    string s2=strs[strs.size()-1];
    while(i<s1.size() && i<s2.size()){
        if(s1[i]==s2[i]){
            i++;
        }
        else{
            break;
        }
    }
    return s1.substr(0,i);

}
};