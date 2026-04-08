class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if(m>n) return findMedianSortedArrays(nums2,nums1);
        // we make sure m is smaller array that we operate on
        // to optimize the TC from O(log(n)) to O(log(m));
        int left = 0, right = m;
        while(left<=right){
            int px = left+(right-left)/2;
            int py = (m+n+1)/2-px;

            int x1 = px==0? INT_MIN:nums1[px-1];
            int y1 = py==0? INT_MIN:nums2[py-1];
            int x2 = px==m? INT_MAX:nums1[px];
            int y2 = py==n? INT_MAX:nums2[py];

            if(x1<=y2 && y1<=x2){
                if((m+n)%2==1) return max(x1,y1);
                else return (max(x1,y1)+min(x2,y2))/2.0;
            }
            else if(x1>y2){
                right = px-1;
            }
            else left = px+1;
        }
        return -1;
    }
};
