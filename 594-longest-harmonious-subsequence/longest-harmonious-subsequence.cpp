class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n=nums.size();

        map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        vector<int>farr1,arr2;
        for(auto it:mp){
            farr1.push_back(it.second);
        }
        
        for(auto it:mp){
            arr2.push_back(it.first);
        }
        int m=arr2.size();
        int Max=0;
        for(int i=0;i<m-1;i++){
           if(arr2[i+1]-arr2[i]==1 ){
              int a=mp[arr2[i]];
              int b=mp[arr2[i+1]];
              int c =a+b;
               Max=max(Max,c);
           }
        }
        return Max;
    }
};