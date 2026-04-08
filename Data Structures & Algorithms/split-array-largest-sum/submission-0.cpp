class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int left = *max_element(nums.begin(),nums.end());
        int right = accumulate(nums.begin(),nums.end(),0);
        while(left<=right){
            int mid = left+(right-left)/2;
            int cap = mid;
            int count_sub = 1;
            for(int num: nums){
                if(cap-num<0){
                    count_sub++;
                    cap=mid;
                }
                cap-=num;
            }
            if(count_sub<=k) right=mid-1;
            else left=mid+1;
        }
        return left;
    }
};