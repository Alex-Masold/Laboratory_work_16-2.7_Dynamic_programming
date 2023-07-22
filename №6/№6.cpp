#include <iostream>  
#include <vector> 
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> length(n, 1);
    vector<int> inx_prev(n, -1);

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j]) {
                if (length[j] + 1 > length[i]) {
                    length[i] = length[j] + 1;
                    inx_prev[i] = j;
                }
            }
        }
    }
    int ans = length[0], index = 0;
    for (int i = 1; i < n; i++) {
        if (length[i] > ans) {
            ans = length[i];
            index = i;
        }
    }
    cout << ans << "\n";
    vector<int> sequense;
    while (index != -1) {
        sequense.push_back(index);
        index = inx_prev[index];
    }
    int m = sequense.size();
    for (int i = m - 1; i >= 0; i--) {
        cout << "A[" << sequense[i] + 1 << "] = " << a[sequense[i]] << endl;
    }
    return 0;

}