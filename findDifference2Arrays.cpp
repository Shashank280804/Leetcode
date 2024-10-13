/* 
1. Sort both input arrays to facilitate comparison.
2. Extract unique elements from nums1 into vector A.
3. Extract unique elements from nums2 into vector B.
4. Iterate through A to find elements not present in B, storing them in vector X.
5. Iterate through B to find elements not present in A, storing them in vector Y.
6. Return the result as a vector of vectors containing X and Y.
*/
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        // Sort both input arrays
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        vector<int> A, B;
        int flag1 = nums1[0], flag2 = nums2[0];
        
        // Extract unique elements from nums1
        A.push_back(nums1[0]);
        for (int i = 1; i < nums1.size(); i++) {
            if (nums1[i] != flag1) {
                flag1 = nums1[i];
                A.push_back(flag1);
            }
        }
        
        // Extract unique elements from nums2
        B.push_back(nums2[0]);
        for (int i = 1; i < nums2.size(); i++) {
            if (nums2[i] != flag2) {
                flag2 = nums2[i];
                B.push_back(flag2);
            }
        }
        
        vector<int> X, Y;

        // Find elements in A not in B
        for (int i = 0; i < A.size(); i++) {
            bool flag = true;
            for (int j = 0; j < B.size(); j++) {
                if (A[i] == B[j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                X.push_back(A[i]);
            }
        }

        // Find elements in B not in A
        for (int i = 0; i < B.size(); i++) {
            bool flag = true;
            for (int j = 0; j < A.size(); j++) {
                if (B[i] == A[j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                Y.push_back(B[i]);
            }
        }
        
        vector<vector<int>> ans;
        ans.push_back(X);
        ans.push_back(Y);

        return ans;
    }
};
