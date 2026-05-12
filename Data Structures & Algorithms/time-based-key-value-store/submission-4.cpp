class TimeMap {
public:
    TimeMap() {
        storage = {};
    }
    
    void set(string key, string value, int timestamp) {
        storage[key].push_back(make_pair(timestamp, value));
        return;
    }
    
    string get(string key, int timestamp) {
        vector<pair<int, string>> *v = &storage[key];

        if (v->size() <= 0) return "";

        int l = 0, r = v->size() - 1, m = (r - l) / 2;

        if (timestamp > (*v)[r].first) return (*v)[r].second;
        else if (timestamp < (*v)[l].first) return "";

        while (true) {
            if ((*v)[m].first == timestamp) return (*v)[m].second;
            if (timestamp >= (*v)[l].first && timestamp <= (*v)[m].first) r = m;
            else if (timestamp >= (*v)[m].first && timestamp <= (*v)[r].first) l = m;
            
            m = l + (r - l) / 2;

            if (m == l || l > r) break;
        }
        return (*v)[r].first == timestamp ? (*v)[r].second : (*v)[m].second;
    }
private:
    unordered_map<string, vector<pair<int,string>>> storage;
};
