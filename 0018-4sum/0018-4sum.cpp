class Solution {
public:
   
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end()); // Sort the array

    int n = nums.size();
    for (int i = 0; i < n - 3; ++i) {
        if (i > 0 && nums[i] == nums[i - 1]) continue; // Skip duplicates for the first number

        for (int j = i + 1; j < n - 2; ++j) {
            if (j > i + 1 && nums[j] == nums[j - 1]) continue; // Skip duplicates for the second number

            int left = j + 1, right = n - 1;

            while (left < right) {
                long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];

                if (sum == target) {
                    result.push_back({nums[i], nums[j], nums[left], nums[right]});

                    // Skip duplicates for the third and fourth numbers
                    while (left < right && nums[left] == nums[left + 1]) ++left;
                    while (left < right && nums[right] == nums[right - 1]) --right;

                    ++left;
                    --right;
                } else if (sum < target) {
                    ++left; // Increase the sum
                } else {
                    --right; // Decrease the sum
                }
            }
        }
    }

    return result;
}
};