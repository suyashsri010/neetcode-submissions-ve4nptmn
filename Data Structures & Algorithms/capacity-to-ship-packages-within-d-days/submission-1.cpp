class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(),weights.end());
        int right = accumulate(weights.begin(),weights.end(),0);
        int mid = 0;
        while(left<=right){
            mid = left + (right-left)/2;
            int d = 0, cap = mid;
            for(int i=0;i<weights.size();i++){
                if(cap<weights[i]){
                    d++;
                    cap = mid;
                }
                cap-=weights[i];
            }
            d++;
            if(d<=days) right=mid-1;
            else left=mid+1;
        }
        return left;
    }
};