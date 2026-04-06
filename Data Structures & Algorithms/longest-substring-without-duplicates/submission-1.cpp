class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 1;
        unordered_map<char,int> freq;
        int max_ans = 0;
        if(s.length()!=0)freq[s[left]]++,max_ans=1;
        else return 0;
        while(right<s.length()){
            freq[s[right]]++;
            if(freq[s[right]]>1){
                max_ans = max(max_ans,right-left);
                while(freq[s[right]]>1){
                    freq[s[left]]--;
                    if(!freq[s[left]]) freq.erase(s[left]);
                    left++;
                }
            }
            right++;
        }
        max_ans = max(max_ans,right-left);
        return max_ans;
    }
};
