import java.util.ArrayList;

import static java.lang.System.currentTimeMillis;

public class Main {
    private static final int MAX_SIZE = 103458;

    public static void main(String[] args) {
        int[] current;
        ArrayList<Double> insertion = new ArrayList<>();
        ArrayList<Double> merge = new ArrayList<>();
        ArrayList<Double> quick = new ArrayList<>();

        for (int i = 0; i < 20; i ++){
            current = generateArray();
            /*System.out.print("before: ");
            printArray(current);*/
            insertion.add(insertionsort(current, MAX_SIZE));
            merge.add(mergesort(current, MAX_SIZE));
            quick.add(quicksort(current, 0, MAX_SIZE-1));

        }
        System.out.println("~~ Total Time ~~ \nInsertion Sort: " + sumList(insertion) + "\n" +
                "Merge Sort: " + sumList(merge) + "\nQuick Sort: " + sumList(quick));

    }

    public static double sumList(ArrayList<Double> TimeVal){
        double totalTime = 0;
        for (Double time: TimeVal) {
            totalTime += time;
        }
        return totalTime;
    }

    //to debug/prove arrays are really being sorted
    public static void printArray(int[] Arr){
        System.out.print("[");
        for (int i = 0; i < Arr.length; i ++){
            System.out.print(Arr[i] + ", ");
        }
        System.out.println("]");
    }

    public static double insertionsort(int[] Arr, int size) {
        double startTime = currentTimeMillis();
        //sort code
        for (int i = 1; i <size; i++){
            int key = Arr[i];
            int j = i - 1;
            while(j >= 0 && Arr[j] > key){
                Arr[j+1] = Arr [j];
                j = j -1;
            }
            Arr[j+1] = key;
        }
        double endTime = currentTimeMillis();
        return (endTime-startTime)*1000;
    }
    public static int[] merge(int[] Arr, int size){

        return new int[MAX_SIZE];
    }
    public static double mergesort(int[] Arr, int size){
        double startTime = currentTimeMillis();
        //sort code


        double endTime = currentTimeMillis();
        return (endTime-startTime)*1000;
    }
    public static int partition(int[] Arr, int p, int r){
        int x = Arr[r];
        int i = p - 1;
        for (int j = p; j < r; j++ ){
            if (Arr[j] <= x) {
                i = i + 1;
                int tmp = Arr[i];
                Arr[i] = Arr[j];
                Arr[j] = tmp;
            }
        }
        int swp = Arr[i+1];
        Arr [i +1] = Arr[r];
        Arr[r] = swp;

        return i+1;
    }
    public static double quicksort(int[] Arr, int p, int r){
        double startTime = currentTimeMillis();
        //sort code
        if (p < r){
            int q = partition(Arr, p, r);
            quicksort(Arr, p, q-1); //stack overflow error
            quicksort(Arr, q+1, r);
        }
        double endTime = currentTimeMillis();
        return (endTime-startTime)*1000;
    }
    public static int[] generateArray(){
        int[] tmp = new int[MAX_SIZE];
        for (int i = 0; i < MAX_SIZE; i ++){
            tmp[i] = (int) (Math.random()*MAX_SIZE);
        }
        return tmp;
    }

}
