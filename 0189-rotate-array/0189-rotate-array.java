class Solution {
    public void rotate(int[] nums, int k) {
        int n = nums.length;
        k = k % n;   // VERY IMPORTANT

        // int[] arr = new int[n];
        // int j = 0;

        // // last k elements
        // for (int i = n - k; i < n; i++) {
        //     arr[j++] = nums[i];
        // }

        // // first n-k elements
        // for (int i = 0; i < n - k; i++) {
        //     arr[j++] = nums[i];
        // }

        // // copy back
        // for (int i = 0; i < n; i++) {
        //     nums[i] = arr[i];
        // }


        reverse(nums,0,n-1);
        reverse(nums,0,k-1);
        reverse(nums,k,n-1);
    }
    public void reverse(int[] nums, int l, int r){
        while(l<r){
            int temp = nums[l];
            nums[l] = nums[r];
            nums[r] = temp;
            l++;
            r--;
        }
    }
}
