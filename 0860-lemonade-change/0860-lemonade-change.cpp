class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int D5=0,D10=0;
        for(int i=0;i<bills.size();i++){
            if(bills[i]==5){
                D5++;
            }
            if(bills[i]==10){
                if(D5<1){
                    return false;
                }
                D5--;
                D10++;
            }
            if(bills[i]==20){
                if((D10>=1 &&D5>=1) ||D5>=3){
                    if (D10>=1) {
                        D10 -= 1;
                        D5 -= 1;
                    } else {
                        D5 -= 3;
                    }
                }
                else{
                    return false;
                }
            }
        }

        return true;
    }
};