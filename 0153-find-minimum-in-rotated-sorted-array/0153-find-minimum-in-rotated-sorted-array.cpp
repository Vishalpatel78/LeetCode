class Solution {
public:
    int findMin(vector<int>& nums) {
         
        int st = 0, end = nums.size()-1;
         while (st < end) {
            int mid = st + (end - st) / 2;

            // If the middle element is less than the rightmost element, the minimum is in the left part (or mid)
            if (nums[mid] < nums[end]) {
                end = mid;
            } 
            // Otherwise, the minimum is in the right part
            else {
                st = mid + 1;
            }
        }
        
        // After the loop ends, st == end and points to the smallest element
        return nums[st];
    }
};