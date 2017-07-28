#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long int
using namespace std;
#define clr(v , d)	memset(v , d , sizeof v)
#define sz(v)		((int)(v).size())
const int VISITED = 1;
const int UNVISITED = -1;
const long long OO = 1e12;
const int OOI = 1e9;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int xdir[] = { 1, -1, 0, 0 };
int ydir[] = { 0, 0, 1, -1 };

int main()
{
    string t;
    ll i,s,p,q,r;
    while(cin>>t)
    {
        s=0;
        r=0;
        for(i=0;i+3<sz(t);i++)
        {
            if(t[i]=='b'&&t[i+1]=='e'&&t[i+2]=='a'&&t[i+3]=='r')
            {
                p=i-r;
                q=sz(t)-i-4;
                //cout<<r<<endl;
                //cout<<i<<" "<<i+3<<endl;
                //cout<<p<<" "<<q<<endl;
                s=s+(p*(q+1))+1+q;
                r=i+1;
                i+=3;
            }
        }
        cout<<s<<endl;
    }
    return 0;
}
