class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        unordered_map<char,int> f1,f2;
        for(char ch: s){
            f1[ch]++;
        }
        for(char ch: t){
            f2[ch]++;
        }
        for(auto x: f1){
            char ch = x.first;
            int freq = x.second;
            if(f2[ch]!=freq) return false;
        }
        return true;
    }
};
