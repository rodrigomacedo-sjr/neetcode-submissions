class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj;
        int count = 0;

        for (auto n : nums) {
            if (count == 0) {
                maj = n;
                count++;
                continue;
            }

            if (n == maj) {
                count++;
            } else {
                count--;
            }
        }
        return maj;
    }
};