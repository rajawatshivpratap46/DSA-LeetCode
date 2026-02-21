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
    vector<int> largestValues(TreeNode* root) {
        
        vector<int> result;
        if(root==nullptr){
            return result;
        }

        vector<priority_queue<int>>res;
        queue<TreeNode*>mkp;
        mkp.push(root);
        int level=0;
        
        while(!mkp.empty()){
            int len=mkp.size();
            res.push_back({});

            for(int i=0;i<len;i++){
                TreeNode* node=mkp.front();

                mkp.pop();

                res[level].push(node->val);

                if(node->left!=nullptr){
                    mkp.push(node->left);
                }

                if(node->right!=nullptr){
                    mkp.push(node->right);
                }

            }
            //level++;
            result.push_back(res[level].top());
            level++;
        }

        return result;
    }
};