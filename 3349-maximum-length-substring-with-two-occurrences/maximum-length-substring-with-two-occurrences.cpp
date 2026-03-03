class Solution {
public:
    int maximumLengthSubstring(string s) {
        
        // Brute Force Approach

        int n=s.size();
        int MaxLen=0;

        for(int i=0;i<n;i++){
            vector<int> mpp(26,0);
            for(int j=i;j<n;j++){
                 if(++mpp[s[j]-'a']==3) break;
                 MaxLen=max(MaxLen,j-i+1);
            }
        }
        return MaxLen;
    }
};