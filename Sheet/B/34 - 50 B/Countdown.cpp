#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long int
using namespace std;
const int VISITED = 1;
const int UNVISITED = -1;
const long long OO = 1e12;
const int OOI = 1e9;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int xdir[] = { 1, -1, 0, 0 };
int ydir[] = { 0, 0, 1, -1 };

int t, n, d;
int father[1001], num[1001], idx[1001];
map<string, int> mp;
char line[101];
string arr[1001];

bool cmp(const int & i, const int& j) {
	if (num[i] != num[j])
		return num[i] > num[j];
	return arr[i] < arr[j];
}

int main() {
	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	int cas = 1;
	while (t--) {
		scanf("%d %d", &n, &d);

		int nodes = 0;
		mp.clear();
		memset(father, -1, sizeof father);
		memset(num, 0, sizeof num);

		for (int i = 0; i < n; i++) {
			int childs;
			scanf("%s %d", &line, &childs);

			string parent(line);
			if (mp.find(parent) == mp.end()) {
				arr[nodes] = parent;
				mp[parent] = nodes++;
			}

			while (childs--) {
				scanf("%s", &line);
				string str = line;
				if (mp.find(str) == mp.end()) {
					arr[nodes] = str;
					mp[str] = nodes;
					nodes++;
				}
				father[mp[str]] = mp[parent];
			}
		}
		for (int i = 0; i < nodes; i++) {
			idx[i] = i;
			int x = i;
			for (int j = 0; j < d; j++) {
				x = father[x];
				if (x == -1)
					break;
			}

			if (x != -1)
				num[x]++;
		}

		sort(idx, idx + nodes, cmp);

		printf("Tree %d:\n", cas++);
		int changes = 0;

		for (int i = 0; i < nodes; i++) {
			int id = idx[i];
			if (num[id] == 0)
				break;

			if (i && num[id] != num[idx[i - 1]])
				changes++;
			if (i && num[id] != num[idx[i - 1]] && i >= 3)
				break;
			if (changes == 3)
				break;
			printf("%s %d\n", arr[id].c_str(), num[id]);

		}
	}

	return 0;
}
