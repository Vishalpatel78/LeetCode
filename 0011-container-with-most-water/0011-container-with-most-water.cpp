class Solution {
public:
    int maxArea(vector<int>& height) {
    int maxWater = 0; // To store the maximum area
    int left = 0, right = height.size() - 1;

    while (left < right) {
        // Calculate the area between the two pointers
        int currentArea = min(height[left], height[right]) * (right - left);
        maxWater = max(maxWater, currentArea);

        // Move the pointer pointing to the shorter line
        if (height[left] < height[right]) {
            ++left;
        } else {
            --right;
        }
    }

    return maxWater;
}
};