enum State {
    UNVISITED,
    VISITING,
    VISITED
};

class Solution {
private:
    vector<bool> exists;

    bool dfs(char curr, vector<State>& visited, vector<vector<char>>& adjList, string& result) {
        if (visited[curr - 'a'] == VISITING) return false;
        if (visited[curr - 'a'] == VISITED) return true;

        visited[curr - 'a'] = VISITING;

        for (auto adj : adjList[curr - 'a']) {
            if (!dfs(adj, visited, adjList, result))
                return false;
        }

        visited[curr - 'a'] = VISITED;
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
            visitWord(words[i]);
    
            int j = 0;
            while (j < words[i].size() && j < words[i + 1].size() && words[i][j] == words[i + 1][j])
                ++j;
            if (j >= words[i].size() || j >= words[i + 1].size()) {
                if (words[i].size() > words[i + 1].size())
                    return "";
            }
            else
                adjList[words[i][j] - 'a'].push_back(words[i + 1][j]);
        }
        visitWord(words[words.size() - 1]);
        
        string result = "";

        vector<State> visited(26, UNVISITED);

        for (int i = 0; i < 26; ++i) {
            if (!exists[i]) continue;
            if (!dfs('a' + i, visited, adjList, result))
                return "";
        }

        reverse(result.begin(), result.end());

        return result;
    }
};
