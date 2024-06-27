#include <iostream>
#include <cmath>
#include <cassert>

using namespace std;

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long mod_exp(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

long long gcd_extended(long long a, long long b, long long *x, long long *y) {
    if (a == 0) {
        *x = 0;
        *y = 1;
        return b;
    }
    long long x1, y1;
    long long gcd = gcd_extended(b % a, a, &x1, &y1);

    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
}

long long mod_inverse(long long b, long long m) {
    long long x, y;
    long long g = gcd_extended(b, m, &x, &y);
    if (g != 1) return -1;  // No modular inverse exists
    return (x % m + m) % m;
}

int main() {
    long long p = 12493161794204943211ULL, q = 14932613808869647427ULL;
    long long n = p * q;
    long long phi = (p - 1) * (q - 1);
    
    // Initial e
    long long e = p + q;

    // Finding e (encryption key)
    while (gcd(phi, e) != 1) {
        e = e + 1;
    }

    // Finding d (decryption key)
    long long d = mod_inverse(e, phi);
    assert(d != -1); // Ensure modular inverse exists

    cout << "Prime-1 (p): " << p << endl;
    cout << "Prime-2 (q): " << q << endl;
    cout << "phi = (p-1)*(q-1): " << phi << endl;
    cout << "n = p*q: " << n << endl;
    cout << "Encryption key (e): " << e << endl;
    cout << "Decryption key (d): " << d << endl;

    // Message to be encrypted
    long long m = 53483;
    cout << "Original Message: " << m << endl;

    // Encrypt the message
    long long c = mod_exp(m, e, n);
    cout << "Cipher Text: " << c << endl;

    // Decrypt the message
    long long decrypted = mod_exp(c, d, n);
    cout << "Decrypted Text: " << decrypted << endl;

    if (m == decrypted) {
        cout << "RSA Successful" << endl;
    } else {
        cout << "RSA Failed" << endl;
    }

    return 0;
}
