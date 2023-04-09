package com.zju.learn;
import java.util.*;
public class MyCollection {
    public static void main(String args[]){
        String s[]= {"You","Complete","Me"};
        ArrayList<String> toS =  new ArrayList<>(Arrays.asList(s));
        for(String p:toS)System.out.println(p);
    }
}
