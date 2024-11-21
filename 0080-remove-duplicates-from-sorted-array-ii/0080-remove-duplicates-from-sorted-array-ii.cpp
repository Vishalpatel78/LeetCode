class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }
    
    int i = 1;  // Pointer to place the next valid element (start from index 1)
    int count = 1;  // Counter to count occurrences of the current element

    // Iterate through the array starting from the second element
    for (int j = 1; j < nums.size(); ++j) {
        if (nums[j] == nums[j - 1]) {
            count++;  // Increment count if the current element is same as previous
        } else {
            count = 1;  // Reset count for a new element
        }

        // Place the element if it appears at most twice
        if (count <= 2) {
            nums[i] = nums[j];
            i++;  // Move the pointer to the next position for valid element
        }
    }

    return i;  // Return the number of valid elements
}
};