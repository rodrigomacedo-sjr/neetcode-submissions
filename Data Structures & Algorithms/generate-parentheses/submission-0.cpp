        /*
        opening = 3
        closing = 0

        2 - 1
        (
        
        2 - 0
        ()

        1 - 1
        ()(

        0 - 2
        ()((

        0 - 0
        ()(())

        im thiking->
        dfs
        decision tree
        we go deep

        going left = opening
        going right = closing

        leaf / base case
        nothing else to do
        micro optimization-> no left brackets left

        tree will be height n
        n log n complexity to go everywhere

        edge? cases?
        as long as there are the same number of opening and closing...
        ((()(()))) seems okay to me

        so when there is nothing left i return ""
        when there is only rights i return ))))))) a ) for each right remaining

        but lets say im on a situation
        2 - 0
        ()
        do i need to go throug every case again?
        (()) and ()()

        on a situation of only rights i can append the memoized solutions...

        idk the methods for that so lets go basic

        */
class Solution {
private:
    set<string> ans;
    void dfs(int open, int close, string s) {
        if (open == 0 && close == 0) {
            ans.insert(s);
            return;
        }

        // open a bracket
        if (open >= 1) dfs(open - 1, close + 1, s + "(");

        // close a bracket
        if (close >= 1) dfs(open, close - 1, s + ")");
    }
public:
    vector<string> generateParenthesis(int n) {
        dfs(n, 0, "");
        vector<string> properAns(ans.begin(), ans.end());
        return properAns;
    }
};
