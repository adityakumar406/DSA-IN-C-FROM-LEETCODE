class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        int i = 1;

        while (i < n - 1) {
            // Check if arr[i] is a peak
            if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
                int left = i;
                int right = i;

                // Expand to the left
                while (left > 0 && arr[left] > arr[left - 1])
                    left--;

                // Expand to the right
                while (right < n - 1 && arr[right] > arr[right + 1])
                    right++;

                ans = max(ans, right - left + 1);

                // Skip processed mountain
                i = right;
            } else {
                i++;
            }
        }

        return ans;
    }
};