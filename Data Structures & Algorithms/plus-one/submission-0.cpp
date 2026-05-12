class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        bool carry = true;
        for (int i = n - 1; i >= 0; --i) {
            if (carry) digits[i]++;

            if (digits[i] == 10) {
                digits[i] = 0;
                carry = true;
            } else {
                carry = false;
            }
        }
        if (carry) digits.insert(digits.begin(), 1);
        return digits;
    }
};
