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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        
        if(root==nullptr){
            return 0;
        }

        queue<TreeNode*> q;
        q.push(root);
        priority_queue<long long int,vector<long long int>,greater<long long int>> mp;
        //int sum=0;

        while(!q.empty()){

            int len=q.size();
            //q.pop();
            long long int sum=0;

            for(int i=0;i<len;i++){
                TreeNode* node=q.front();
                q.pop();

                sum +=node->val;

                if(node->left!=nullptr){
                    q.push(node->left);
                }

                if(node->right!=nullptr){
                    q.push(node->right);
                }
            }
            mp.push(sum);
            if(mp.size()>k){
                mp.pop();
            }
        }
        if(mp.size()<k){
            return -1;
        }

        return mp.top();
    }
};