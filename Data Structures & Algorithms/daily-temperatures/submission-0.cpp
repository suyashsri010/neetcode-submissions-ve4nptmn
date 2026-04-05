class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        // int len = 1;
        // vector<int>result(n,0);
        // int maxi = temperatures[n-1];
        // for(int i=n-2;i>=0;i--){
        //     if(temperatures[])
        // }
        vector<int> result(n,0);
        for(int i=0;i<n-1;i++){
            int len = 1;
            for(int j=i+1;j<n;j++){
                if(temperatures[j]>temperatures[i]) {
                    result[i]=len;
                    break;
                }
                len++;
            }
        }
        return result;
    }
};
