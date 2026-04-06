class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int mini_diff = INT_MAX,diff=0;
        int mindx = 0;
        for(int i=0;i<k;i++) diff += abs(x-arr[i]);
        mini_diff = diff;
        for(int i=k;i<arr.size();i++){
            diff += abs(x-arr[i]);
            diff -= abs(x-arr[i-k]);
            if(diff<mini_diff){
                mindx = i-k+1;
                mini_diff = diff;
            }
        }
        vector<int> res;
        for(int i=mindx;i<mindx+k;i++){
            res.push_back(arr[i]);
        }
        return res;
    }
};