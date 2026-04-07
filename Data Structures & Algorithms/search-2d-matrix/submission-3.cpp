class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = matrix[0].size();
        int i=0,j=rows-1,p=0,q=cols-1;
        while(i<=j){
            int midr = i+(j-i)/2;
            if(matrix[midr][0]>target) j=midr-1;
            else if(matrix[midr][0]<target) i=midr+1;
            else return true;
        }
        if(j<0) j=0;
        while(p<=q){
            int midc = p+(q-p)/2;
            if(matrix[j][midc]==target) return true;
            else if(matrix[j][midc]>target) q=midc-1;
            else p=midc+1;
        }  
        return false;
    }
};
