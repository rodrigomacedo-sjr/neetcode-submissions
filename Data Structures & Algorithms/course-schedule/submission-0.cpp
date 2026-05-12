class Solution {
private:
    bool dfs(int course, vector<vector<int>>& adjList, vector<bool>& visited, vector<bool>& possible) {
        if (possible[course]) return true;

        if (visited[course]) return false;

        visited[course] = true;

        for (auto& preReq : adjList[course]) {
            if (possible[preReq]) continue;

            if (!dfs(preReq, adjList, visited, possible))
                return false;
        }

        possible[course] = true;
        return true;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // [course][prerequisit]
        vector<vector<int>> adjList(numCourses);

        for (auto& p : prerequisites) {
            adjList[p[0]].push_back(p[1]);
        }

        vector<bool> possible(numCourses, false);

        for (int course = 0; course < numCourses; ++course) {
            if (possible[course]) continue;

            vector<bool> visited(numCourses, false);

            if (!dfs(course, adjList, visited, possible))
                return false;
        }

        return true;
    }
};
