#include<bits/stdc++.h>
#include<gmpxx.h>

using namespace std;


void solve()
{
    //prime number and generator
    mpz_class p("10007");
    mpz_class alpha("2");

    //private key and public key
    mpz_class a("24");
    mpz_class beta;
    mpz_powm(beta.get_mpz_t(),alpha.get_mpz_t(),a.get_mpz_t(),p.get_mpz_t());

    //message to be encrypted

    mpz_class m1("15");
    mpz_class m2("7");

    //random values for encryption
    mpz_class k1("9");
    mpz_class k2("5");

    //encrypt m1
    mpz_class y11,y12;
    mpz_powm(y11.get_mpz_t(), alpha.get_mpz_t(), k1.get_mpz_t(),p.get_mpz_t());
    mpz_class beta_k1;
    mpz_powm(beta_k1.get_mpz_t(), beta.get_mpz_t(), k1.get_mpz_t(),p.get_mpz_t());
    y12 =(beta_k1 *m1)%p;


    mpz_class y21, y22;
    mpz_powm(y21.get_mpz_t(), alpha.get_mpz_t(), k2.get_mpz_t(), p.get_mpz_t());
    mpz_class beta_k2;
    mpz_powm(beta_k2.get_mpz_t(), beta.get_mpz_t(), k2.get_mpz_t(),p.get_mpz_t());
    y22 = (beta_k2*m2)%p;

    //product of ciphers
    mpz_class c1 = (y11*y21)%p;
    mpz_class c2 =(y12*y22)%p;

    //Decrypt Product Cipher
    mpz_class c1_a;
    mpz_powm(c1_a.get_mpz_t(), c1.get_mpz_t(), a.get_mpz_t(), p.get_mpz_t());



    //Finding Modular Inverse of C1_a

    mpz_class inv;
    mpz_invert(inv.get_mpz_t(), c1_a.get_mpz_t(), p.get_mpz_t());
    mpz_class m1m2 = (c2*inv)%p;

    //output 
    cout<<"Original Message m1: "<<m1<<endl;
    cout<<"Original Message m2: "<<m2<<endl;
    cout<<"Product of Two Ciphers "<<m1m2<<endl;

    if(m1m2 == (m1*m2)%p)
    {
        cout<<"Product Successful"<<endl;
    }
    else
    {
        cout<<"Product Failed"<<endl;
    }



}

int main()
{
    solve();
    return 0;

}