class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0, r = nums.size() - 1, m = (r - l + 1) / 2;
        int c = 0;

        while (l != r) {
            if (c++ > 10) return 1;
            cout << "l: " << l << "\n";
            cout << "m: " << m << "\n";
            cout << "r: " << r << "\n\n";
            if (nums[l] > nums[r]) {
                if (nums[m] < nums[r]) {
                    r = m;
                    m = (r - l + 1) / 2 + l;
                } else if (nums[m] > nums[r]) {
                    l = m;
                    m = (r - l + 1) / 2 + l;
                }
            } else if (nums[l] < nums[r]) {
                break;
            }
            
            if (nums[l] == nums[m] || nums[r] == nums[m]) {
                return min(nums[l], nums[r]);
            }
        }
        return nums[l];
    }
};
