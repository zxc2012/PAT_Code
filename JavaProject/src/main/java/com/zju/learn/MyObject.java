package com.zju.learn;
public class MyObject {
    protected int age;
    protected void bark(){

    }
    private String name;
}
class smallObject extends MyObject{
    void test(){
        age =4 ;
        bark();
    }
}
