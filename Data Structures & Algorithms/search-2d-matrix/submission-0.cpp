class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int j=m-1;
        int i=0;
        while(true){
            if(matrix[i][j]==target) return true;
            else if(matrix[i][j]<target) i++;
            else{
                while(j>=0){
                    j--;
                    if(j<0) break;
                    if(matrix[i][j]==target) return true;

                }
            }
            if(j<0 || i>n-1) break;
        }
        return false;
    }
};
