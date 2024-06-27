#include<bits/stdc++.h>
#include<gmpxx.h>

using namespace std;

void solve()
{
    mpz_class p("12493161794204943211"),q("14932613808869647427");
    mpz_class n;
    n=p*q;
    mpz_class phi;
    phi=(p-1)*(q-1);
    //initial e
    mpz_class e;
    e = p+q;

    //finding e (encryption key)
    while(true)
    {
        mpz_class gcd_r;
        mpz_gcd(gcd_r.get_mpz_t(),phi.get_mpz_t(),e.get_mpz_t());
        if(gcd_r == 1)break;

        e=e+1;
    }
    //Finding d (decryption key)

    mpz_class d;
    mpz_invert(d.get_mpz_t(), e.get_mpz_t(),phi.get_mpz_t());
    cout<<"Prime -1 is : "<<p<<endl;
    cout<<"Prime -2 is : "<<q<<endl;
    cout<<"phi = p*q "<<phi<<endl;
    cout<<"n = p*q "<<n<<endl;
    cout<<"Encryption key: "<<e<<endl;
    cout<<"Decryption Key: "<<d<<endl;
    //message
    mpz_class m("53483");

    //encryption 
    mpz_class c;
    mpz_powm(c.get_mpz_t(), m.get_mpz_t(), e.get_mpz_t(), n.get_mpz_t());
    cout<<"Cipher Text is: "<<c<<endl;
    //decryption
    mpz_class de;
    mpz_powm(de.get_mpz_t(), c.get_mpz_t(), d.get_mpz_t(), n.get_mpz_t());
    cout<<"Decrypted text is: "<<de<<endl;

    if(m ==de)
    {
        cout<<"RSA Successful"<<endl;
    }
    else cout<<"RSA Failed"<<endl;
}

int main()
{
    solve();
    return 0;
}