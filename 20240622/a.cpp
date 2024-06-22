// g++ a.cpp -o a
// cat input.txt | ./a ./a < input.txt
#include<bits/stdc++.h>
using namespace std;
 
int main(void){
  int n;
  cin >> n;

  string s;
  int count = 0;

  for (int i=0; i<n; i++) {
    cin >> s;
    if (s.length() > 4) {
      count++;
    }
  }

  cout << count << endl;

  return 0;
}
