class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        
        // Approach By using Sliding window Concept
        int N=blocks.size();
        int Min=INT_MAX;
        for(int i=0;i<=N-k;i++){
            int count=0;
           for(int j=i;j<=k+i-1;j++){
              if(blocks[j]=='W'){
                 count++;
              }
              //Min=min(Min,count);
           }
           Min=min(Min,count);
        }
        return Min;
    }
};