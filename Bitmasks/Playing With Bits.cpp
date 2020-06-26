#include <iostream>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        int ans = 0;
        for (int i = a; i <= b; i++)
        {
            int temp = i;
            while (temp > 0)
            {
                if (temp & 1)
                {
                    ans++;
                }
                temp = temp / 2;
            }
        }
        cout << ans << "\n";
    }

}