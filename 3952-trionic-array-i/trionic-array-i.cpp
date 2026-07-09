class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        int i = 0;

        // First increasing segment
        while (i + 1 < n && nums[i] < nums[i + 1])
            i++;

        // p cannot be 0
        if (i == 0) return false;
        int p = i;

        // Decreasing segment
        while (i + 1 < n && nums[i] > nums[i + 1])
            i++;

        // q must be after p
        if (i == p) return false;
        int q = i;

        // q cannot be the last index
        if (q == n - 1) return false;

        // Final increasing segment
        while (i + 1 < n && nums[i] < nums[i + 1])
            i++;

        return i == n - 1;
    }
};