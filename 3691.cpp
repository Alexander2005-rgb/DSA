class Solution {
public:
    struct SparseTable {
        vector<vector<int>> mx, mn;
        vector<int> lg;
        int n;

        SparseTable(vector<int>& nums) {
            n = nums.size();

            lg.resize(n + 1);
            for (int i = 2; i <= n; i++) {
                lg[i] = lg[i / 2] + 1;
            }

            int K = lg[n] + 1;

            mx.assign(K, vector<int>(n));
            mn.assign(K, vector<int>(n));

            for (int i = 0; i < n; i++) {
                mx[0][i] = nums[i];
                mn[0][i] = nums[i];
            }

            for (int j = 1; j < K; j++) {
                for (int i = 0; i + (1 << j) <= n; i++) {
                    mx[j][i] = max(mx[j - 1][i],
                                   mx[j - 1][i + (1 << (j - 1))]);

                    mn[j][i] = min(mn[j - 1][i],
                                   mn[j - 1][i + (1 << (j - 1))]);
                }
            }
        }

        int getMax(int l, int r) {
            int j = lg[r - l + 1];
            return max(mx[j][l],
                       mx[j][r - (1 << j) + 1]);
        }

        int getMin(int l, int r) {
            int j = lg[r - l + 1];
            return min(mn[j][l],
                       mn[j][r - (1 << j) + 1]);
        }
    };

    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();

        SparseTable st(nums);

        priority_queue<
            tuple<long long, int, int>
        > pq;

        for (int l = 0; l < n; l++) {
            long long val =
                1LL * st.getMax(l, n - 1) -
                st.getMin(l, n - 1);

            pq.push({val, l, n - 1});
        }

        long long ans = 0;

        while (k--) {
            auto [val, l, r] = pq.top();
            pq.pop();

            ans += val;

            if (r > l) {
                long long nxt =
                    1LL * st.getMax(l, r - 1) -
                    st.getMin(l, r - 1);

                pq.push({nxt, l, r - 1});
            }
        }

        return ans;
    }
};