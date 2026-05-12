class Solution {
public:
    int hammingWeight(uint32_t n) {
        int numberOnes = 0;

        while (n > 0) {
            int i = 0;
            while (pow(2, i++) <= n) {}
            n -= pow(2, ----i);
            numberOnes++;
        }

        return numberOnes;
    }
};
