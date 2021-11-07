import java.util.*;
public interface testinterface {
    int data=3;
    default void testdefault(){
        System.out.println("enter testdefault"+this.data);
    }
    static void teststatic(){
        System.out.println("teststatic from interface");
    }
    int readata(int x);
}
