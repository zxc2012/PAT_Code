import java.util.*;
abstract class test{
    public test(){
        System.out.println("testfromabstractclass");
    }
    abstract void getparam();
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
    void getparam() {
        // TODO Auto-generated method stub
        super.param =2;
        this.param = 3;
        System.out.println("extends from abstract class"+this.param);
    }
    @Override
    public int readata(int x) {
        // TODO Auto-generated method stub
        return this.data;
    }
    public static void main(String[] args) {
        ycy x = new ycy();
        x.getparam();
        x.testdefault();
        x.dosomething();
        System.out.println("testmain");
    }
}

