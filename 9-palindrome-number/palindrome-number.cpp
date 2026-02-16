// class Solution {
// public:
//     bool isPalindrome(int x) {
//         if(x<0){
//             return false;
//         }

//         string res=to_string(x);

//         //int n=res.size();
//         bool result;
//         reverse(res.begin(),res.end());
//         int res1= stoi(res);
//         if(res1==x){
//             result= true;
//         }else{result=false;}
//         return result;
//     }
// };



class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        long long reversed = 0;
        long long temp = x;

        while (temp != 0) {
            int digit = temp % 10;
            reversed = reversed * 10 + digit;
            temp /= 10;
        }

        return (reversed == x);
    }
};