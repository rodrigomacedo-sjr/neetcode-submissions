class Solution {
private:
    string getNext(string& s, int& idx) {
        int n = s.size();

        if (idx >= n) return "";

        while(idx < n && s[idx] == ' ') idx++;

        string token = "";
        if (isdigit(s[idx])) {
            while(idx < n && isdigit(s[idx])) {
                token += s[idx++];
            }
        }
        else if (idx < n && s[idx] != ' ') {
            token += s[idx++];
        }

        return token;
    }

    string evaluate(string& num, string& op, string& num2) {
        if (num == "") return "";
        if (op == "" || num2 == "") return num;

        int inum = stoi(num), inum2 = stoi(num2);

        if (op == "+")
            return to_string(inum + inum2);
        else if (op == "-")
            return to_string(inum - inum2);
        else if (op == "*")
            return to_string(inum * inum2);
        else if (op == "/")
            return to_string(inum / inum2);

        return "";
    }

public:
    int calculate(string s) {
        int idx = 0, n = s.size();
        string num = getNext(s, idx), op = getNext(s, idx), num2 = getNext(s, idx), num3 = "", nextOp = getNext(s, idx);

        while (idx < n && op != "") {
            if (op == "*" || op == "/" || nextOp == "+" || nextOp == "-") {
                num = evaluate(num, op, num2);
                op = nextOp;
                num2 = getNext(s, idx);
                nextOp = getNext(s, idx);
            } else {
                num3 = getNext(s, idx);
                num2 = evaluate(num2, nextOp, num3);
                nextOp = getNext(s, idx);
            }
        }

        return stoi(evaluate(num, op, num2));
    }
};