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
    int findBottomLeftValue(TreeNode* root) {
        
        if(root==nullptr){
            return {};
        }

        vector<vector<int>>result;
        queue<TreeNode*>mpp;
        mpp.push(root);
        int level=0;

        while(!mpp.empty()){
            int len=mpp.size();
            result.push_back({});

            for(int i=0;i<len;i++){

                TreeNode* node=mpp.front();
                mpp.pop();

                result[level].push_back(node->val);

                if(node->left!=nullptr){
                    mpp.push(node->left);
                }

                if(node->right!=nullptr){
                    mpp.push(node->right);
                }

            }
            level++;
            //int m=result.size();

            //return result[m][0];
        }

        int m=result.size();

        return result[m-1][0];
    }
};