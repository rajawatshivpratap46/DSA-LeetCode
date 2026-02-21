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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        if(root==nullptr){
            return {};
        }

        vector<vector<int>> result;
        queue<TreeNode*> mp;
        mp.push(root);
        int Currentlevel=0;

        while(!mp.empty()){

            int len=mp.size();
            result.push_back({});

            for(int i=0;i<len;i++){
                TreeNode* node=mp.front();
                mp.pop();

                result[Currentlevel].push_back(node->val);

                if(node->left!=nullptr){
                    mp.push(node->left);
                }

                if(node->right!=nullptr){
                    mp.push(node->right);
                }

            }
            Currentlevel++;
        }

        return result;
    }
};