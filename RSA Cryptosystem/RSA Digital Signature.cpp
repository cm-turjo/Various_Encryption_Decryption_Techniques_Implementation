#include<bits/stdc++.h>
#include<gmpxx.h>
using namespace std;

void solve()
{
    mpz_class p("12493161794204943211"), q("14932613808869647427");
    //modulus n

    mpz_class n =p*q;
    mpz_class phi =(p-1)*(q-1);
    //initial e
    mpz_class e =p+q;

    //Finding e (Encryption)

    while(true)
    {
        mpz_class gcd_r;
        mpz_gcd(gcd_r.get_mpz_t(), phi.get_mpz_t(), e.get_mpz_t());
        if(gcd_r ==1) break;
        e=e+1;
    }

    //finding d( decryption key)
    mpz_class d;
    mpz_invert(d.get_mpz_t(), e.get_mpz_t(), phi.get_mpz_t());

     // Print keys
    cout << "Prime-1 (p): " << p << endl;
    cout << "Prime-2 (q): " << q << endl;
    cout << "n = p * q: " << n << endl;
    cout << "phi = (p - 1) * (q - 1): " << phi << endl;
    cout << "Encryption key (e): " << e << endl;
    cout << "Decryption key (d): " << d << endl;

    //input message;
    mpz_class m;
    cout<<"Enter Message: ";
    cin>>m;

    //generating signature
    mpz_class s;
    mpz_powm(s.get_mpz_t(), m.get_mpz_t(), d.get_mpz_t(),n.get_mpz_t());
    cout<<"The Signature is: "<<s<<endl;

    //verifying signature
    mpz_class h;
    mpz_powm(h.get_mpz_t(), s.get_mpz_t(), e.get_mpz_t(),n.get_mpz_t());
    cout<<"Verified Signature: "<<h<<endl;

    if(m==h)
    {
        cout<<"RSA Digital Signature Successfull"<<endl;
    }
    else
    {
        cout<<"RSA Digital Signature Failed"<<endl;
    }
   
}

int main()
{
    solve();
    return 0;
}


