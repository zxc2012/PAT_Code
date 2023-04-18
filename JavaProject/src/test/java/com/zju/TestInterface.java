package com.zju;
import org.junit.Test;

import com.zju.learn.MyInterface;

import java.util.*;

import static org.junit.Assert.*;
public class TestInterface {
    public record Greetings(String sentence){}
    public Greetings greet(){
        return new Greetings("Hi");
    }
    @Test
    public void testreadata(){
        MyInterface r1 = a->a+1;
        ArrayList<String> m = new ArrayList<String>();
        m.add("12");m.add("test");m.add("");
        m.removeIf(x->x.length()==0);
        assertEquals(2, m.size());
        r1.testdefault();
        MyInterface.teststatic();
        assertEquals(4, r1.readdata(3));
        System.out.println(greet());
    }

}
