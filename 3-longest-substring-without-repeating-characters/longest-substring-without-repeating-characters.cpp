class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n=s.size();
        int Max=0;

        for(int i=0;i<n;i++){
            set<char> s2;
            map<char,int>mpp;
            for(int j=i;j<n;j++){
                // if(s[j]!=s[j+1]){
                //     //break;
                //     s2.insert(s[j]);
                // }
                mpp[s[j]]++;
                if(mpp[s[j]]>1){break;}
                s2.insert(s[j]);
            }
            int size= s2.size();
            Max=max(Max,size);
        }
        return Max;
    }
};