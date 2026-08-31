class Solution {
    vector<vector<int>> visited = vector<vector<int>>(8, vector<int>(8, 0));

public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        // upper diagonals
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {source[0], source[1]}});
        visited[source[0] - 1][source[1] - 1] = true;

        while (q.size()) {

            // upper diagonals
            int n = q.size();
            for (int i = 0; i < n; i++) {
                auto [cost, point] = q.front();
                auto [x, y] = point;
                q.pop();

                if (x == target[0] && y == target[1])
                    return cost;

                // going all four diagonals
                int j = x, k = y;
                while (1) {
                    j -= 1;
                    k += 1;
                    if (!isValid(j, k))
                        break;
                    if (!visited[j-1][k-1]) {
                        visited[j - 1][k - 1] = true;
                        q.push({cost + 1, {j, k}});
                    }
                }

                j = x, k = y;
                while (1) {
                    j -= 1;
                    k -= 1;
                    if (!isValid(j, k))
                        break;
                    if (!visited[j-1][k-1]) {
                        visited[j - 1][k - 1] = true;
                        q.push({cost + 1, {j, k}});
                    }
                }

                j = x, k = y;
                while (1) {
                    j += 1;
                    k -= 1;
                    if (!isValid(j, k))
                        break;
                    if (!visited[j-1][k-1]) {
                        visited[j - 1][k - 1] = true;
                        q.push({cost + 1, {j, k}});
                    }
                }

                j = x, k = y;
                while (1) {
                    j += 1;
                    k += 1;
                    if (!isValid(j, k))
                        break;
                    if (!visited[j-1][k-1]) {
                        visited[j - 1][k - 1] = true;
                        q.push({cost + 1, {j, k}});
                    }
                }
            }
        }

        return -1;
    }

private:
    bool isValid(int i, int j) {
        if ((i < 1 || i > 8) || (j < 1 || j > 8))
            return false;

        return true;
    }
};