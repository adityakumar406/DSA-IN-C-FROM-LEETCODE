class SnapshotArray {
private:
    int snapId;
    vector<vector<pair<int, int>>> history;

public:
    SnapshotArray(int length) {
        snapId = 0;
        history.resize(length);

        for (int i = 0; i < length; i++) {
            history[i].push_back({0, 0});
        }
    }

    void set(int index, int val) {
        if (history[index].back().first == snapId) {
            history[index].back().second = val;
        } else {
            history[index].push_back({snapId, val});
        }
    }

    int snap() {
        return snapId++;
    }

    int get(int index, int snap_id) {
        auto &v = history[index];

        int left = 0, right = v.size() - 1;
        int ans = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (v[mid].first <= snap_id) {
                ans = v[mid].second;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return ans;
    }
};