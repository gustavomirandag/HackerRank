// AngryProfessor.cpp : Defines the entry point for the console application.
//
#include "AngryProfessor.h" 

#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int mainAngryProfessor() {
	int T, N, K;

	cin >> T;
	while (T--) {
		cin >> N;
		cin >> K;

		int arrivalTime;
		int studentsOnTime = 0;
		for (int i = 0; i<N; i++) {
			cin >> arrivalTime;
			//Check if the student arrived on time
			if (arrivalTime <= 0)
				studentsOnTime++;
		}
		if (studentsOnTime >= K) {
			cout << "NO" << endl;
		}
		else {
			cout << "YES" << endl;
		}
	}
	return 0;
}


