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
    int minDiffInBST(TreeNode* root) {
        vector<int> res;
        TreeNode* curr=root;
        stack<TreeNode*> st;
        while(!st.empty() || curr!=NULL){
            if(curr!=NULL){
                st.push(curr);
                curr=curr->left;
            }
            else{
                curr=st.top();st.pop();
                res.push_back(curr->val);
                curr=curr->right;
            }
        }
        int ans=INT_MAX;
        if(res.size()==1){
            return res[0];
        }
        if(res.size()==2){
            return abs(res[0]-res[1]);
        }
        else{
            int i=0,j=1,k=2;
            for(k=2;k<res.size();k++,i++,j++){
                ans=min(ans,min(abs(res[j]-res[i]),abs(res[k]-res[j])));
            }
        }
        return ans;
    }
};