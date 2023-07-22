#include <iostream> 
#include <vector> 
#include <algorithm>  
using namespace std;



int main() {
	int d = 1000000000 + 7;
	int n;
	cin >> n;
	vector <int> a(n + 1);

	a[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			a[j] = (a[j] + a[j - i]) % d;
		}
	}

	cout << a[n];
}