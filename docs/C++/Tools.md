# Tools
## Maven

POM: project object model

groupId and artifactId

```xml
<project>
  <modelVersion>4.0.0</modelVersion>
 
  <!-- the id of the project's group -->
  <groupId>com.mycompany.app</groupId>
  <!-- the id of the artifact (project)-->
  <artifactId>my-app</artifactId>
  <version>1</version>
</project>
```

Example: 

```
.
 |-- my-module
 |   `-- pom.xml
 `-- parent
     `-- pom.xml
```

Project Inheritance

```xml
<project>
  <!-- pom under my-module -->
  <modelVersion>4.0.0</modelVersion>
 
  <parent>
    <groupId>com.mycompany.app</groupId>
    <artifactId>my-app</artifactId>
    <version>1</version>
    <relativePath>../parent/pom.xml</relativePath>
  </parent>
 
  <!-- groupId the same as parent-->
  <artifactId>my-module</artifactId>
  <!-- version the same as parent>
</project>
```

Project Aggregation

- Change the parent POMs packaging to the value "pom"
- Specify in the parent POM the directories of its modules (children POMs)

```xml
<project>
  <modelVersion>4.0.0</modelVersion>
 
  <groupId>com.mycompany.app</groupId>
  <artifactId>my-app</artifactId>
  <version>1</version>
  <packaging>pom</packaging>
 
  <modules>
    <module>../my-module</module>
  </modules>
</project>
```

## JUnit

```java
@org.junit.Test
org.junit.Assert.assertEquals(expected, actual)
```

It is annoying to type out the name of the library repeatedly,
to avoid this we’ll start every test file with:

```java
import org.junit.Test;
import static org.junit.Assert.*;
```