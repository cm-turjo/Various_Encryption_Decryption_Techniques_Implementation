#include <iostream>
#include <gmpxx.h>

using namespace std;

int main() {
    // Given prime number
    mpz_class prime("656692050181897513638241554199181923922955921760928836766304161790553989228223793461834703506872747071705167995972707253940099469869516422893633357693");

    // Find the next prime number
    mpz_nextprime(prime.get_mpz_t(), prime.get_mpz_t());

    // Print the next prime number
    cout << "Next prime number: " << prime << endl;

    return 0;
}
