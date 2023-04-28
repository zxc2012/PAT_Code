package com.zju.learn.cutomer;

import jakarta.persistence.Column;
import jakarta.persistence.Entity;
import jakarta.persistence.GeneratedValue;
import jakarta.persistence.GenerationType;
import jakarta.persistence.Id;
import jakarta.persistence.SequenceGenerator;

@Entity
public class Customer {
    @Id
    @SequenceGenerator(name= "customer_id_sequence",sequenceName = "customer_id_sequence")
    @GeneratedValue(strategy = GenerationType.SEQUENCE,generator = "customer_id_sequence")
    private Integer id;
    @Column(
        nullable = false
    )
    private String name;
    private String email;

    private Integer age;

    public Customer() {

    }

    public Customer(String name, String email, Integer age){
        this.name = name;
        this.email = email;
        this.age = age;
    }

    public Integer getId() {
        return id;
    }

    public void setId(Integer id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public Integer getAge() {
        return age;
    }

    public void setAge(Integer age) {
        this.age = age;
    }

    @Override
    public String toString() {
        return "Customer [id=" + id + ", name=" + name + ", email=" + email + ", age=" + age + "]";
    }    
    
}
