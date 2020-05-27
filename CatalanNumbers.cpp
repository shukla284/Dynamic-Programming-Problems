
#include<bits/stdc++.h>
using namespace std;

/*

Author : Shivam Shukla
Description : Catalan Number
*/


// using the relation C(n) = 1 / (n + 1) * C(2 * n, n)
uint64_t catalanNumbers(int n) {
    auto C = [](uint64_t n, uint64_t r) {
        r = min((n - r), r);
        uint64_t res = 1;

        for (uint64_t i = 0; i < r; i++) 
        	res = res * (n - i), res /= (i + 1);
        
        return res;
    }; 

    return C(n << 1, n) / (n + 1);
}


int main(int argc,char** argv){
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);

    int n; cin >> n;
    cout << catalanNumbers(n) << endl;   
    
    return 0;		
}