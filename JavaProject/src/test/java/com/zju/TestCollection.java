package com.zju;
import java.util.*;
import org.junit.Test;
import static org.junit.Assert.*;

public class TestCollection{
    @Test
    public void testRemoveDuplicate(){
        ArrayList<Integer> m = new ArrayList<>();
        m.add(3);m.add(4);m.add(3);
        m.add(2);m.add(2);m.add(2);
        m.add(5);m.add(1);m.add(3);
        ArrayList<Integer> result = new ArrayList<>();
        result.add(3);result.add(4);result.add(3);
        result.add(5);result.add(1);result.add(3);
        for(Iterator i = m.iterator();i.hasNext();){
            if(i.next().equals(2)){
                i.remove();
            }
        }
        Object[] r1 = result.toArray();
        Object[] r2 = m.toArray();
        assertEquals(r1,r2);
    }
}