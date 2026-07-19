class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        unordered_map<int, vector<int>> mp;

        // Store each piece with its first element as the key
        for (auto &p : pieces) {
            mp[p[0]] = p;
        }

        int i = 0;
        while (i < arr.size()) {
            // If no piece starts with arr[i], impossible
            if (mp.find(arr[i]) == mp.end())
                return false;

            vector<int> &piece = mp[arr[i]];

            // Check if the entire piece matches arr
            for (int x : piece) {
                if (i >= arr.size() || arr[i] != x)
                    return false;
                i++;
            }
        }

        return true;
    }
};