#include<bits/stdc++.h>
#include<gmpxx.h>
using namespace std;

void solve()
{
    mpz_class m1("200"),m2("10");
    mpz_class p("12493161794204943211"), q("14932613808869647427");
    mpz_class n =p*q;
    mpz_class phi = (p-1)*(q-1);

    mpz_class e =p+q;
    
    while(true)
    {
        mpz_class gcd_r;
        mpz_gcd(gcd_r.get_mpz_t(), phi.get_mpz_t(), e.get_mpz_t());
        if(gcd_r ==1)break;
        e=e+1;
    }

    mpz_class d;
    mpz_invert(d.get_mpz_t(), e.get_mpz_t(),phi.get_mpz_t());

    cout<<"Prime -1 is : "<<p<<endl;
    cout<<"Prime -2 is : "<<q<<endl;
    cout<<"phi = p*q "<<phi<<endl;
    cout<<"n = p*q "<<n<<endl;
    cout<<"Encryption key: "<<e<<endl;
    cout<<"Decryption Key: "<<d<<endl;

    mpz_class c1;
    mpz_powm(c1.get_mpz_t(),m1.get_mpz_t(),e.get_mpz_t(),n.get_mpz_t());
    cout<<"Cipher Text for m1: "<<c1<<endl;
    mpz_class c2;
    mpz_powm(c2.get_mpz_t(), m2.get_mpz_t(),e.get_mpz_t(),n.get_mpz_t());
    cout<<"Cipher Text for m2: "<<c2<<endl;
    //product cipher
    mpz_class c;
    c=(c1*c2)%n;

    //Decryption
    mpz_class de1,de2;
    mpz_powm(de1.get_mpz_t(), c1.get_mpz_t(),d.get_mpz_t(), n.get_mpz_t());
    mpz_powm(de2.get_mpz_t(),c2.get_mpz_t(), d.get_mpz_t(),n.get_mpz_t());
    //product of two messages;
    mpz_class de = de1*de2;
    cout<<"m1m2: "<<de<<endl;
    if(de ==(m1*m2)%n)
    {
        cout<<"Product Cipher Successful"<<endl;
    }
    else cout<<"Product Cipher Failed"<<endl;


}


int main()
{
     solve();
    return 0;
}