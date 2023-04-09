# Java8 Features
## Optional

Before Java 8, any number of operations involving accessing an object’s methods or properties could result in a NullPointerException:

```java
String isocode = user.getAddress().getCountry().getIsocode().toUpperCase();
```

- Create Optional(Of, OfNullable)
    - Optional<User> opt = Optional.ofNullable(user);
- ReturnValues
    - Optional.ofNullable(user).ifPresent(u -> logger.info("User is:" + u.getEmail()))
    - Optional.ofNullable(user).orElse(createNewUser());
    - Optional.ofNullable(user).ifPresentOrElse( u -> logger.info("User is:" + u.getEmail()), () -> logger.info("User not found"));

## Stream

Streams are wrappers around a data source, allowing us to operate with that data source and making bulk processing convenient and fast.

Stream pipeline: 

- source: A collection, an array, a generator function, or an I/O channel.
- Zero or more intermediate operations: An intermediate operation, such as filter, produces a new stream.
- A terminal operation: produces a non-stream result, such as a primitive value (like a double value), a collection.

### Method

forEach() is a terminal function. After the operation is performed, the stream pipeline is considered consumed

```java
@Test
public void whenIncrementSalaryForEachEmployee_thenApplyNewSalary() {    
    empList.stream().forEach(e -> e.salaryIncrement(10.0));
    
    assertThat(empList, contains(
      hasProperty("salary", equalTo(110000.0)),
      hasProperty("salary", equalTo(220000.0)),
      hasProperty("salary", equalTo(330000.0))
    ));
}
```

The strategy for collect() is provided via the *Collector* interface implementation. In the example below, we used the toList collector to collect all Stream elements into a List instance.

```java
@Test
public void whenFindFirst_thenGetFirstEmployeeInStream() {
    Integer[] empIds = { 1, 2, 3, 4 };
    
    List<Employee> employees = Stream.of(empIds)
      .map(employeeRepository::findById)
      .filter(e -> e != null)
      .filter(e -> e.getSalary() > 200000)
      .collect(Collectors.toList());
    
    assertEquals(Arrays.asList(arrayOfEmps[2]), employees);
}
```

findFirst() returns an Optional for the first entry in the stream; the Optional can, of course, be empty.

```java
@Test
public void whenFindFirst_thenGetFirstEmployeeInStream() {
    Integer[] empIds = { 1, 2, 3, 4 };
    
    Employee employee = Stream.of(empIds)
      .map(employeeRepository::findById)
      .filter(e -> e != null)
      .filter(e -> e.getSalary() > 100000)
      .findFirst()
      .orElse(null);
    
    assertEquals(employee.getSalary(), new Double(200000));
}
```

We saw forEach() earlier in this section, which is a terminal operation. However, sometimes we need to perform multiple operations on each element of the stream before any terminal operation is applied.

peek() is a intermediate operation

```java
@Test
public void whenIncrementSalaryUsingPeek_thenApplyNewSalary() {
    Employee[] arrayOfEmps = {
        new Employee(1, "Jeff Bezos", 100000.0), 
        new Employee(2, "Bill Gates", 200000.0), 
        new Employee(3, "Mark Zuckerberg", 300000.0)
    };

    List<Employee> empList = Arrays.asList(arrayOfEmps);
    
    empList.stream()
      .peek(e -> e.salaryIncrement(10.0))
      .peek(System.out::println)
      .collect(Collectors.toList());

    assertThat(empList, contains(
      hasProperty("salary", equalTo(110000.0)),
      hasProperty("salary", equalTo(220000.0)),
      hasProperty("salary", equalTo(330000.0))
    ));
}
```

### Lazy Evaluation

Computation on the source data is only performed when the terminal operation is initiated, and source elements are consumed only as needed.

All intermediate operations are lazy, so they’re not executed until a result of a processing is actually needed.

**Short-circuiting**:When findFirst() meets, the remaining employees will not evalute.

```java
@Test
public void whenFindFirst_thenGetFirstEmployeeInStream() {
    Integer[] empIds = { 1, 2, 3, 4 };
    
    Employee employee = Stream.of(empIds)
      .map(employeeRepository::findById)
      .filter(e -> e != null)
      .filter(e -> e.getSalary() > 100000)
      .findFirst()
      .orElse(null);
    
    assertEquals(employee.getSalary(), new Double(200000));
}
```