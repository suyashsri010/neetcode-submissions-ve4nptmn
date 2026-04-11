class Solution {
public:
    bool isvalid(int l, int r, string s){
        while(l<=r){
            if(s[l]==s[r]) l++,r--;
            else return false;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int mistakes = 1;
        int left = 0, right = s.length()-1;
        while(left<=right){
            if(mistakes<0) return false;
            if(s[left]==s[right]) left++,right--;
            else{
                mistakes-=1;
                if(isvalid(left,right-1,s) || isvalid(left+1,right,s)) return true;
                else return false;
            }
        }
        return true;
    }
};