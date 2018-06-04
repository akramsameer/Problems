//============================================================================
// Name        : Marcus,.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
using namespace std;
char arr[9][9], word[] = "IEHOVA#";
int n, m, si, sj, cnt, t;
int main() {
	scanf("%d" , &t);
	while (t--) {
		scanf("%d %d \n" , &m ,&n);
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				char c ;
				scanf("%c",&c);
				arr[i][j] = c;
				if (arr[i][j] == '@') {
					si = i;
					sj = j;
				}
			}
		}

		while (true) {
			if (arr[si][sj] == '#')
				break;

			if (si > 0 && arr[si - 1][sj] == word[cnt]) {

				si--;
				if (word[cnt] != '#')
					cout << "forth ";
				else
					cout << "forth" << endl;
				cnt++;
			} else if (sj > 0 && arr[si][sj - 1] == word[cnt]) {

				sj--;
				if (word[cnt] != '#')
					cout << "left ";
				else
					cout << "left" << endl;
				cnt++;
			} else if (sj < m - 1 && arr[si][sj + 1] == word[cnt]) {

				sj++;
				if (word[cnt] != '#')
					cout << "right ";
				else
					cout << "right" << endl;
				cnt++;
			}

		}

	}
	return 0;
}
