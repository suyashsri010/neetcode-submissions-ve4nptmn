class TimeMap {
public:
    unordered_map<string,vector<pair<string,int>>> mp;
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value,timestamp});
    }
    
    string get(string key, int timestamp) {
        auto &values = mp[key];
        int left = 0,right = values.size()-1;
        string res = "";
        while(left<=right){
            int mid = left+(right-left)/2;
            if(values[mid].second<=timestamp){
                res = values[mid].first;
                left = mid+1;
            }
            else right = mid-1;
        }
        return res;
    }
};
