class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int bill5=0, bill10=0, bill20=0;
        for(int i=0;i<bills.size();i++){
            int pay= bills[i]-5;
            while(pay>=20 && bill20>0) pay-=20,bill20--;
            while(pay>=10 && bill10>0) pay-=10,bill10--;
            while(pay>=5 && bill5>0) pay-=5,bill5--;
            if(pay!=0) return false;
            if(bills[i]==5) bill5++;
            else if(bills[i]==10) bill10++;
            else bill20++;
        }
        return true;
    }
};