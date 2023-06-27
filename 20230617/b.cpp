// g++ a.cpp -o a
// cat input.txt | ./a ./a < input.txt
#include<bits/stdc++.h>
using namespace std;
 
int main(void){
    vector<unsigned long long> a(64);
    unsigned long long result = 0;
    for (int i=0; i<64; i++) {
        cin >> a[i];
        unsigned long long pow_a = 1;
        for (int j=1; j<=i; j++) {
            pow_a *= 2;
        }
        result += (a[i] * pow_a);
    }

    cout << result << endl;

    return 0;
}