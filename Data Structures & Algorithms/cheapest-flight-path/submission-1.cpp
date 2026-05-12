class Solution {
private:
    int min_price = INT_MAX;

    void dfs(int n, vector<vector<int>>& flights, int src, int dst, int k, int cur_price) {
        if (k < 0) return;

        if (src == dst) {
            min_price = min(min_price, cur_price);
        }

        for (auto flight : flights) {
            if (flight[0] == src) {
                dfs(n, flights, flight[1], dst, k - 1, cur_price + flight[2]);
            }
        }
    }
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        dfs(n, flights, src, dst, k + 1, 0);
        return min_price == INT_MAX ? -1 : min_price;
    }
};
