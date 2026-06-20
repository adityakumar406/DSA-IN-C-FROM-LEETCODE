class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long long prefixSum = 0;
        long long ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];

            long long cur =
                (prefixSum + i) / (i + 1);   // ceil(prefixSum/(i+1))

            ans = max(ans, cur);
        }

        return (int)ans;
    }
};