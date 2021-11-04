import java.util.*;
abstract class test{
    public test(){
        System.out.println("testfromabstractclass");
    }
    abstract void getparam();
    int param;
}
public class ycy extends test {
    public ycy(){
        super();
    }
    @Override
    void getparam() {
        // TODO Auto-generated method stub
        System.out.print("extends from abstract class");
    }
    public static void main(String[] args) {
        System.out.println("testmain");
    }
}

