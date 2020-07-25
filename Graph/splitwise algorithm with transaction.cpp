#include <bits/stdc++.h>
using namespace std;

class person {

public:
    bool operator()(pair<string, int>p1, pair<string, int>p2)
    {
        return p1.second < p2.second;
    }
};

int main() {
    int friends, trans;
    cin >> friends >> trans;

    map<string, int>net;
    for (int i = 0; i < trans; i++)
    {
        string x, y;
        int amount;
        cin >> x >> y >> amount;
        net[x] -= amount;
        net[y] += amount;
    }
    int count = 0;

    multiset<pair<string, int>, person>m;

    for (auto i : net)
    {
        string person = i.first;
        int amount = i.second;
        if (net[person] != 0)
            m.insert({person, amount});
    }

    while (!m.empty())
    {
        auto low = m.begin();
        auto high = prev(m.end());
        m.erase(low);
        m.erase(high);

        int debit = low->second;
        string debitperson = low->first;

        int credit = high->second;
        string creditperson = high->first;

        int settledamount = min(-debit, credit);
        count++;

        debit += settledamount;
        credit -= settledamount;

        cout << debitperson << " will pay " << settledamount << " Rupees to " << creditperson << endl;

        if (credit != 0)
            m.insert({creditperson, credit});

        if (debit != 0)
            m.insert({debitperson, debit});
    }

    cout << count << endl;
}
