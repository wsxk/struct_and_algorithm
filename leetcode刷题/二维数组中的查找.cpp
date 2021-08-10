class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0 || matrix[0].size()==0)
            return false;
        int n = matrix.size();
        int m = matrix[0].size();
        int row = n-1,col = 0;
        while(row>=0 && col<m){
            if(matrix[row][col] == target){
                return true;
            }else if(matrix[row][col] <target){
                col++;
            }else{
                row--;
            }
        }
        return false;
    }
};