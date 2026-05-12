class Solution {
public:
    int reverse(int x) {
        if (x == 0) return 0;

        string res = "";
        int sign = x < 0 ? -1 : 1;
        x = abs(x);

        while (x > 0) {
            res += to_string(x % 10);
            x = x / 10;
        }

        cout << res << "\n";

        if (res.size() >= to_string(INT_MAX).size() && res > to_string(INT_MAX)) {
            return 0;
        }
        

        return stoi(res) * sign;
    }
};
