class Solution {
public:
    string multiply(string num1, string num2) {
        long long first = 0;
        long long second = 0;
        for(char ch: num1){
            first*=10;
            first+=int(ch-'0');
        }
        for(char ch: num2){
            second*=10;
            second+=int(ch-'0');
        }
        long long ans = first*second;
        string r = "";
        if(ans==0) return "0";
        while(ans){
            int dig = ans%10;
            r+=char(dig+'0');
            ans/=10;
        }
        reverse(r.begin(),r.end());
        return r;
    }
};
