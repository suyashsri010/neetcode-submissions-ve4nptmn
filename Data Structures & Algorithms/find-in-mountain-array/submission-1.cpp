/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int left = 0, right = mountainArr.length()-1;
        while(left<=right){
            int mid = left+(right-left)/2;
            if(mountainArr.get(mid)<mountainArr.get(mid+1)) left = mid+1;
            else right=mid-1;
        }
        int pivot = left;
        int p = pivot;
        right = mountainArr.length()-1;
        left = 0;
        while(left<=pivot){
            int mid = left+(pivot-left)/2;
            if(mountainArr.get(mid)==target) return mid;
            else if(mountainArr.get(mid)<target) left=mid+1;
            else pivot=mid-1;
        }
        while(p<=right){
            int mid = p+(right-p)/2;
            if(mountainArr.get(mid)==target) return mid;
            else if(mountainArr.get(mid)<target) right=mid-1;
            else p=mid+1;
        }
        return -1;

    }
};