enum CourseState {
    UNVISITED,
    VISITING,
    VISITED
};

class Solution {
private:
    bool dfs(int course, vector<vector<int>>& adjList, vector<CourseState>& state) {
        if (state[course] == VISITED) return true;

        if (state[course] == VISITING) return false;

        state[course] = VISITING;

        for (auto& preReq : adjList[course]) {
            if (state[preReq] == VISITED) continue;

            if (!dfs(preReq, adjList, state))
                return false;
        }

        state[course] = VISITED;
        return true;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);

        for (auto& p : prerequisites) {
            adjList[p[0]].push_back(p[1]);
        }

        vector<CourseState> state(numCourses, UNVISITED);

        for (int course = 0; course < numCourses; ++course) {
            if (state[course] == VISITED) continue;

            if (!dfs(course, adjList, state))
                return false;
        }

        return true;
    }
};
