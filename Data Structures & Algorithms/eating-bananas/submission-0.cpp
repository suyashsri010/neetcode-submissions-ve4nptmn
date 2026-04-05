class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1, high = INT_MIN;
        for(int num: piles){
            if(high<num) high = num;
        }
        while(low<high){
            int mid = low+(high-low)/2;
            long long hours = 0;
            for(int num: piles){
                hours += (long long)(num+mid-1)/mid;
            }
            if(hours<=h) high = mid;
            else low = mid+1;
        }
        return low;
    }
};
