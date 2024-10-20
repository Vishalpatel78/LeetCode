class Solution {
public:

    void for_first(vector<int>nums,int target,vector<int>&ans){
            int st = 0;
            int end = nums.size() -1;

            while(st<=end){
                int mid = st + (end - st)/2;

                if(nums[mid] == target){
                    ans[0] = mid;
                    end = mid - 1;
                }
                else if(nums[mid]>target){
                    end = mid -1;
                }
                else{
                    st = mid + 1;
                }
            }
    }
    void for_second(vector<int>nums,int target,vector<int>&ans){
            int st = 0;
            int end = nums.size() -1;

            while(st<=end){
                int mid = st + (end - st)/2;

                if(nums[mid] == target){
                    ans[1] = mid;
                    st = mid + 1;
                }
                else if(nums[mid]>target){
                    end = mid -1;
                }
                else{
                    st = mid + 1;
                }
            }
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans = {-1,-1};

        for_first(nums,target,ans);
        for_second(nums,target,ans);
        return ans;

    }
        
};