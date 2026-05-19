class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int i=0,l=0,r=n-1;
        while(i<=r){
            if(nums[i]==1) i++;
            else if(nums[i]==0) swap(nums[l],nums[i]), i++,l++;
            else swap(nums[i],nums[r]), r--;
        }
    }
};