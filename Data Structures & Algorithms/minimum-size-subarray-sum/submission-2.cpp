class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int mini_len = INT_MAX;
        int left = 0, right = 0;
        long long sum = 0;
        for(right = 0; right<nums.size(); right++){
            sum += nums[right];
            if(sum>=target){
                while(sum>target){
                    sum -= nums[left];
                    left++;
                }
                if(sum<target)mini_len = min(mini_len,right-left+2);
                else mini_len = min(mini_len,right-left+1);
            }
        }
        return mini_len==INT_MAX?0:mini_len;
    }
};