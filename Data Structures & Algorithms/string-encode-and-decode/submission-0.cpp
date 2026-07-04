class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";
        for(string s: strs){
            ans += s;
            ans += ".";
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        stringstream ss(s);
        string token = "";
        while(getline(ss,token,'.')) ans.push_back(token);
        return ans;
    }
};
