class Solution {
public:
    string getSmallestString(int n, int k) {
        string s(n, 'a');

        int E = k - n;
        int i = n - 1;

        while (E > 0) {
            if (E >= 25) {
                s[i] = 'z';
                E -= 25;
            }
            else {
                s[i] += E;
                E = 0;
            }
            i--;
        }

        return s;
    }
};