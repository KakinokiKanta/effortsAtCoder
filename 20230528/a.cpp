// g++ a.cpp -o a
// cat input.txt | ./a ./a < input.txt
#include<bits/stdc++.h>
using namespace std;
 
int main(void){
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    int center_ind = n / 2 + 1;

    for(int i=0; i<(n / 2); i++){
        if((a[i] < a[i+center_ind]) && (a[i+center_ind] > a[i+1])){
            continue;
        }
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;
    return 0;
}