class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;

        function<long long(int, int)> dfs = [&](int i, int j) -> long long {
            if (i < 0 || i >= m || j < 0 || j >= n ||
                grid[i][j] == 0) {
                return 0;
            }

            long long sum = grid[i][j];
            grid[i][j] = 0; // Mark visited

            sum += dfs(i + 1, j);
            sum += dfs(i - 1, j);
            sum += dfs(i, j + 1);
            sum += dfs(i, j - 1);

            return sum;
        };

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    long long sum = dfs(i, j);

                    if (sum % k == 0) {
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};