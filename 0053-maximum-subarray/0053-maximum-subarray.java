class Solution {
    public int maxSubArray(int[] nums) {
        int sum = Integer.MIN_VALUE;
        int c_sum = 0;
        for(int i=0; i<nums.length; i++){
            c_sum += nums[i];
            sum = Math.max(sum, c_sum);
            if(c_sum < 0){
                c_sum = 0;
            }
            
        }
        return sum;
        
    }
}