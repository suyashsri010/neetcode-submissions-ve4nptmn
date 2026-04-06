class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result = "";
        for(int i=0;i<min(word1.length(),word2.length());i++){
            result += word1[i];
            result += word2[i];
        }
        if(word1.length()>word2.length()){
            for(int i=word2.length();i<word1.length();i++) result+=word1[i];
        }
        else{
            for(int i=word1.length();i<word2.length();i++) result+=word2[i];
        }
        return result;
    }
};