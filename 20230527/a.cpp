// g++ a.cpp -o a
// cat input.txt | ./a ./a < input.txt
#include<bits/stdc++.h>
using namespace std;
 
int main(void){
    int n;
    cin >> n;
    string s, t;
    cin >> s;
    cin >> t;
    bool flag = true;

    for(int i = 0; i < n; i++){
        if((s[i] == t[i]) || ((s[i] == '1' && t[i] == 'l') || (s[i] == 'l' && t[i] == '1') || (s[i] == '0' && t[i] == 'o') || (s[i] == 'o' && t[i] == '0'))){
            continue;
        }
        flag = false;
    }

    if(flag){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}