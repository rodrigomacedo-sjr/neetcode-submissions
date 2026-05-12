class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        while (stones.size() > 1) {
            int heavy_idx1 = stones[0] >= stones[1] ? 0 : 1;
            int heavy_idx2 = stones[0] < stones[1] ? 0 : 1;

            for (int i = 2; i < stones.size(); ++i) {
                if (stones[i] >= stones[heavy_idx1]) {
                    heavy_idx2 = heavy_idx1;
                    heavy_idx1 = i;
                }
                else if (stones[i] > stones[heavy_idx2]) {
                    heavy_idx2 = i;
                }
            }

            int heavy_val1 = stones[heavy_idx1];
            int heavy_val2 = stones[heavy_idx2];

            if (heavy_val1 != heavy_val2) {
                stones.push_back(abs(heavy_val1 - heavy_val2));
            }

            if (heavy_idx1 > heavy_idx2) {
                stones.erase(stones.begin() + heavy_idx1);
                stones.erase(stones.begin() + heavy_idx2);
            } else {
                stones.erase(stones.begin() + heavy_idx2);
                stones.erase(stones.begin() + heavy_idx1);
            }


        }
        return stones.size() == 1 ? stones[0] : 0;
    }
};
