class Solution {
public:
    using int2 = pair<int,int>;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++) mp[nums[i]]++;
        priority_queue<int2,vector<int2>,greater<int2>> pq;
        for(auto x: mp){
            pq.push({x.second,x.first});
            if(pq.size()>k) pq.pop();
        }
        while(!pq.empty()){
            auto x = pq.top();
            pq.pop();
            res.push_back(x.second);
        }
        return res;
    }
};
