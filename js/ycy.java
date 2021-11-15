import static org.junit.Assert.assertEquals;

import java.util.*;
import org.junit.Test;
import org.junit.Assert;
abstract class test{
    public test(){
        System.out.println("testfromabstractclass");
    }
    abstract int getparam();
    static int param;
}
public class ycy extends test implements testinterface{
    public ycy(){
        super();
    }
    static void dosomething(){
        System.out.println("do somthing ");
    }
    @Override
    int getparam() {
        // TODO Auto-generated method stub
        super.param =2;
        this.param = 3;
        System.out.println("entergetparam"+param);
        return this.param;
    }
    @Override
    public int readata(int x) {
        // TODO Auto-generated method stub
        return this.data;
    }
    @Test
    public static void main(String[] args) {
        ycy x = new ycy();
        int toassert = x.getparam();
        assertEquals(3, 3);
        System.out.println("testmain");
    }
}

