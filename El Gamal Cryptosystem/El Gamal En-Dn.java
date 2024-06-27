import java.math.BigInteger;
import java.util.ArrayList;

class variable{
    BigInteger x, y;

    public variable(BigInteger x, BigInteger y) {
        this.x = x;
        this.y = y;
    }
}


class cryptography{

    BigInteger zero = BigInteger.ZERO;
    BigInteger one = BigInteger.ONE;
    public variable ext_gcd(BigInteger A, BigInteger M)
    {
        if(M.equals(zero))return new variable(one,one);
        variable p = ext_gcd(M,A.mod(M));
        BigInteger x = p.y, y = p.x.subtract(A.divide(M).multiply(p.y));
        return new variable(x,y);
    }
    public BigInteger gcd(BigInteger A, BigInteger M)
    {
        variable p = ext_gcd(A,M);
        return A.multiply(p.x).add(M.multiply(p.y));
    }
    public BigInteger primtive(BigInteger A)
    {
        ArrayList<BigInteger> a = new ArrayList<>();
        BigInteger  n=new BigInteger("2");


        while (n.compareTo(A)<0)
        {
            BigInteger i=zero;
            while (i.compareTo(A.subtract(one))<0) {
                if (a.contains(n.modPow(i, A))) {
                    break;
                }
                a.add(n.modPow(i, A));
                i = i.add(one);
            }

            if(i.compareTo(A.subtract(one))==0)
            {
                break;
            }
            a.clear();
            n=n.add(one);
        }
        if(n.equals(A))
        {
            return null;
        }
        return n;
    }
    public void solve()
    {
        BigInteger p=new BigInteger("10007");
        BigInteger m = new BigInteger("15");
        BigInteger alpha = primtive(p);
        BigInteger a = new BigInteger("24");
        BigInteger beta = alpha.modPow(a,p);
        BigInteger k = new BigInteger("9");
        BigInteger y1 = alpha.modPow(k,p);
        BigInteger y2 = (m.mod(p).multiply(beta.modPow(k,p))).mod(p);
        BigInteger t = y1.pow(a.intValue());
        variable t1 =ext_gcd(t,p);
        BigInteger inv = (t1.x.mod(p).add(p)).mod(p);
        BigInteger plain = (y2.mod(p).multiply(inv)).mod(p);
        System.out.println(plain);



    }
}
public class Main {
    public static void main(String[] args) {
        cryptography cryptography = new cryptography();
        cryptography.solve();
    }
}