// Coin Change.cpp : Defines the entry point for the console application.
//
#include "CoinChange.h"

#include <stdio.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long int llint;

int mainCoinChange() {
	llint m, n;

	cin >> n;//Number to solve
	cin >> m;//Number of coins
	vector<llint> coins(m, 0);//Coins List
							  //Fill the coins vector
	for (llint i=0; i<m; i++) {
		cin >> coins[i];
	}

	vector<llint> results(n + 1, 0);

	// Base case (If given value is 0)
	results[0] = 1;

	// Pick all coins one by one and update the table[] values
	// after the index greater than or equal to the value of the
	// picked coin
	for (llint i = 0; i<m; i++)
		for (llint j = coins[i]; j <= n; j++)
			results[j] += results[j - coins[i]];

	cout << results[n];

	return 0;
}

