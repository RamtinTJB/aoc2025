#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> dirs = {
    {0, 1}, {1, 0}, {-1, 0}, {0, -1},
    {1, 1}, {-1, 1}, {1, -1}, {-1, -1}
};

int n, m;

int find_and_remove(vector<string>& g) {
    int res = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (g[i][j] != '@') continue;

            int count = 0;
            for (const auto& dir: dirs) {
                auto xx = i+dir[0], yy = j+dir[1];
                if (xx >= 0 && xx < n && yy >= 0 && yy < m 
                        && g[xx][yy] == '@') {
                    count++;
                }
            }

            if (count < 4) {
                res++;
                g[i][j] = '.';
            }
        }
    }

    return res;
}

int main() {
    string line;
    vector<string> g;

    while (getline(cin, line)) {
        g.push_back(line);
    }

    n = g.size();
    m = g[0].size();
    int ans = 0;

    while (int count = find_and_remove(g)) {
        ans += count;
    }

    cout << ans << endl;

    return 0;
}
