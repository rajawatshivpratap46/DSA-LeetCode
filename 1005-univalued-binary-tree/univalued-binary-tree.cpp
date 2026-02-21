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
    bool isUnivalTree(TreeNode* root) {
        
        if(root==nullptr){
            return false;
        }

        unordered_map<int,int>mp;
        queue<TreeNode*>res;
        res.push(root);

        while(!res.empty()){

            int len=res.size();

            for(int i=0;i<len;i++){
                TreeNode* node=res.front();
                res.pop();
                
                int value=node->val;
                mp[value]++;

                if(node->left!=nullptr){
                    res.push(node->left);
                }

                if(node->right!=nullptr){
                    res.push(node->right);
                }
            }

        }
        int size=mp.size();
        if(size==1){
            return true;
        }

        return false;
    }
};