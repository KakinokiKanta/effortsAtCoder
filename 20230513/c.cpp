
// g++ Template.cpp -o Template
// cat input.txt | ./Template ./Template < input.txt
#include<bits/stdc++.h>
using namespace std;

int main(void){
    string s, t;
    cin >> s;
    cin >> t;

    string ns, nt;
    // int dis_count = 0;
    for(int i = 0; i < s.size(); i++){
        if((s[i] != '@') && (s[i] == t[i])) continue;
        ns = ns + s[i];
        nt = nt + t[i];
        // dis_count++;
    }

    int ind = 0;
    while(ind < ns.size()){
        int i = 0;
        while(i < ns.size()){
            if(ns[ind] == '@') break;
            if(ns[ind] == nt[i]){
                ns.erase(ind, 1);
                nt.erase(i, 1);
                ind--;
                break;
            }
            i++;
        }
        ind++;
    }

    // int at_ind = 0;
    bool flag = true;
    while(ns.size()){
        if((ns[0] != 'a') && (ns[0] != 't') && (ns[0] != 'c') && (ns[0] != 'o') && (ns[0] != 'd') && (ns[0] != 'e') && (ns[0] != 'r') && (ns[0] != '@')){
            cout << "No" << endl;
            return 0;
        }
        if(ns[0] == '@'){
            int i = 0;
            while(i < ns.size()){
                if((nt[i] == 'a') || (nt[i] == 't') || (nt[i] == 'c') || (nt[i] == 'o') || (nt[i] == 'd') || (nt[i] == 'e') || (nt[i] == 'r')){
                    ns.erase(0, 1);
                    nt.erase(i, 1);
                    break;
                }
                i++;
            }
        }else{
            int i = 0;
            while(i < ns.size()){
                if('@' == nt[i]){
                    ns.erase(0, 1);
                    nt.erase(i, 1);
                    flag = false;
                    break;
                }
                i++;
            }
        }
        for(int i = 0; i < ns.size(); i++){
            if(ns[0] == nt[i]){
                ns.erase(0, 1);
                nt.erase(i, 1);
                flag = false;
                break;
            }
        }
        if(!flag) continue;
        cout << "No" << endl;
        return 0;
    }

    if(!ns.size()){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    
    return 0;
}