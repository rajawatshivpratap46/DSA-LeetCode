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
    int maxLevelSum(TreeNode* root) {
        
        if(root==nullptr){
            return 0;
        }

        queue<TreeNode*>q;
        q.push(root);
        int level=1;
        int Max=INT_MIN;
        int ans;
        //int sum=0;

        while(!q.empty()){
            
            int len=q.size();
            int sum=0;
            for(int i=0;i<len;i++){
               TreeNode* node=q.front();
               q.pop();
   
               sum+= node->val;

               if(node->left!=nullptr){
                q.push(node->left);
               }

               if(node->right!=nullptr){
                q.push(node->right);
               }

            }
            //Max=max(sum,Max);
            if(sum>Max){
                Max=sum;
                ans=level;
            }
            level++;
        }
        return ans;
    }
};