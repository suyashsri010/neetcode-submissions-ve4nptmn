class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        mp[0]=1;
        int curr_sum = 0;
        int res = 0;
        for(int num: nums){
            curr_sum+=num;
            if(mp.find(curr_sum-k)!=mp.end()){
                res+=mp[curr_sum-k];
            }
            mp[curr_sum]++;
        }
        return res;
    }
};