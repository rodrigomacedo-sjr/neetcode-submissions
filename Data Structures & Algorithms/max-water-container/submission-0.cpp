class Solution {
public:
  int maxArea(vector<int> &heights) {
    int r = heights.size() - 1;
    int l = 0;
    int dist = r;
    int max = 0;
    int cur_area;

    while (l < r) {
      cur_area = dist * min(heights[l], heights[r]);
      if (cur_area > max)
        max = cur_area;
      if (heights[l] < heights[r])
        l++;
      else
        r--;
      dist--;
    }

    return max;
  }
};