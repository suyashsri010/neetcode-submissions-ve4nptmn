class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int max_sum = INT_MIN,min_sum=INT_MAX;
        int total_sum = accumulate(nums.begin(),nums.end(),0);
        int curr_sum=0,curr_neg=0;
        for(int i=0;i<nums.size();i++){
            curr_sum += nums[i];
            curr_neg += nums[i];
            max_sum = max(max_sum,curr_sum);
            min_sum = min(min_sum,curr_neg);
            if(curr_sum<0) curr_sum=0;
            if(curr_neg>0) curr_neg=0;
        }
        if(max_sum<0) return max_sum;
        return max(max_sum,total_sum-min_sum);
    }
};