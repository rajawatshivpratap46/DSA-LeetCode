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
        
        //Approach-1 Iterative BFS
        vector<int> result;
        if(root==nullptr){
            return result;
        }

        queue<TreeNode*>mpp;
        mpp.push(root);
        int level=0;

        while(!mpp.empty()){
            int len=mpp.size();

            for(int i=0;i<len;i++){

                TreeNode* node=mpp.front();
                mpp.pop();
                
                if(i==len-1){
                    result.push_back(node->val);
                }
                //result.push_back();
                if(node->left!=nullptr){
                    mpp.push(node->left);
                }

                if(node->right!=nullptr){
                    mpp.push(node->right);
                }
            }
            level++;
        }

        return result;
    }
};