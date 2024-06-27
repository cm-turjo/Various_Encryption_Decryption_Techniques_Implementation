#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "GIVEMESOMEFOOD";
    string key ="ZEBRAS";
    //cin >> key;
    int len = key.size();
    char ch[3][len];
    int k = 0;

    // Fill the plaintext matrix
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < len; ++j) {
            ch[i][j] = s[k++];
        }
    }

    // Print the plaintext matrix
    cout << "Plain matrix is:" << endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < len; ++j) {
            cout << ch[i][j];
        }
        cout << endl;
    }

    // Generate the permutation order
    string sorted_key = key;
    sort(sorted_key.begin(), sorted_key.end());
    vector<int> permutation_order(len);

    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            if (key[j] == sorted_key[i]) {
                permutation_order[i] = j;
                break;
            }
        }
    }

    // Print the cipher matrix using the permutation order
    cout << "Cipher matrix is:" << endl;
    for (int i = 0; i < len; ++i) {
        int col = permutation_order[i];
        for (int j = 0; j < 3; ++j) {
            cout << ch[j][col];
        }
        cout << endl;
    }

    return 0;
}
