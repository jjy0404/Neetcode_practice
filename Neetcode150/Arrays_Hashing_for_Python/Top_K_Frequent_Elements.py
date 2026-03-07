# Given an integer array nums and an integer k, return the k most frequent elements within the array.

# The test cases are generated such that the answer is always unique.

# You may return the output in any order.

# Example 1:

# Input: nums = [1,2,2,3,3,3], k = 2

# Output: [2,3]
# Example 2:

# Input: nums = [7,7], k = 1

# Output: [7]

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freq =  defaultdict(int);
        num = [[] for i in range(len(nums) + 1)];
        a = k;

        for i in range(len(nums)):
            freq[nums[i]] += 1;

        for key, val in freq.items():
            num[val].append(key);
        
        result = [];
        for i in range(len(num) - 1, 0, -1):
            if num[i]:
                for j in num[i]:
                    result.append(j);
                    a = a - 1;
                    if a == 0:
                        return result;