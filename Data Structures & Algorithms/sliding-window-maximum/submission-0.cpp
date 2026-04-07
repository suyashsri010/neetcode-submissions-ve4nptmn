class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        map<int,int> mp;
        for(int i=0;i<k;i++) mp[nums[i]]++;
        vector<int> ans;
        for(int i=k;i<nums.size();i++){
            auto it = mp.rbegin();
            ans.push_back(it->first);
            mp[nums[i-k]]--;
            if(!mp[nums[i-k]]) mp.erase(nums[i-k]);
            mp[nums[i]]++;
        }
        auto it = mp.rbegin();
        ans.push_back(it->first);
        return ans;
    }
};
