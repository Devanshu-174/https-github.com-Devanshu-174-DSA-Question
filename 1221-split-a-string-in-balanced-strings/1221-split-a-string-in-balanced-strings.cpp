class Solution {
public:
    int balancedStringSplit(string s) {
        int count=0,CR=0,CL=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='R'){
                CR++;
            }
            if(s[i]=='L'){
                CL++;
            }
            if(CR==CL){
                count++;
                CR=0,CL=0;
            }
        }
        return count;
    }
};