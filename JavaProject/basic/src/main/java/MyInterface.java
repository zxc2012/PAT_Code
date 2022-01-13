import java.util.*;
public interface MyInterface {
    default void testdefault(){
        System.out.println("enter testdefault");
    }
    static void teststatic(){
        System.out.println("teststatic from interface");
    }
    int readdata(int x);
}