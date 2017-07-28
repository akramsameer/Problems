#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long int
using namespace std;
int n;
char grid[3][3];
bool valid(char c){
	if ((grid[0][0] == grid[1][1]) && (grid[1][1] == grid[2][2])
				&& grid[1][1] == c)
			return true;

		if ((grid[0][0] == grid[0][1]) && (grid[0][1] == grid[0][2])
				&& grid[0][1] == c)
			return true;

		if ((grid[1][0] == grid[1][1]) && (grid[1][1] == grid[1][2])
				&& grid[1][1] == c)
			return true;

		if ((grid[2][0] == grid[2][1]) && (grid[2][1] == grid[2][2])
				&& grid[2][1] == c)
			return true;

		if ((grid[0][0] == grid[1][0]) && (grid[1][0] == grid[2][0])
				&& grid[1][0] == c)
			return true;
		if ((grid[0][1] == grid[1][1]) && (grid[1][1] == grid[2][1])
				&& grid[1][1] == c)
			return true;
		if ((grid[0][2] == grid[1][2]) && (grid[1][2] == grid[2][2])
				&& grid[1][2] == c)
			return true;

		if ((grid[0][2] == grid[1][1]) && (grid[1][1] == grid[2][0])
				&& grid[1][1] == c)
			return true;

		return false;
}
int main() {
	freopen("in.txt", "r", stdin);
	scanf("%d", &n);
	while (n--) {
		getchar();
		int o = 0 , x = 0;
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j){
				scanf("%c", &grid[i][j]);
				if(grid[i][j] == 'O')
					o++;
				else if(grid[i][j] == 'X')
					x++;
			}
			getchar();
		}

		bool ans = true;
		if(x == o+1)
			ans = !valid('O');
		else if (x == o){
			ans = ! valid('X');
		}
		else
			ans = false;
		if(ans)
			printf("yes\n");
		else
			printf("no\n");

	}
	return 0;
}

