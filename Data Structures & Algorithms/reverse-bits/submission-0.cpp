class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int i = 0, ans = 0;
        while (n > 0) {
            int shouldAdd = n & 1;
            n >>= 1;
            if (shouldAdd) {
                int add = 1;
                add <<= 31 - i;
                ans += add;
            }
            i++;
        }
        return ans;
    }
};
