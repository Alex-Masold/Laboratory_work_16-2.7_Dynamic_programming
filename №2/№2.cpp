#include <iostream> 
#include <vector> 

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int* a = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] = a[i] % k;
        if (a[i] < 0) {
            a[i] += k;
        }
    }

    vector<bool> t1(k, false);

    t1[a[0]] = true;
    for (int i = 1; i < n; i++) {
        vector<bool> t2(k, false);
        for (int j = 0; j < k; j++) {
            if (t1[(j - a[i] + k) % k]) {
                t2[j] = true;
            }
            if (t1[(j + a[i]) % k]) {
                t2[j] = true;
            }
        }
        t1 = t2;
    }
    if (t1[0]) {
        cout << "Divisible\n";
    }
    else {
        cout << "Not divisible\n";
    }


    return 0;
}