import java.util.*;

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
    void bark(){
        System.out.println(this.name+"barking");
    }
}
class DogAgeCompator implements Comparator<Dog>{

    @Override
    public int compare(Dog o1, Dog o2) {
        return o1.compareTo(o2);
    }
    
}
public class testcompare{
    public static void main(String[] args) {
        Dog[] dogs = {new Dog("monkey",2),new Dog("monika",1),new Dog("Snooby",4)};
        DogAgeCompator dogAgeComparator = new DogAgeCompator();
        Arrays.sort(dogs,dogAgeComparator);
        for (Dog o: dogs){
            o.bark();
        }
    }
}

