// g++ a.cpp -o a
// cat input.txt | ./a ./a < input.txt
#include<bits/stdc++.h>
using namespace std;
 
int main(void){
    int n;
    cin >> n;
    string s;
    cin >> s;

    string result;
    for (int i=0; i<n; i++) {
        result = result + s[i] + s[i];
    }

    cout << result << endl;

    return 0;
}