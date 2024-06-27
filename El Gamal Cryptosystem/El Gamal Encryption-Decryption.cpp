#include<bits/stdc++.h>
#include<gmpxx.h>
using namespace std;

void solve()
{
    //taking prime 
    mpz_class p("10007");
    //Plain Text Message
    mpz_class m("15");
    //Primitive Element
    mpz_class alpha;
    //Private Key a
    mpz_class a("24");
    //another private key beta
    mpz_class beta;
    //random number k
    mpz_class k("9");

    mpz_class y1, y2;

    //Taking Primitive Root as 2
    alpha =2;

    //Calculating Public Key
    //y1 = (alpha)^ k mod p
    //beta = (alpha)^ a mod p
    mpz_powm(beta.get_mpz_t(), alpha.get_mpz_t(),a.get_mpz_t(),p.get_mpz_t());

    //Encrypt
    mpz_class t;
    mpz_powm(y1.get_mpz_t(), alpha.get_mpz_t(), k.get_mpz_t(), p.get_mpz_t());
    mpz_powm(y2.get_mpz_t(),beta.get_mpz_t(), k.get_mpz_t(), p.get_mpz_t());
    y2= (y2*m)%p;

    //Decrypt
    mpz_powm(t.get_mpz_t(), y1.get_mpz_t(), a.get_mpz_t(),p.get_mpz_t());

    //Extended Eucledean Algorithm to Find Modualar Inverse
    mpz_class inv_t;
    mpz_invert(inv_t.get_mpz_t(), t.get_mpz_t(), p.get_mpz_t());
    mpz_class plain;
    plain = (y2 * inv_t) % p;

    cout<<"Plaintext Before Encryption is: "<< m<<endl;
    cout<<"Plaintext After Encryption is:"<< plain <<endl;

    if( m==plain)
    {
        cout<<"Successful"<<endl;
    }
    else
    {
        cout<<"Failed"<<endl;
    }


}

int main()
{
    solve();
    return 0;
}