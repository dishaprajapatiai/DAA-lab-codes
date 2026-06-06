#include <bits/stdc++.h>
using namespace std;

int main() {
    string text, pattern;
    cout << "Enter Text: ";
    cin >> text;
    cout << "Enter Pattern: ";
    cin >> pattern;

    int n = text.length();
    int m = pattern.length();

    bool found = false;

    for(int i = 0; i <= n-m; i++) {
        int j;
        for(j = 0; j < m; j++) {
            if(text[i+j] != pattern[j])
                break;
        }
        if(j == m) {
            cout << "Pattern found at index: " << i << endl;
            found = true;
        }
    }

    if(!found) {
        cout << "Pattern not found!" << endl;
    }

    return 0;
}
