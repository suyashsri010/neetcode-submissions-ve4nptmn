class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left_prod(n,1), right_prod(n,1);
        for(int i=1;i<n;i++){
            left_prod[i]=left_prod[i-1]*nums[i-1];
        }
        for(int i=n-2;i>=0;i--){
            right_prod[i]=right_prod[i+1]*nums[i+1];
        }
        for(int i=0;i<n;i++){
            left_prod[i]*=right_prod[i];
        }
        return left_prod;
    }
};
