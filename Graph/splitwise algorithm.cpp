#include <bits/stdc++.h>
using namespace std;
int main() {
    int friends, trans;
    cin >> friends >> trans;

    int amount[10000] = {0};
    for (int i = 0; i < trans; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        amount[x] -= w;
        amount[y] += w;
    }
    multiset<int>ms;
    for (int i = 0; i < friends; i++)
    {
        if (amount[i] != 0)
            ms.insert(amount[i]);
    }

    int count = 0;

    while (!ms.empty())
    {
        auto low = ms.begin();
        auto high = prev(ms.end());
        ms.erase(low);
        ms.erase(high);

        int debit = *low;
        int credit = *high;

        int totalamount = min(-debit, credit);
        count++;

        debit += totalamount;
        credit -= totalamount;

        if (debit != 0)
            ms.insert(debit);

        if (credit != 0)
            ms.insert(credit);
    }

    cout << count << endl;
}
