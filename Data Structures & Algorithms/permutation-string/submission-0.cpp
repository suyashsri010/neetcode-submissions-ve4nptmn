class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.length()<s1.length()) return false;
        unordered_map<char,int> count1,count2;
        for(int i=0;i<s1.length();i++) count1[s1[i]]++,count2[s2[i]]++;
        if(count1==count2) return true;
        for(int i=s1.length();i<s2.length();i++){
            count2[s2[i]]++;
            count2[s2[i-s1.length()]]--;
            if(!count2[s2[i-s1.length()]]) count2.erase(s2[i-s1.length()]);
            if(count1==count2) return true;
        }
        return false;
    }
};
