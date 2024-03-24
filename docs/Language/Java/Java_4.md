# 4 Concurrency
## Thread Object

Runnable and Thread

```java
@FunctionalInterface
public interface Runnable{
    void run();
}
public class Thread implements Runnable{
    Thread(Runnable task);
    static Thread currentThread();
    final String getName();
    Thread.State getState();
    final int getPriority();
    final void join();//Waits for this thread to terminate.
    void run();
    static void sleep(long millis);
    void start();//A thread can be started at most once. Throws IllegalThreadStateException if the thread was already started
    static void yield();//the current thread is willing to yield
}
public class HelloRunnable implements Runnable {

    public void run() {
        System.out.println("Hello from a thread!");
    }

    public static void main(String args[]) {
        new Thread(new HelloRunnable()).start();
        //写法2
        new Thread(()->System.out.println("Hello from a thread!")).start();
    }

}
```

join

- Schedules thread4 to begin execution. Thread4 will execute independently of the main thread
- join waits for thread4 to finish

![20230426214421](https://raw.githubusercontent.com/zxc2012/image/main/20230426214421.png)

Interrupt

```java
public class A implements Runnable
{
    public void run(){
        try {
            Thread.sleep(2000);
        } 
        catch (InterruptedException ie) {
            ie.printStackTrace(); // interrupt sleep
        }
        System.out.println("Hello Java");
        System.out.println(Thread.currentThread());
    }
    public static void main(String[] args) {
        A a = new A();
        Thread t = new Thread(a, "Child Thread");
        t.start();
        t.interrupt();
    }
}
```

## Synchronization

It is not possible for two invocations of synchronized methods on the same object to interleave

```java
public class SynchronizedCounter {
    private int c = 0;

    //Synchronized Method: The lock release occurs even if the return was caused by an uncaught exception
    public synchronized void increment() {
        c++;
    }

    public synchronized void decrement() {
        c--;
    }

    public synchronized int value() {
        return c;
    }
}
public class MsLunch {
    private long c1 = 0;
    private long c2 = 0;
    private Object lock1 = new Object();
    private Object lock2 = new Object();

    public void inc1() {
        synchronized(lock1) {
            c1++;
        }
    }

    public void inc2() {
        synchronized(lock2) {
            c2++;
        }
    }
}

```