class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        vector<int> pref(n, 0);

        for (int i = 1; i < n; i++) {
            pref[i] = pref[i - 1];
            if ((nums[i] % 2) == (nums[i - 1] % 2))
                pref[i]++;
        }

        vector<bool> ans;

        for (auto &q : queries) {
            int l = q[0], r = q[1];
            ans.push_back(pref[r] - pref[l] == 0);
        }

        return ans;
    }
};