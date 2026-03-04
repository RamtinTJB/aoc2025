#include <iostream>
#include <string>

using namespace std;

int main() {
    string line;
    int cur = 50, ans = 0; 

    while (getline(cin, line)) {
        int val = stoi(line.substr(1));
        ans += abs(val) / 100;
        val %= 100;

        if (line[0] == 'L') {
            ans += (cur != 0) && (val >= cur);
            cur -= val;
        } else {
            cur += val;
            ans += cur >= 100;
        }
        cur = (cur + 100) % 100;
    }

    cout << ans << endl;
}
