class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;
        mp[0] = -1;  // prefix sum 0 before array starts

        int prefixSum = 0;
        int maxLen = 0;

        for (int i = 0; i < nums.size(); i++) {
            prefixSum += (nums[i] == 1 ? 1 : -1);

            if (mp.count(prefixSum)) {
                maxLen = max(maxLen, i - mp[prefixSum]);
            } else {
                mp[prefixSum] = i; // store first occurrence
            }
        }

        return maxLen;
    }
};