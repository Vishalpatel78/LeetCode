class Solution {
public:
      void backtrack(vector<int>& nums, int start, vector<int>& current, vector<vector<int>>& result) {
        // Add the current subset to the result
        result.push_back(current);
        
        // Try to include every element after the current index
        for (int i = start; i < nums.size(); ++i) {
            // Include the current element
            current.push_back(nums[i]);
            // Recurse with the next element
            backtrack(nums, i + 1, current, result);
            // Exclude the current element and backtrack
            current.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(nums, 0, current, result);
        return result;
    }
};