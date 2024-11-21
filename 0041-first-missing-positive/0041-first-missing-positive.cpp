class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        
        // Step 1: Re-arrange the elements
        for (int i = 0; i < n; ++i) {
            // While the current element is in the range [1, n] and it is not in the correct position
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                // Swap nums[i] with nums[nums[i] - 1]
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        
        // Step 2: Find the first missing positive number
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        
        // Step 3: If all elements are in place, the missing number is n + 1
        return n + 1;
    }
};