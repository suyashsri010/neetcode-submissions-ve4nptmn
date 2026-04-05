class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // int n = nums.size();
        // int left = 0, right = 1;
        // while(right < n){
        //     //while(left<right && nums[left]!=nums[right]) left++;
        //     if(right-left>k) left++;
        //     //while(left<right && nums[left]!=nums[right]) left++;
        //     else{
        //         if(nums[left]==nums[right]) return true;
        //         else right++;
        //     }
        //     while(left<right && nums[left]!=nums[right]) left++;
        // }
        // return false;
        int sz = nums.size();
        unordered_map<int,int> frequency;
        for(int i=0;i<=k;i++){
            frequency[nums[i]]++;
            if(frequency[nums[i]]==2) return true;
        }
        int left = 0, right = k+1;
        while(right<sz){
            if(frequency.size()<=k) return true;
            frequency.erase(nums[left]);
            frequency[nums[right]]++;
            left++,right++;
        }
        if(frequency.size()<=k) return true;
        return false;
    }
};