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
    int maxDepth(TreeNode* root) {
        
        //Approach-1 BFS Solution
        // if(root==nullptr){
        //     return 0;
        // }
        
        // queue<TreeNode*> mp;
        // mp.push(root);

        // //vector<vector<int>>res;
        // int Currentlevel=0;

        // while(!mp.empty()){
            
        //     int len=mp.size();
        //     //TreeNode* node= mp.front();
        //     //mp.pop();

        //    for(int i=0;i<len;i++){

        //        TreeNode* node= mp.front();
        //        mp.pop();
        //       //res[Currentlevel].push_back(node->val);

        //       if(node->left!=nullptr){
        //         mp.push(node->left);
        //       }

        //       if(node->right!=nullptr){
        //         mp.push(node->right);
        //       }

        //    }
        //    Currentlevel++;
        // }
        // //int result=res.size();

        // return Currentlevel;

        //Approach-2 DFS Solution Recursive
        
        if(root==nullptr){
            return 0;
        }

        int left= maxDepth(root->left);
        int right=maxDepth(root->right);

        return max(left,right)+1;
    }
};