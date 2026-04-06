class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0;
        int left = 0, maxf = 0;
        unordered_map<char,int> freq;
        for(int right = 0; right<s.length();right++){
            freq[s[right]]++;
            maxf = max(maxf,freq[s[right]]);
            while(right-left+1-maxf>k){
                freq[s[left]]--;
                left++;
            }
            res = max(res,right-left+1);
        }
        return res;
    }
};
