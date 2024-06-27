#include <iostream>
#include <gmpxx.h>

using namespace std;

// Function to calculate the greatest common divisor (GCD) using Euclid's algorithm
mpz_class gcd(mpz_class a, mpz_class b) {
    while (b != 0) {
        mpz_class temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    // Taking Large Prime Numbers
    mpz_class p("656692050181897513638241554199181923922955921760928836766304161790553989228223793461834703506872747071705167995972707253940099469869516422893633358353");
    mpz_class q("204616454475328391399619135615615385636808455963116802820729927402260635621645177248364272093977747839601125961863785073671961509749189348777945178129");
    mpz_class n = p * q;
    mpz_class phi = (p - 1) * (q - 1); // Calculating phi

    // Randomly choose g and r
    mpz_class g("13");
    mpz_class r("11"); // taking a random number

    // Ensure r is coprime with n
    while (gcd(r, n) != 1) {
        r++;
    }

    // Calculate lambda directly using the formula: lambda = lcm(p-1, q-1) = (p-1)*(q-1)/gcd(p-1, q-1)
    mpz_class lambda = (phi / gcd(p - 1, q - 1));

    // Calculate mu using the formula: mu = (L(g^lambda mod n^2))^(-1) mod n
    mpz_class n1 = n * n;
    mpz_class l;
    mpz_powm(l.get_mpz_t(), g.get_mpz_t(), lambda.get_mpz_t(), n1.get_mpz_t());
    mpz_class mu;
    mpz_class b1= (l-1)/n;
    mpz_invert(mu.get_mpz_t(), b1.get_mpz_t(), n.get_mpz_t());

    // Public key: (n, g)
    cout << "Public key: (n, g) = (" << n << ", " << g << ")" << endl;

    // Private key: (lambda, mu)
    cout << "Private key: (lambda, mu) = (" << lambda << ", " << mu << ")" << endl;

    // Example Message to be Encrypted
    mpz_class message("118667788");

    // Encryption: cipher = (g^message mod n^2) * (r mod n)^n mod n^2
    mpz_class k1, k2, cipher;
    mpz_powm(k1.get_mpz_t(), g.get_mpz_t(), message.get_mpz_t(), n1.get_mpz_t());
    mpz_powm(k2.get_mpz_t(), r.get_mpz_t(), n.get_mpz_t(), n1.get_mpz_t());
    cipher = (k1 * k2) % n1;
    cout << "Message: " << message << endl;
    cout << "Cipher: " << cipher << endl;

    // Decryption: decrypted = L(cipher^lambda mod n^2) * mu mod n
    mpz_class t1, t2, decrypted;
    mpz_powm(t1.get_mpz_t(), cipher.get_mpz_t(), lambda.get_mpz_t(), n1.get_mpz_t());
    t2 = (t1 - 1) / n;
    decrypted = (t2 * mu) % n;
    cout << "Decrypted Message: " << decrypted << endl;

    // Compare original message with decrypted message
    if (message == decrypted) {
        cout << "Encryption Decryption Successful" << endl;
    } else {
        cout << "Failed" << endl;
    }

    return 0;
}
