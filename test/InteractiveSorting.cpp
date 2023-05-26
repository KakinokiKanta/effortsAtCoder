#include<bits/stdc++.h>
using namespace std;

int main(void){
    int n, q;
    cin >> n >> q;

    vector<char> alphabet(0);
    int count = 0;
    for(char alpha = 'A'; alpha <= 'Z'; alpha++){
        if(n <= count) break;
        alphabet.push_back(alpha);
        count++;
    }

    int id_count = 0;
    int minus_count = 2;
    for(int i = 0; i < q; i++){
        cout << "? " << alphabet[id_count] << " " << alphabet[id_count + 1] << endl;

        char comparison;
        cin >> comparison;

        char tmp_char;
        if(comparison == '>'){
            tmp_char = alphabet[id_count];
            alphabet[id_count] = alphabet[id_count + 1];
            alphabet[id_count + 1] = tmp_char;
        }

        id_count++;
        if(n <= id_count + 1){
            id_count -= (n - minus_count);
            minus_count++;
        }
        if(minus_count > n) break;
    }

    string ans;
    for(int i = 0; i < n; i++){
        ans.push_back(alphabet[i]);
    }

    cout << "! " << ans << endl;

    return 0;
}