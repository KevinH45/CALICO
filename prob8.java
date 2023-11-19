import java.util.*;
import java.io.*;

public class prob8 {

    public static void main(String[] args){
        Scanner scan = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

        int t= scan.nextInt();
        for (int i=0; i<t;i++){
            solve_test(scan, pw);
        }
        pw.close();
        scan.close();
    }
    public static void solve_test(Scanner scan, PrintWriter pw){

        int n = scan.nextInt();
        int m = scan.nextInt();
        int k = scan.nextInt();

        HashSet<Integer> subway = new HashSet<>();
        List<TreeSet<Integer>> starting = new ArrayList<>();
        List<TreeSet<Integer>> ending = new ArrayList<>();

        for (int i = 0; i < m; i++) {
            starting.add(new TreeSet<>());
            ending.add(new TreeSet<>());
        }
        for (int i=0; i<n; i++){
            int x = scan.nextInt();
            starting.get(x-1).add(i);
        }

        for (int i=0; i<n; i++){
            int x = scan.nextInt();
            ending.get(x-1).add(i);
        }

        int currentPassengers = n;
        int travelled = 0;
        int ptr = 0;

        while (currentPassengers > 0){
            
            for (int passenger: ending.get(ptr)){
                if (subway.contains(passenger)){
                    subway.remove(passenger);
                    ending.remove(passenger);
                    currentPassengers --;
                }
            } 
            
            while (subway.size()<k && !starting.get(ptr).isEmpty()){
                subway.add(starting.get(ptr).pollFirst());
            }

            travelled++;
            ptr = (ptr+1)%(m);
        }
        pw.println(travelled-1); // - the last station travelled
    }
}