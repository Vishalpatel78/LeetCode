class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int>ans;
        int top = 0; 
        int bottom = n-1;
        int left = 0;
        int right = m-1;

        while(top<=bottom && left<=right){

            // sbse phle left se right ke elm print kren
            for(int i=left; i<=right; i++){
                ans.push_back(mat[top][i]);    
            }
            top++;

            // ab top right se bottom tk ke elm print kren
            for(int i=top; i<=bottom; i++){
                ans.push_back(mat[i][right]);
            }
            right--;

            // ab right se lekar left tk ke elm print kren
            // but there is only one clm then 
            if(top<=bottom){
                for(int i=right; i>=left; i--){
                    ans.push_back(mat[bottom][i]);
                }
                bottom--;
            }
            

            // ab last me bottom se top jana hai 
            // but if there is only one row 
            if(left<=right){
                for(int i=bottom; i>=top; i--){
                    ans.push_back(mat[i][left]);
                }
                 left++;
            }
           

        }
        return ans ;

        
    }
};