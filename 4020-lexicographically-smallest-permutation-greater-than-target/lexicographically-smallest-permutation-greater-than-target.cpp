class Solution {
    string ans = "{";

public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> f(26, 0);
        for (auto& x : s)
            f[x - 'a'] += 1;
        string temp = "";

        // at every index i will have two choices
        dfs(0, f, target, 0, temp);

        return ans == "{" ? "" : ans;
    }

private:
    void dfs(int index, vector<int>& f, string& target, int flag,
             string& temp) {
        int n = target.size();
        if (index >= n) {
            if (temp.size())
                if (flag) {
                    ans = min(ans, temp);
                }

            return;
        }

        if (flag) {
            // picking the smallest available
            for (int i = 0; i < 26; i++) {
                if (f[i]) {
                    temp += (i + 'a');
                    f[i] -= 1;
                    dfs(index + 1, f, target, flag, temp);
                    temp.pop_back();
                    f[i] += 1;

                    break;
                }
            }
        } else {
            // i can choose to get bigger or same
            // same case
            if (f[target[index] - 'a']) {
                f[target[index] - 'a'] -= 1;
                temp += target[index];
                dfs(index + 1, f, target, flag, temp);
                f[target[index] - 'a'] += 1;
                temp.pop_back();
            }

            int i = target[index] - 'a';
            for (int j = i + 1; j < f.size(); j++) {
                if (f[j]) {
                    temp += (j + 'a');
                    f[j] -= 1;
                    dfs(index + 1, f, target, flag ^ 1, temp);
                    temp.pop_back();
                    f[j] += 1;
                    break;
                }
            }
        }

        return;
    }
};