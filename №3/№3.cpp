#include <iostream> 
#include <vector> 
#include <algorithm>  
using namespace std;


int main() {

    int n;
    int w;//ограничение по массе 
    int c_answ = 0, w_answ = 0;
    cin >> n >> w;

    int** arr = new int* [n + 1];
    int** table = new int* [n + 1];
    for (int i = 0; i <= n; i++) {
        if (i > 0) {
            arr[i] = new int[2];

            cin >> arr[i][0] >> arr[i][1];
        }
        table[i] = new int[w + 1];
        for (int j = 0; j <= w; j++) {
            table[i][j] = 0;
        }
    }





    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= w; j++) {

            if (arr[i][0] > j)
                table[i][j] = table[i - 1][j];
            else
                table[i][j] = max(table[i - 1][j], table[i - 1][j - arr[i][0]] + arr[i][1]);
        }
    }

    int count = 0, i = n, j = w;
    vector<int> answer;
    while (i > 0 && j > 0) {
        if (table[i][j] != table[i - 1][j]) {
            answer.push_back(i);

            w_answ += arr[i][0];
            c_answ += arr[i][1];
            j -= arr[i][0];
            count++;
        }
        i--;
    }

    cout << count << " " << w_answ << " " << c_answ << endl;

    for (int i = count - 1; i >= 0; i--)
        cout << answer[i] << " ";

    cout << endl;

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= w; j++) {
            cout << table[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}