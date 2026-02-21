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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        if(root==nullptr ){
            return {};
        }

        vector<vector<int>> result;
        queue<TreeNode*> mpp;
        mpp.push(root);

        int Currentlevel=0;
        bool status= true;

        while(!mpp.empty()){
            int len=mpp.size();
            result.push_back({});

            for(int i=0;i<len;i++){
                TreeNode* node= mpp.front();
                mpp.pop();

                result[Currentlevel].push_back(node->val);

                if(node->left!= nullptr){
                    mpp.push(node->left);
                }

                if(node->right!=nullptr){
                    mpp.push(node->right);
                }
              
            //   if(status==false){
            //      reverse(result[Currentlevel].begin(),result[Currentlevel].end());
            //   }
            }
            if(status==false){
                 reverse(result[Currentlevel].begin(),result[Currentlevel].end());
              }
            Currentlevel++;
            status=!status;

        }

        return result;
    }
};