class Solution {
public:
  int maxArea(vector<int> &heights) {
    int l = 0, r = heights.size() - 1;
    int biggest = 0;
    int cur_area, dist;

    while (l < r) {
      dist = r - l;
      cur_area = dist * min(heights[l], heights[r]);
      biggest = max(biggest, cur_area);
      if (heights[l] < heights[r]) l++;
      else r--;
    }

    return biggest;
  }
};