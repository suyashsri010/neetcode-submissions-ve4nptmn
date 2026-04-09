class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int max_size = 1;
        int len = 1,sign=0;
        if(arr.size()==1) return 1;
        // if(arr[1]-arr[0]>0) len=2,sign=1;
        // if(arr[1]-arr[0]<0) len=2,sign=-1;
        for(int i=1;i<arr.size();i++){
            int diff = arr[i]-arr[i-1];
            if(diff>0 && sign<=0) len+=1,sign=1;
            else if(diff<0 && sign>=0) len+=1,sign=-1;
            else{
                len=2;
                if(!diff) len=1,sign = 0;
                else if(diff>0) sign=1;
                else sign = -1;
            } 
            max_size=max(max_size,len);
        }
        return max_size;
    }
};