class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        //for(string &s: strs) sort(s.begin(),s.end());
        int len = strs.size();
        string s = strs[0], t = strs[len-1];
        string ans ="";
        int i = 0;
        while(i < s.length() && i < t.length()){
            if(s[i]!=t[i]) break;
            ans+=s[i];
            i++;
        }
        return ans;
    }
};