import java.util.*;
public class ycy{
    public static void main(String args[]){
        Refer x= new Refer();
        System.out.println(Refer.age);
        int test[][] = new int [][]{
            {1,2},{3,4},{5,6}
        };
        // System.out.println(test.length);
        for(int p[]:test){
            for(int q:p)System.out.println(q);
            System.out.println("end of line"+p.length);
        }
    }
}
class Refer{
    static int age=3;
}