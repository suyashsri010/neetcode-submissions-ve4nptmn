class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0,j=0;
        while(j<nums.size()){
            if(nums[i]==nums[j]) j++;
            else{
                nums[i+1]=nums[j];
                i++;
            }
        }
        int count = 1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]) break;
            count++;
        }
        return i+1;
    }
};