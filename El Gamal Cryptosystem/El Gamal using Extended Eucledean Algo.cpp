#include <iostream>
#include <gmpxx.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

void solve() {
    mpz_class p("10007");
    mpz_class m("15");  // Plaintext message
    mpz_class alpha;     // Generator
    mpz_class a("24");   // Private key
    mpz_class beta;      // Public key
    mpz_class k("9");    // Random value for encryption
    mpz_class y1, y2;

    // Find primitive root
    mpz_class zero = 0, one = 1;
    vector<mpz_class> a_vals;
    mpz_class n = 2;
    while (n < p) {
        mpz_class i = zero;
        while (i < p - one) {
            mpz_class pow_val;
            mpz_powm_ui(pow_val.get_mpz_t(), n.get_mpz_t(), i.get_ui(), p.get_mpz_t());
            if (find(a_vals.begin(), a_vals.end(), pow_val) != a_vals.end()) {
                break;
            }
            a_vals.push_back(pow_val);
            i++;
        }
        if (i == p - one) {
            alpha = n;
            break;
        }
        a_vals.clear();
        n++;
    }

    // Calculate public key
    mpz_powm(beta.get_mpz_t(), alpha.get_mpz_t(), a.get_mpz_t(), p.get_mpz_t());

    // Encrypt
    mpz_powm(y1.get_mpz_t(), alpha.get_mpz_t(), k.get_mpz_t(), p.get_mpz_t());
    mpz_powm(y2.get_mpz_t(), beta.get_mpz_t(), k.get_mpz_t(), p.get_mpz_t());
    y2 = (y2 * m) % p;

    // Decrypt
    mpz_class t;
    mpz_powm(t.get_mpz_t(), y1.get_mpz_t(), a.get_mpz_t(), p.get_mpz_t());

    mpz_class inv;
    mpz_class temp;
    mpz_class x = 0, y = 1;
    mpz_class original_p = p; // Store original value of p
    while (t != 0) {
        mpz_class q = p / t;
        mpz_class new_t = p - q * t;
        mpz_class new_x = x - q * y;
        x = y;
        y = new_x;
        p = t;
        t = new_t;
    }
    if (p == 1) {
        inv = (x % original_p + original_p) % original_p; // Use original_p for modulo
    } else {
        throw invalid_argument("Modular inverse does not exist");
    }

    mpz_class plain = (y2 * inv) % original_p;

    // Output
    cout << "Plaintext before encryption: " << m << endl;
    cout << "Plaintext after decryption: " << plain << endl;

    if (m == plain) {
        cout << "Encryption-decryption process is successful." << endl;
    } else {
        cout << "Encryption-decryption process has failed." << endl;
    }
}

int main() {
    solve();
    return 0;
}
