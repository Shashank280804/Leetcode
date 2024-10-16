/*
Algorithm:
1. Initialize Result Array: Start with an array arr filled with -1, assuming no greater elements are found.

2. Outer Loop: Iterate through each element in nums1:

3. For each element in nums1, locate its position in nums2.
4. Inner Loop: Once a match is found in nums2:

5. Start a second loop from the next index in nums2 to find the first greater element.
6. If a greater element is found, update the corresponding index in arr.
7. If the end of nums2 is reached without finding a greater element, arr remains -1 for that index.
8. Return the Result: After processing all elements in nums1, return the result array arr.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<int> arr(n,-1);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(nums1[i]==nums2[j]){
                    for(int k=j+1;k<m;k++){
                    if(nums2[k]>nums2[j]){
                        arr[i]=nums2[k];
                        break;
                    }
                    }
                }
            }
        }
        return arr;
    }
};