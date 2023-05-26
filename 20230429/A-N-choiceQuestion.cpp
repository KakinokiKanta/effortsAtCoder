
// g++ Template.cpp -o Template
// cat input.txt | ./Template ./Template < input.txt
#include<bits/stdc++.h>
using namespace std;

int main(void){
    int n, a, b;
    cin >> n >> a >> b;
    
    int sum = a + b;

    int ex;
    int id;
    for(int i = 0; i < n; i++){
        cin >> ex;
        if(ex == sum){
            id = i + 1;
            break;
        }
    }
    
    cout << id << endl;
    return 0;
}