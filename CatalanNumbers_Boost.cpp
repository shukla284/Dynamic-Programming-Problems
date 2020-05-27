
#include<bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>

using boost::multiprecision::cpp_int;
using namespace std;

/*

Author : Shivam Shukla
Description : Catalan Number using Boost Multiprecision Library
*/


// using the relation C(n) = 1 / (n + 1) * C(2 * n, n)
cpp_int catalanNumbers(int n) {
    auto C = [](uint64_t n, uint64_t r) {
        r = min((n - r), r);
        cpp_int res = 1;

        for (cpp_int i = 0; i < r; i++) 
        	res = res * (n - i), res /= (i + 1);
        
        return res;
    }; 

    return C(n << 1, n) / (n + 1);
}

int main(int argc,char** argv){
    
    int t; cin >> t;
    
    while (t--) {
       int n; cin >> n;
       cout << catalanNumbers(n) << endl;       
    }
    
    return 0;		
}