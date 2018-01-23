//============================================================================
// Name        : PrimeNumberFactor.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
vector<long> SieveOfEratosthenes(long int n);
vector<long> SieveOfEratosthenes(long int n) {
	// Create a boolean array "prime[0..n]" and initialize
	// all entries it as true. A value in prime[i] will
	// finally be false if i is Not a prime, else true.
	bool prime[n + 1];
	vector<long> temp;
	memset(prime, true, sizeof(prime));

	for (int p = 2; p * p <= n; p++) {
		// If prime[p] is not changed, then it is a prime
		if (prime[p] == true) {
			// Update all multiples of p
			for (int i = p * 2; i <= n; i += p)
				prime[i] = false;
		}
	}

	// Print all prime numbers
	for (long int p = 2; p <= n; p++)
		if (prime[p])
			temp.push_back(p);
	return temp;
}


int main() {
	long store;
	vector<long > :: iterator it;
	vector<long > now;
	vector< long> values;
	cout << "enter in the number: "<<endl;
	cin>>store;
	long k = sqrt (store);
	now = SieveOfEratosthenes(k);
	for(it = now.begin(); it< now.end(); it++){
		if(store % *it ==0){
			values.push_back(*it);
		}
	}
	for(it = values.begin(); it <values.end(); it++){
		cout<<*it<<" ";
	}

	return 0;
}
