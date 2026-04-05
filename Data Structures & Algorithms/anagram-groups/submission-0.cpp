class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        vector<string> str = strs;
        for(string &s: str){
            sort(s.begin(),s.end());
        }
        unordered_map<string,vector<int>> mp;
        for(int i=0;i<str.size();i++){
            mp[str[i]].push_back(i);
        }
        int j=0;
        result.resize(mp.size());
        for(auto x: mp){
            string s = x.first;
            vector<int> idx = x.second;
            for(int i=0;i<idx.size();i++){
                result[j].push_back(strs[idx[i]]);
            }
            j++;
        }
        return result;
    }
};
