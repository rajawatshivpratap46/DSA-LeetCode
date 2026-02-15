// class Solution {
// public:
//     string addBinary(string a, string b) {
//         int a1=stoi(a);
//         int b1=stoi(b);

//         int c1= a1+b1;
//         string str;
//         while(c1%2!=1){
//             int rem=c1%2;
//         }
//     }
// };

class Solution {
 public:
  string addBinary(string a, string b) {
    string ans;
    int carry = 0;
    int i = a.length() - 1;
    int j = b.length() - 1;

    while (i >= 0 || j >= 0 || carry) {
      if (i >= 0)
        carry += a[i--] - '0';
      if (j >= 0)
        carry += b[j--] - '0';
      ans += carry % 2 + '0';
      carry /= 2;
    }

    reverse(begin(ans), end(ans));
    return ans;
  }
};