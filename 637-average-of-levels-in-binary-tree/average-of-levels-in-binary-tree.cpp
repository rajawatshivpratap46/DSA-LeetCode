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
    vector<double> averageOfLevels(TreeNode* root) {
        
         vector<double> result;
        if(root==nullptr){
            return result; //ask to chatgpt;
        }

        vector<vector<long long int>> res;
        //vector<double> result;

        //int Currentlevel=0;
        queue<TreeNode*>mp;
        mp.push(root);

        while(!mp.empty()){

            int len=mp.size();
            //TreeNode* node= mp.front();
            long long sum=0;

            for(int i=0;i<len;i++){
                
                TreeNode* node= mp.front();
                mp.pop();

                //res[Currentlevel].push_back(node->val);
                sum+= node->val;

                if(node->left!=nullptr){
                    mp.push(node->left);
                }

                if(node->right!=nullptr){
                    mp.push(node->right);
                }
            }
            //Currentlevel++;
            result.push_back((double)sum/len);

        }

        // int n=res.size();
        // //int m=res[0].size();
       
        // for(int i=0;i<n;i++){
        //     double Average;
        //     int m=res[i].size();
        //     for(int j=0;j<m;j++){
        //        Average +=res[i][j];
        //     }
        //     double k=Average/m;
        //     result.push_back(k);
        // }

        return result;

    }
};