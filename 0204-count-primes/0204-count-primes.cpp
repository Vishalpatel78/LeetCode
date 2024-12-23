class Solution {
public:
    int countPrimes(int n) {
        if(n<=1)return 0;
        int count = 0; 
        vector<int>arr(n,0);
        arr[0] = 1;
        arr[1] = 1;

        for(int i=2; i<sqrt(n); i++){
            if(arr[i] == 0){
                for(int j=i*i; j<n; j += i){
                    arr[j] = 1;
                }
            }
        }

        for(int i=0; i<n; i++){
            if(arr[i] == 0){
                count++;
            }
        }
        return count;
        
    }
};