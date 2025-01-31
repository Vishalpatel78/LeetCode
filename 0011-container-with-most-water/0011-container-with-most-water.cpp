class Solution {
public:
    int maxArea(vector<int>& arr) {
        int n = arr.size();
        int j= n-1;
        int st = 0;
        int water = 0;
        for(int i=0; i<n; i++){
            int width = j - st;
            int height = min (arr[st], arr[j]);
            int curntWater = width * height;
            water = max(curntWater,water);
            if(arr[st]<arr[j]){
                st++;
            }
            else{
                j--;
            }
        }
        return water;
    }
};