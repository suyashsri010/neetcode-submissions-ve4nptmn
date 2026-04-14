class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int boats = 0;
        int i=0,j=people.size()-1;
        while(i<=j){
            boats++;
            if(i==j) {
                break;
            }
            else if(people[i]+people[j]<=limit) i++,j--;
            else{
                j--;
            }
        }
        return boats;
    }
};