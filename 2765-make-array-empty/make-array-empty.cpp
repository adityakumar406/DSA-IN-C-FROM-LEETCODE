class Fenwick {
public:
    int n;
    vector<int> bit;

    Fenwick(int n) {
        this->n = n;
        bit.assign(n + 1, 0);
    }

    void update(int idx, int val) {
        idx++;
        while (idx <= n) {
            bit[idx] += val;
            idx += idx & -idx;
        }
    }

    int query(int idx) {
        idx++;
        int sum = 0;
        while (idx > 0) {
            sum += bit[idx];
            idx -= idx & -idx;
        }
        return sum;
    }

    int rangeQuery(int l, int r) {
        if (l > r) return 0;
        return query(r) - (l ? query(l - 1) : 0);
    }
};

class Solution {
public:
    long long countOperationsToEmptyArray(vector<int>& nums) {
        int n = nums.size();

        vector<pair<int,int>> arr;
        for (int i = 0; i < n; i++)
            arr.push_back({nums[i], i});

        sort(arr.begin(), arr.end());

        Fenwick ft(n);
        for (int i = 0; i < n; i++)
            ft.update(i, 1);

        long long ans = 0;
        int cur = 0;

        for (auto &[val, idx] : arr) {
            if (idx >= cur) {
                ans += ft.rangeQuery(cur, idx);
            } else {
                ans += ft.rangeQuery(cur, n - 1);
                ans += ft.rangeQuery(0, idx);
            }

            ft.update(idx, -1);
            cur = idx;
        }

        return ans;
    }
};