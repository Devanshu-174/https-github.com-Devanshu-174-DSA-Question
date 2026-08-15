/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<vector<int>> lvlans;
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> level;
           int n=q.size();
           while(n--){
                TreeNode* curr=q.front();
                q.pop();
                level.push_back(curr->val);

                if(curr->left!=NULL){
                    q.push(curr->left);
                }

                if(curr->right!=NULL){
                    q.push(curr->right);
                }
           }
           lvlans.push_back(level);
        }
        for(auto it:lvlans){
            ans.push_back(it[it.size()-1]);
        }
        return ans;
    }
};