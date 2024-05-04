#include<bits/stdc++.h>

#include <gmpxx.h>

using namespace std;

int main() {
    // Taking Large Prime Numbers
    mpz_class p("656692050181897513638241554199181923922955921760928836766304161790553989228223793461834703506872747071705167995972707253940099469869516422893633358353");
    mpz_class q("204616454475328391399619135615615385636808455963116802820729927402260635621645177248364272093977747839601125961863785073671961509749189348777945178129");
    mpz_class n = p * q;
    mpz_class phi = (p - 1) * (q - 1); // Calculating phi

    mpz_class lambda;
    mpz_class g("13");
    mpz_class r("11"); // taking a random number
    mpz_class message("118667788"); // Message to be converted

    // Calculate the GCD of r and n
    mpz_class gcd; 
    mpz_gcd(gcd.get_mpz_t(),r.get_mpz_t(), n.get_mpz_t());

    // Check if the GCD equals 1
    if (gcd != 1) {
        // r and n are not coprime, adjust r to ensure coprimality
     
        mpz_class rand_max(n * n); // Setting maximum value for random number
        gmp_randclass rand(gmp_randinit_default);
        rand.seed(time(NULL)); //random number generator

        // Generate a new random value for r within the appropriate range
        r = mpz_class(rand.get_z_range(rand_max));

        // Recalculate the GCD
        mpz_gcd(gcd.get_mpz_t(),r.get_mpz_t(), n.get_mpz_t());
        // Ensure the new value of r is coprime with n
        while (gcd != 1) {
            r = mpz_class(rand.get_z_range(rand_max));
            mpz_gcd(gcd.get_mpz_t(),r.get_mpz_t(), n.get_mpz_t());
        }
    }

    // Calculate lambda
    mpz_class x = 0, y = 1;
    mpz_class a = p - 1, b = q - 1;
    while (a != 0) {
        mpz_class q = b / a;
        mpz_class t = a;
        a = b % a;
        b = t;
        t = x;
        x = y - q * x;
        y = t;
    }
    lambda = phi / b;

    // Calculate mu
    mpz_class n1 = n * n;
    mpz_class l, mu;
    mpz_powm(l.get_mpz_t(), g.get_mpz_t(), lambda.get_mpz_t(), n1.get_mpz_t());
    mpz_class t = (l - 1) / n;
    mpz_invert(mu.get_mpz_t(), t.get_mpz_t(), n.get_mpz_t());

    // Public key: (n, g)
    cout << "Public key: (n, g) = (" << n << ", " << g << ")" << endl;

    // Private key: lambda
    cout << "Private key: (lambda, mu) = (" << lambda << "," << mu << ")" << endl;

    // Encryption
    mpz_class k1, k2, cipher;
    mpz_powm(k1.get_mpz_t(), g.get_mpz_t(), message.get_mpz_t(), n1.get_mpz_t());
    mpz_powm(k2.get_mpz_t(), r.get_mpz_t(), n.get_mpz_t(), n1.get_mpz_t());
    cipher = (k1 * k2) % n1;
    cout << "Message: " << message << endl;
    cout << "Cipher: " << cipher << endl;

    // Decryption
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
