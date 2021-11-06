import java.util.*;
abstract class test{
    public test(){
        System.out.println("testfromabstractclass");
    }
    abstract void getparam();
    static int param;
}
public class ycy extends test {
    public ycy(){
        super();
    }
    @Override
    void getparam() {
        // TODO Auto-generated method stub
        super.param =2;
        this.param = 3;
        System.out.println("extends from abstract class"+this.param);
    }
    public static void main(String[] args) {
        ycy x = new ycy();
        x.getparam();
        System.out.println("testmain");
    }
}

