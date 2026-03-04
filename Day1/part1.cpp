#include <iostream>
#include <string>

using namespace std;

int main() {
    string line;
    int cur = 50, ans = 0; 

    while (getline(cin, line)) {
        int val = stoi(line.substr(1));
        if (line[0] == 'L') {
            cur -= val;
        } else {
            cur += val;
        }
        cur = (cur + 100) % 100;

        if (cur == 0) ans++;
    }

    cout << ans << endl;
}
