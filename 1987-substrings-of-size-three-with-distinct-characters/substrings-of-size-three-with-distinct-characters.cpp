class Solution {
public:
    int countGoodSubstrings(string s) {
        
        int n=s.size();
        //set<char> res;
        int count=0;
        int k=3;

        //Approach-1 Brute Force Approach
        //Approach-2 Sliding Window Approach
        for(int i=0;i<=n-k;i++){
            set<char> res;
            for(int j=i;j<k+i;j++){
                res.insert(s[j]);
            }
            if(res.size()==3){
                count++;
            }
        }
        //Approach-3 By using STL
        return count;
    }
};