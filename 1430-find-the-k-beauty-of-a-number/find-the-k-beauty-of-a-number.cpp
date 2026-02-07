class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string s=to_string(num);

        int n=s.size();
        //string s1;
        int K_Beauty_count=0;
        for(int i=0;i<=n-k;i++){
            string s1;
           for(int j=i;j<k+i;j++){
               s1 +=s[j];
           }
           int div= stoi(s1);
           if(div>0 && num%div==0){
             //if(){}
             K_Beauty_count++;
           }
        }
        return K_Beauty_count;
    }
};