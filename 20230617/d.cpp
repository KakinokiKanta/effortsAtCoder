// g++ a.cpp -o a
// cat input.txt | ./a ./a < input.txt
#include<bits/stdc++.h>
using namespace std;
 
int main(void){
    int n;
    cin >> n;

    long long normal_point = 0;
    long long bad_point = 0;
    for (int i=0; i<n; i++) {
        int state;
        long long point;

        cin >> state >> point;
        if (state) {
            if (bad_point < (normal_point + point)) {
                bad_point = normal_point + point;
            }
        } else {
            if (0 < point){
                if (normal_point < bad_point) {
                    normal_point = bad_point + point;
                    bad_point = 0;
                }
            } else {
                if (normal_point < (bad_point + point)) {
                    normal_point = bad_point + point;
                }
            }
        }
    }

    long long result = (normal_point > bad_point) ? normal_point : bad_point;

    cout << result << endl;

    return 0;
}