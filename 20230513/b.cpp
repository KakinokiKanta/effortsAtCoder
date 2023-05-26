
// g++ Template.cpp -o Template
// cat input.txt | ./Template ./Template < input.txt
#include<bits/stdc++.h>
using namespace std;

int main(void){
    int n;
    cin >> n;

    vector<int> a(n, 0);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    vector<int> na;
    int count = 0;
    for(int i = 0; i < n - 1; i++){
        if(a[i] < a[i + 1]){
            na.push_back(a[i]);
            count++;
            for(int j = 1; j < (a[i + 1] - a[i]); j++){
                na.push_back(a[i] + j);
                count++;
            }
        }else{
            na.push_back(a[i]);
            count++;
            for(int j = 1; j < (a[i] - a[i + 1]); j++){
                na.push_back(a[i] - j);
                count++;
            }
        }
    }
    na.push_back(a[n - 1]);
    count++;
    
    for(int i = 0; i < count - 1; i++){
        cout << na[i] << ' ' << flush;
    }
    cout << na[count - 1] << flush;
    cout << endl;
    return 0;
}