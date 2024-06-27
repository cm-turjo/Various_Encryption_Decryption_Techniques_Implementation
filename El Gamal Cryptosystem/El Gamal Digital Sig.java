import java.math.BigInteger;
import java.util.ArrayList;

class  variable{
    BigInteger x, y;

    public variable(BigInteger x, BigInteger y) {
        this.x = x;
        this.y = y;
    }
}
class elgamal_digital_security{

    BigInteger zero = BigInteger.ZERO;
    BigInteger one = BigInteger.ONE;
    public variable ext_gcd ( BigInteger A, BigInteger M)
    {
        if(M.equals(zero))
            return new variable(one,one);
        variable p = ext_gcd(M, A.mod(M));
        BigInteger x = p.y, y = p.x.subtract(A.divide(M).multiply(p.y));

        return (new variable(x,y));
    }
    public BigInteger gcd( BigInteger A, BigInteger M)
    {
        variable p = ext_gcd(A,M);
        return A.multiply(p.x).add(M.multiply(p.y));
    }

    public BigInteger prim(BigInteger num)
    {
        BigInteger res= new BigInteger("2");

        ArrayList<BigInteger> a = new ArrayList<>();

        while (res.compareTo(num)<0)
        {
            BigInteger i = zero;
            while (i.compareTo(num.subtract(one))<0)
            {
                if(a.contains(res.modPow(i,num)))
                {

                    break;
                }
                a.add(res.modPow(i,num));
                i=i.add(one);
            }
            a.clear();
            if(i.compareTo(num.subtract(one))==0)
                break;
            res=res.add(one);
        }
        return res;
    }

    public void solve()
    {
        BigInteger p = new BigInteger("10007");
        BigInteger alpha = prim(p);
        BigInteger a = new BigInteger("17");
        BigInteger k = new BigInteger("9");
        BigInteger beta = alpha.modPow(a,p);
        BigInteger message = new BigInteger("1234");
        BigInteger y1 = alpha.modPow(k,p);
        BigInteger y2 = (message.subtract(a.multiply(y1))).mod(p.subtract(one));

        variable p1 = ext_gcd(p.subtract(one),k);

        BigInteger inv = p1.y.mod(p.subtract(one)).add(p.subtract(one)).mod(p.subtract(one));

        y2 = y2.multiply(inv).mod(p.subtract(one));

        BigInteger left = (y1.modPow(y2,p).multiply(beta.modPow(y1,p))).mod(p);
        BigInteger right = alpha.modPow(message,p);

        System.out.println(left+" "+right);

    }
}
public class El Gamal Digital Sig {
    public static void main(String[] args) {
        elgamal_digital_security e = new elgamal_digital_security();
        e.solve();
    }
}



