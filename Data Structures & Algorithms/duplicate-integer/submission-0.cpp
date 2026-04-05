class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n = nums.size();
        set<int> s;
        for(int num: nums){
            if(s.find(num)!=s.end()) return true;
            else s.insert(num);
        }
        return false;
    }
};