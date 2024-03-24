package com.zju.learn;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

@SpringBootApplication
public class AccessingDataJpaApplication {
    public static void main(String[] args){
        System.out.println("#################### Starting Spring Boot Application ####################");
        SpringApplication.run(AccessingDataJpaApplication.class,args);
        System.out.println("#################### Start Application successfully!! ####################");
        new Thread(()->System.out.println("123")).run();
    }
}
