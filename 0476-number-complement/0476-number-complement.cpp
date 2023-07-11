class Solution {
public:
//     int findComplement(int n) {
// //         STACK OVerflow int erorr
// //         // Find number of bits in the given integer
// //     long long   number_of_bits = floor(log2(n)) + 1;
 
// //         return ((1<<number_of_bits)-1) ^n;
//   //   vector<int> v;
//   //   // convert to binary representation
//   //   while (n != 0) {
//   //       v.push_back(n % 2);
//   //       n = n / 2;
//   //   }
//   // reverse(v.begin(), v.end());
//   //   // change 1's to 0 and 0's to 1
//   //   for (int i = 0; i < v.size(); i++) {
//   //       if (v[i] == 0)
//   //           v[i] = 1;
//   //       else
//   //           v[i] = 0;
//   //   }
//   //   // convert back to number representation
//   //   int two = 1;
//   //   for (int i = v.size() - 1; i >= 0; i--) {
//   //       n = n + v[i] * two;
//   //       two = two * 2;
//   //   }
//   //   return n;
//     }
    
    int countbits(int n)
        {
            int count=0;
            while(n>0)
            {
                count++;
                n=n>>1;
            }
            return count;
        }
    int findComplement(int num) {
        for(int i=0;i<countbits(num);i++)
        {
            num=num^(1<<i);
        }
        return num;
    }
    
};