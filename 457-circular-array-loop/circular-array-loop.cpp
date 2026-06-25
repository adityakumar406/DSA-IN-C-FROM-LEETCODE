class Solution {
public:
    int nextIndex(vector<int>& nums, int i) {
        int n = nums.size();
        return ((i + nums[i]) % n + n) % n;
    }

    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) continue;

            int slow = i, fast = i;
            bool dir = nums[i] > 0;

            while (true) {
                int nextSlow = nextIndex(nums, slow);
                int nextFast = nextIndex(nums, fast);
                
                if ((nums[nextSlow] > 0) != dir ||
                    (nums[nextFast] > 0) != dir)
                    break;

                nextFast = nextIndex(nums, nextFast);
                if ((nums[nextFast] > 0) != dir)
                    break;

                slow = nextSlow;
                fast = nextFast;

                if (slow == fast) {
                    // Length 1 cycle is invalid
                    if (slow == nextIndex(nums, slow))
                        break;
                    return true;
                }
            }

            // Mark all nodes in this path as visited
            int curr = i;
            while (nums[curr] != 0 && (nums[curr] > 0) == dir) {
                int nxt = nextIndex(nums, curr);
                nums[curr] = 0;
                curr = nxt;
            }
        }

        return false;
    }
};