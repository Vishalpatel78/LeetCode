class Solution {
    public int maxProfit(int[] arr) {
         int minValu = arr[0];
        int stock_val = 0;
        for(int i=1; i<arr.length; i++){
            if(minValu < arr[i]){
                int curnt_stock = arr[i] - minValu;
                if(curnt_stock > stock_val){
                    stock_val = curnt_stock;
                }
            }
            else{
                    minValu = arr[i];
                }
        }
        return stock_val;
       
    }
    
}