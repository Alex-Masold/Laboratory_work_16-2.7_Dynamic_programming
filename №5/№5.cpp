#define _CRT_SECURE_NO_WARNINGS 
#include <iostream> 
#include <vector> 
#include <algorithm>  
#include <cstdlib> 
using namespace std;

struct Man {
    int time;
    int money;
    int width;

};
int main() {
    int n;
    scanf("%d %*d %*d", &n);
    vector<Man> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i].time);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i].money);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i].width);
    }
    sort(a.begin(), a.end(), [](const Man& left, const Man& right) {
        return left.time < right.time;
        });

    vector<int> max_sum(n, 0);

    for (int i = 0; i < n; i++) 
    {
        if (a[i].width <= a[i].time) 
        {
            max_sum[i] = a[i].money;
            for (int prev = 0; prev < i; prev++) {
                if (abs(a[prev].width - a[i].width) <= a[i].time - a[prev].time) {
                    max_sum[i] = max(max_sum[i], max_sum[prev] + a[i].money);
                }
            }
        }
    }
    int max_s = 0;
    for (int i = 0; i < n; i++) {
        max_s = max(max_s, max_sum[i]);
    }
    cout << max_s;
    return 0;
}