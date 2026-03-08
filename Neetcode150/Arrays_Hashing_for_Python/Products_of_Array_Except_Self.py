# Given an integer array nums, return an array output where output[i] is the product of all the elements of nums except nums[i].

# Each product is guaranteed to fit in a 32-bit integer.

# Follow-up: Could you solve it in 
# O
# (
# n
# )
# O(n) time without using the division operation?

# Example 1:

# Input: nums = [1,2,4,6]

# Output: [48,24,12,8]
# Example 2:

# Input: nums = [-1,0,1,2,3]

# Output: [0,-6,0,0,0]
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        result = [1] * len(nums);
        post = 1;
        pre = 1;

        for i in range(1, len(nums) + 1, 1):
            result[i - 1] = pre * result[i - 1];
            pre = pre * nums[i - 1];

        for j in range(len(nums) - 2, -2, -1):
            result[j + 1] = result[j + 1] * post;
            post = post * nums[j + 1];

        return result;