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
    int deepestLeavesSum(TreeNode* root) {
        
        if(root==nullptr){
            return {};
        }

        queue<TreeNode*> res;
        vector<vector<int>>result;
        res.push(root);
        int level=0;

        while(!res.empty()){

            int len=res.size();
            result.push_back({});

            for(int i=0;i<len;i++){

                TreeNode* node=res.front();
                res.pop();

                result[level].push_back(node->val);

                if(node->left!=nullptr){
                    res.push(node->left);
                }

                if(node->right!=nullptr){
                    res.push(node->right);
                }

            }
            level++;

        }
        
        int m=result.size();
        int n=result[m-1].size();
        int sum=0;

        for(int j=0;j<n;j++){
            sum +=result[m-1][j];
        }

        return sum;
    }
};