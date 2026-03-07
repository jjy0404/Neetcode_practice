// Top K Frequent Elements
// Medium
// Topics
// Company Tags
// Hints
// Given an integer array nums and an integer k, return the k most frequent elements within the array.

// The test cases are generated such that the answer is always unique.

// You may return the output in any order.

// Example 1:

// Input: nums = [1,2,2,3,3,3], k = 2

// Output: [2,3]
// Example 2:

// Input: nums = [7,7], k = 1

// Output: [7]

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        vector<vector<int>> num(nums.size() + 1);
        int a = k;
        vector<int> result;

        for (const auto i : nums) {
            freq[i]++;
        }

        for (const auto& i : freq) {
            num[i.second].push_back(i.first);
        }

        for (int i = num.size()-1; i > 0; i--) {
            if (!num[i].empty()) {
                for (int j = 0; j < num[i].size(); j++) {
                    result.push_back(num[i][j]);
                    a--;
                    if(a == 0) {
                        return result;
                    }
                }
            }
        }
    }
};