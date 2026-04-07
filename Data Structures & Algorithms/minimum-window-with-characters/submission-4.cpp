class Solution {
public:
    string minWindow(string s, string t) {
        if(t.length()>s.length() || t.length()==0) return "";
        unordered_map<char,int> freq;
        for(char ch: t) freq[ch]++;
        int left = 0, right = 0;
        int count = 0;
        int len = t.length(), mindx = 0, minlen=INT_MAX;
        while(right<s.length()){
            if(freq[s[right]]>0) count++;
            freq[s[right]]--;
            if(count==len){
                while(count>=len){
                    int current_window_len = right - left + 1;
                    if (current_window_len < minlen) {
                        minlen = current_window_len;
                        mindx = left;
                    }
                    if(freq[s[left]]>=0) count--;
                    freq[s[left]]++;
                    left++;
                }
            }
            right++;
        }
        string res = "";
        if(minlen==INT_MAX) return "";
        for(int i=mindx;i<mindx+minlen;i++){
            res+=s[i];
        }
        return res;
    }
};
