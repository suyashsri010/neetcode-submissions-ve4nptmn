class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int boats = 0;
        int i=0,j=people.size()-1;
        while(i<=j){
            if(i==j) {
                boats++;
                break;
            }
            else if(people[i]+people[j]<=limit) boats++,i++,j--;
            else{
                j--;
                boats++;
            }
        }
        return boats;
    }
};