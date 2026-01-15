class Solution {
    public void sortColors(int[] nums) {
        int n = nums.length;
        int first =0;
        int last= n-1;
         
        int[] arr = new int[n];
        for(int i=0; i<n; i++){
            if(nums[i] == 0){
                arr[first] = 0;
                first++;
            }
            if(nums[i] == 2){
                arr[last] = 2;
                last--;
            }
        }
        for(int i=first; i<=last; i++){
            arr[i] = 1;
        }
        for(int i=0; i<n; i++){
            nums[i] = arr[i];
        }
        
    }
}