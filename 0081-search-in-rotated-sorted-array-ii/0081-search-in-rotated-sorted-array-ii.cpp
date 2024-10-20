class Solution {
public:
    bool search(vector<int>& nums, int target) {
        bool ans = false;

        int st = 0, end = nums.size()-1;
        while(st<=end){
            int mid = st + (end-st)/2;

            if(nums[mid] == target){
                ans = true;
                return ans;
            }
            if(nums[st] == nums[mid] && nums[end] == nums[mid]){
                st++;
                end--;
            }
            
            else if(nums[st]<=nums[mid]){
                if(nums[st]<=target && nums[mid]>target){
                    end = mid -1;
                }
                else{
                    st = mid + 1;
                }
            }
            else{
                if(nums[mid]<target && target <= nums[end]){
                    st = mid + 1;
                }
                else{
                    end = mid -1;
                }
            }
        }
        return ans;
        
    }
};