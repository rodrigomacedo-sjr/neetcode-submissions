class Solution {
public:
    bool isValid(string s) {
        stack<char> checker;

        for (char c : s) {
            switch (c) {
                case '(':
                case '[':
                case '{':
                    checker.push(c);
                    break;
                case '}':
                    if (!checker.empty() && checker.top() == '{') checker.pop();
                    else return false;
                    break;
                case ']':
                    if (!checker.empty() && checker.top() == '[') checker.pop();
                    else return false;
                    break;
                case ')':
                    if (!checker.empty() && checker.top() == '(') checker.pop();
                    else return false;
                    break;
            }
        }
        if (checker.empty())
            return true;
        else
            return false;
    }
};
