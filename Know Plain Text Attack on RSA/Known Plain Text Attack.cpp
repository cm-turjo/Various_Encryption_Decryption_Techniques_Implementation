#include<bits/stdc++.h>
#include<gmpxx.h>
using namespace std;


mpz_class mod_pow(mpz_class m, mpz_class e, mpz_class n)
{
    mpz_class res=1;
    while(e>0)
    {
        if(e%2 ==1)
        {
            res= (res*m)%n;
        }
        e = e>>1;
        m= (m*m)%n;
    }
    return res;
}




int main()
{
    mpz_class p("12493161794204943211");
    mpz_class q("14932613808869647427");
    mpz_class n=p*q;
    mpz_class phi = (p-1)*(q-1);
    mpz_class e("1");
    mpz_class m("54321");

    mpz_class c =mod_pow(m,e,n);

    mpz_class d("5");
    while(true)
    {
        mpz_class n_m =mod_pow(c,d,n);
        if(n_m ==m)
        {
            cout<<"New Message: "<<n_m<<endl;
            cout<<"Private Key: "<<d<<endl;
            break;
        }
        d++;
    }
    return 0;
}