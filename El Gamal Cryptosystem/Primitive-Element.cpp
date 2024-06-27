#include <bits/stdc++.h>
#include <gmpxx.h>
using namespace std;

void solve() {
    // Find Primitive Root
    mpz_class zero = 0, one = 1;
    vector<mpz_class> a_vals;
    mpz_class n = 2;
    mpz_class p("10007");  // Example prime number
    mpz_class alpha;  // Variable to store the primitive root

    while (n < p) {
        mpz_class i = zero;
        bool is_primitive = true;

        while (i < p - one) {
            mpz_class pow_val;
            mpz_powm(pow_val.get_mpz_t(), n.get_mpz_t(), i.get_mpz_t(), p.get_mpz_t());

            if (find(a_vals.begin(), a_vals.end(), pow_val) != a_vals.end()) {
                is_primitive = false;
                break;
            }
            a_vals.push_back(pow_val);
            i++;
        }

        if (is_primitive && i == p - one) {
            alpha = n;
            break;
        }
        a_vals.clear();
        n++;
    }

    // Output the primitive root found
    cout << "Primitive root of " << p << " is: " << alpha << endl;
}

int main() {
    solve();
    return 0;
    
}
