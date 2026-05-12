enum State {
    UNVISITED,
    VISITING,
    VISITED
};

class Solution {
private:
    vector<bool> exists;
    vector<char> compareWords(string& w1, string& w2) {
        int i = 0;
        while (i < w1.size() && i < w2.size() && w1[i] == w2[i]) {
            ++i;
        }

        if (i >= w1.size() || i >= w2.size()) 
            if (w1.size() > w2.size()) return {'!'};
            else return {'#'};

        return {w1[i], w2[i]};
    }

    bool dfs(char curr, unordered_map<char, State>& visited, vector<vector<char>>& adjList, string& result) {
        if (visited[curr] == VISITING) return false;
        if (visited[curr] == VISITED) return true;

        visited[curr] = VISITING;

        for (auto adj : adjList[curr - 'a']) {
            if (!dfs(adj, visited, adjList, result))
                return false;
        }

        visited[curr] = VISITED;
        result += curr;
        return true;
    }

    void visitWord(string& w) {
        for (auto c : w)
            exists[c - 'a'] = true;
    }

public:
    string foreignDictionary(vector<string>& words) {
        vector<vector<char>> adjList(26);

        exists.assign(26, false);

        for (int i = 0; i < words.size() - 1; ++i) {
            vector<char> adj = compareWords(words[i], words[i+1]);
            visitWord(words[i]);
            if (adj[0] == '#') continue;
            if (adj[0] == '!') return "";
            adjList[adj[0] - 'a'].push_back(adj[1]);
        }
        visitWord(words[words.size() - 1]);
        
        string result = "";

        unordered_map<char, State> visited;

        for (int i = 0; i < 26; ++i) {
            if (!dfs('a' + i, visited, adjList, result))
                return "";
        }

        reverse(result.begin(), result.end());

        return result;
    }
};
