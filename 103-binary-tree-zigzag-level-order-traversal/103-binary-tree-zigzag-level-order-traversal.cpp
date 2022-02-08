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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==NULL) return res;
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        s1.push(root);
        while(!s1.empty() || !s2.empty()){
            vector<int> temp1;
            while(!s1.empty()){
                TreeNode* curr=s1.top();
                s1.pop();
                temp1.push_back(curr->val);
                if(curr->left!=NULL) s2.push(curr->left);
                if(curr->right!=NULL) s2.push(curr->right);
            }
            if(!temp1.empty()) res.push_back(temp1);
            vector<int> temp2;
            while(!s2.empty()){
                TreeNode* curr=s2.top();
                s2.pop();
                temp2.push_back(curr->val);
                if(curr->right!=NULL) s1.push(curr->right);
                if(curr->left!=NULL) s1.push(curr->left);
            }
            if(!temp2.empty()) res.push_back(temp2);
        }
        return res;
    }
};