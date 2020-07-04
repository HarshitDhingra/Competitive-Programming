#include <bits/stdc++.h>
using namespace std;

// int find(int a[],int n,int s,int e,int sum)
// {
//     while(s<=e)
//     {
//         int mid=(s+e)/2;
//         if(a[mid]==sum)
//         {
//             return a[mid];
//         }
//         if(a[mid]>sum)
//         {
//             e=mid-1;
//         }
//         else{
//             s=mid+1;
//         }
//     }
//     return -1;
// }

int main() {
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[10001];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int x;
        cin >> x;
        sort(a, a + n);
        int ansi = -1, ansj = 100000;

        for (int i = n - 1; i >= 0; i--)
        {
            if (a[i] >= x)
                continue;

            bool find = binary_search(a, a + i, x - a[i]);
            if (find == true)
            {
                int lb = lower_bound(a, a + i, x - a[i]) - a;
                if ( abs(a[lb] - a[i]) < abs(ansi - ansj) || i == -1)
                {
                    ansi = a[i];
                    ansj = a[lb];
                }
            }
            // int p,q;
            // p=a[i];
            // int s=0,e=i-1;
            // q=find(a,n,s,e,x-a[i]);
            // if(q!=-1)
            // {
            //     if( (ansi*ansj)<0 || abs(ansi-ansj) > abs(p-q) )
            //     {
            //         //cout<<p<<" "<<q<<endl;
            //         ansi=p;
            //         ansj=q;
            //     }
            // }
        }
        cout << "Deepak should buy roses whose prices are " << min(ansi, ansj) << " and " << max(ansi, ansj) << "." << endl;
    }
}
