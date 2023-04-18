package com.zju;
import java.util.*;
import org.junit.Test;
import static org.junit.Assert.*;

class Dog implements Comparable<Dog>{
    private String name = "";
    private int age = 0;
    Dog(String name,int age){
        this.name = name;
        this.age = age;
    }
    public int getAge() {
        return age;
    }
    @Override
    public int compareTo(Dog o) {
        // TODO Auto-generated method stub
        return this.age - o.age;
    }
    protected void bark(){
        System.out.println(this.name+"barking");
    }
}
public class Testcompare{
    @Test
    public void testbark(){
        Dog[] dogs = {new Dog("monkey",2),new Dog("monika",1),new Dog("Snooby",4)};
        Arrays.sort(dogs,(Dog o1,Dog o2)->o1.compareTo(o2));
        for (Dog o: dogs){
            o.bark();
        }
        assertEquals(3,3);
    }
}

