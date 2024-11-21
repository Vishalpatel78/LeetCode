class Solution {
public:
     void backtrack(vector<int>& nums, int start, vector<int>& current, vector<vector<int>>& result) {
        result.push_back(current); // Add current subset to result

        for (int i = start; i < nums.size(); ++i) {
            // Skip duplicates: only add nums[i] if it is the first occurrence
            if (i > start && nums[i] == nums[i - 1]) {
                continue;
            }
            current.push_back(nums[i]); // Include nums[i]
            backtrack(nums, i + 1, current, result); // Move to next index
            current.pop_back(); // Backtrack, remove nums[i]
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        
        // Sort the input to handle duplicates
        sort(nums.begin(), nums.end());
        
        backtrack(nums, 0, current, result); // Start backtracking from index 0
        return result;
    }
};
 