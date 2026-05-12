class Solution {
private:
    set<int> seen;

    int calculate(int n) {
        if (n == 1) return 1;

        if (seen.contains(n)) return -1;
        seen.insert(n);

        int res = 0;
        while (n > 0) {
            int r = n % 10;
            n = n / 10;
            res += r * r;
        }

        return calculate(res);
    }
public:
    bool isHappy(int n) {
        int r = calculate(n);

        return r != -1;
    }
};
