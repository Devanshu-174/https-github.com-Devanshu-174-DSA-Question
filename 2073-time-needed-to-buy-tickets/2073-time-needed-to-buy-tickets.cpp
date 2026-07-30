class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int t=0;
        int i=0;
        int n=tickets.size();
        while(true){
            i=i%n;
            if(tickets[i]>0){
                tickets[i]=tickets[i]-1;
                t++,i++;
                if(tickets[k]==0){
                    return t;
                }
            }
            else{
                i++;
            }
        }
    }
};