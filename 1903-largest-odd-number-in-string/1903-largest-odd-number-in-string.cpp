class Solution {
public:
    string largestOddNumber(string num) {
        while(!(num.empty())){
            if(num[num.size()-1]%2==0){
                num.pop_back();
            }
            else{
                return num;
            }
        }
        return num;
    }
};