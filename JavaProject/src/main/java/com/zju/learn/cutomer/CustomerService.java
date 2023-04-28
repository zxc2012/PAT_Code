package com.zju.learn.cutomer;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.zju.learn.exception.DuplicateResourceException;
import com.zju.learn.exception.ResourceNotFound;

@Service
public class CustomerService {

    @Autowired
    private CustomerRepository customerRepository;

    public List<Customer> getAllCustomers(){
        return customerRepository.findAll();
    }
    public Customer getCustomer(Integer id){
        return customerRepository.findById(id).orElseThrow(
            ()->new ResourceNotFound("customer with id[%s] not found".formatted(id))
        );
    }
    public void insertCustomer(Customer customer){
        if(customerRepository.existsCustomerByName(customer.getName()))
            throw new DuplicateResourceException("customer whith id[%s] exists".formatted(customer.getId()));
        customerRepository.save(new Customer(
            customer.getName(),
            customer.getEmail(),
            customer.getAge()
        ));
    }

    public void deleteCustomer(Integer customerid){
        if(customerRepository.existsById(customerid)){
            customerRepository.deleteById(customerid);
        }
        else throw new ResourceNotFound("customer with id[%s] not found".formatted(customerid));
    }

    public void updateCustomer(Integer customerid, Customer updatedCustomer){
        Customer previousCustomer = customerRepository.findById(customerid)
                            .orElseThrow(
                                ()->new ResourceNotFound("customer with id[%s] not found".formatted(customerid)
                            ));
        if(updatedCustomer.getName()!=null){
            previousCustomer.setName(updatedCustomer.getName());
        }
        if(updatedCustomer.getEmail()!=null){
            previousCustomer.setEmail(updatedCustomer.getEmail());
        }
        if(updatedCustomer.getAge()!=null){
            previousCustomer.setAge(updatedCustomer.getAge());
        }
        customerRepository.save(previousCustomer);
    }
}
