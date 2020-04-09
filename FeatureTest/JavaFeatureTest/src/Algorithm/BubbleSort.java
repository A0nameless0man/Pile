package Algorithm;

import java.util.*;

public class BubbleSort {
    public static <T extends Comparable<T>, L extends List<T>> void bSort(L list) {
        Vector<T> ary = new Vector<T>();
        ary.addAll(list);
        for (int i = 0; i < ary.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (ary.get(i).compareTo(ary.get(j)) < 0) {
                    T t = ary.get(i);
                    ary.set(i, ary.get(j));
                    ary.set(j, t);
                }
            }
        }
        list.clear();
        list.addAll(ary);
    }

    public static void main(String[] args) {
        Vector<Integer> vec = new Vector<Integer>();
        for (Integer i = 0; i < 10; ++i)
        {
            vec.add(i);
        }
        Collections.shuffle(vec);
        for (Integer i : vec) {
            System.out.printf("%d ", i);
        }
        System.out.println("");
        bSort(vec);
        for (Integer i : vec) {
            System.out.printf("%d ", i);
        }
        System.out.println("");
    }
}