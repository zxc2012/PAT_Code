package com.zju.learn.cutomer;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping(path = "api/customer")
public class CustomerController {
    @Autowired
    private CustomerService customerService;

    @GetMapping(value = "all")
    List<Customer> getCustomers(){
        return customerService.getAllCustomers();
    }

    @GetMapping(value = "{id}")
    Customer getCustomer(@PathVariable("id") Integer id){
        return customerService.getCustomer(id);
    }
    @PostMapping(value = "create")
    void registerCustomer(@RequestBody Customer newCustomer){
        customerService.insertCustomer(newCustomer);
    }
    @DeleteMapping(value = "delete/{id}")
    void removeCustomer(@PathVariable("id") Integer id){
        customerService.deleteCustomer(id);
    }
    @PutMapping(value = "update/{id}")
    void updateCustomer(@PathVariable("id") Integer id, @RequestBody Customer updatedCustomer){
        customerService.updateCustomer(id, updatedCustomer);
    }
}