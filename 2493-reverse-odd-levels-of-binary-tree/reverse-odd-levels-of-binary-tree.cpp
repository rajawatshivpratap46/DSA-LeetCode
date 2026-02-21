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
// class Solution {
// public:
//     TreeNode* reverseOddLevels(TreeNode* root) {
        
//         TreeNode* result;
//         if(root==nullptr){
//             return result;
//         }

//         queue<TreeNode*> q;
//         q.push(root);
//         int level=0;

//         while(!q.empty()){
//             int len=q.size();

//             for(int i=0;i<len;i++){
//                 TreeNode* node=q.front();
//                 q.pop();

//                 if(level%2!=0 && node->left!=nullptr && node->right!=nullptr){
//                     TreeNode* temp;
//                     temp=node->left;
//                     node->left=node->right;
//                     node->right=temp;
//                 }

//                 q.push(node->left);
//                 q.push(node->right);
//             }

//             level++;
//         }

//         return root;
//     }
// };

class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        
        if(root == nullptr)
            return root;

        queue<TreeNode*> q;
        q.push(root);
        int level = 0;

        while(!q.empty()){
            int len = q.size();
            vector<TreeNode*> nodes;

            for(int i = 0; i < len; i++){
                TreeNode* node = q.front();
                q.pop();

                nodes.push_back(node);

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }

            if(level % 2 != 0){
                int i = 0, j = nodes.size() - 1;
                while(i < j){
                    swap(nodes[i]->val, nodes[j]->val);
                    i++;
                    j--;
                }
            }

            level++;
        }

        return root;
    }
};