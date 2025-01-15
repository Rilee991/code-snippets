class Solution {
public:
    int minimizeXor(int num1, int num2) {
        // 0011 1000
        // 0011
        int setBits1 = __builtin_popcount(num1);
        int setBits2 = __builtin_popcount(num2);

        if(setBits1 == setBits2)
            return num1;
        else if(setBits1 < setBits2) {
            setBits2 -= setBits1;
// 0011 =0010 0001 sb2 = 1
            for(int i=0;i<31;i++) {
                if(!(num1&(1<<i))) {
                    num1 = num1 | (1<<i);
                    setBits2--;
                }

                if(setBits2 == 0)
                    return num1;
            }
        } else {
            // setBits1 -= setBits2;

            for(int i=30;i>=0;i--) {
                if((num1&(1<<i))) {
                    if(setBits2 <= 0)
                        num1 = num1 ^ (1<<i);
                    setBits2--;
                }

                // if(setBits2 == 0)
                //     return num1;
            }

            return num1;
        }

        return 5;
    }
};