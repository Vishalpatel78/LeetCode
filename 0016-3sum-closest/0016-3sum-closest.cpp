class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end()); // Sort the array
    int closestSum = nums[0] + nums[1] + nums[2]; // Initialize with the first three elements

    for (int i = 0; i < nums.size() - 2; ++i) {
        int left = i + 1, right = nums.size() - 1;

        while (left < right) {
            int currentSum = nums[i] + nums[left] + nums[right];

            // Update closestSum if the currentSum is closer to the target
            if (abs(currentSum - target) < abs(closestSum - target)) {
                closestSum = currentSum;
            }

            if (currentSum < target) {
                ++left; // Move the left pointer to increase the sum
            } else if (currentSum > target) {
                --right; // Move the right pointer to decrease the sum
            } else {
                // Exact match found
                return target;
            }
        }
    }

    return closestSum;
}
};