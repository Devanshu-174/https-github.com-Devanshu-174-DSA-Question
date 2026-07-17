class Solution {
public:
    string removeDuplicates(string s) {
        string ans;
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            char curr = s[i];

            if (st.empty() || curr != st.top())
                st.push(curr);
            else
                st.pop();
        }

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};