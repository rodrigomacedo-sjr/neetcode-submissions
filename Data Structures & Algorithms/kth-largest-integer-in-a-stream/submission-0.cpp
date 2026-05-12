class KthLargest {
private:
    vector<int> v;
    int kth = 1;
public:
    KthLargest(int k, vector<int>& nums) {
        kth = k;
        sort(nums.begin(), nums.end());
        for (auto n : nums) {
            v.push_back(n);
        }
    }
    
    int add(int val) {
        v.push_back(val);
        sort(v.begin(), v.end());
        return v[v.size() - kth];
    }
};
