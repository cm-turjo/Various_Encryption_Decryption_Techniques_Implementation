#include<bits/stdc++.h>
#include<gmpxx.h>
using namespace std;

void solve()
{
    //prime number p
    mpz_class p("10007");

    //message to be signed
    mpz_class m("12345");
    //primitive root alpha
    mpz_class alpha("2");

    //private key a
    mpz_class a("24");
    //random number k
    mpz_class k("9");

    //public key beta
    //beta = alpha^a mod p;
    mpz_class beta;
    mpz_powm(beta.get_mpz_t(), alpha.get_mpz_t(),a.get_mpz_t(),p.get_mpz_t());

    //signature generation
    mpz_class y1,y2, k_inv;

    //y1 =alpha ^ k mod p;
    mpz_powm(y1.get_mpz_t(), alpha.get_mpz_t(), k.get_mpz_t(), p.get_mpz_t());
    mpz_class q;
    q=p-1;
    mpz_invert(k_inv.get_mpz_t(), k.get_mpz_t(),q.get_mpz_t());

    //y2 = (m-a*y1)k^-1 mod p;
    mpz_class temp = (m -a*y1)%(p-1);
    y2 = (temp*k_inv)% (p-1);

    //to ENsure y2 is positive
    if( y2<0)
    {
        y2+=(p-1);
    }

    //Signature Verificaiton
    mpz_class left, right, temp1, temp2;
    //left = (beta^y1 * y1^y2)mod p;

    mpz_powm(temp1.get_mpz_t(), beta.get_mpz_t(), y1.get_mpz_t(),p.get_mpz_t());
    mpz_powm(temp2.get_mpz_t(),y1.get_mpz_t(),y2.get_mpz_t(),p.get_mpz_t());

    left = (temp1*temp2)% p;

    //right
    //alpha^m mod p
    mpz_powm(right.get_mpz_t(),alpha.get_mpz_t(),m.get_mpz_t(),p.get_mpz_t());

    //output results
    cout<<"Message "<<m<<endl;
    cout<<"Signature: (y1,y2) = ( "<<y1<<" , "<<y2<<")"<<endl;

    if(left ==right)
    {
        cout<<"Verification Successful"<<endl;
    }
    else
    {
        cout<<"Verification Failed"<<endl;
    }


}


int main()
{
    solve();
    return 0;
}
