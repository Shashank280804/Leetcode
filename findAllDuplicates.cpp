/*
1. Sort the input array to bring duplicates next to each other.
2. Iterate through the sorted array and check adjacent elements for equality.
3. If a duplicate is found, add it to the result and skip the next element.
4. Return the result containing all duplicates.
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& v) {
        // Sort the input array to group duplicates together
        sort(v.begin(), v.end());
        
        int n = v.size(); // Get the size of the array
        vector<int> ans; // Vector to store the duplicates
        
        // Iterate through the array
        for (int i = 0; i < n - 1; i++) {
            // Check if the current element is equal to the next
            if (v[i] == v[i + 1]) {
                ans.push_back(v[i]); // Add the duplicate to the result
                i++; // Skip the next element as it's a duplicate
            }
        }
        
        return ans; // Return the list of duplicates
    }
};
