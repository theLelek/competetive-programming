// 97 is the largest element

import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

public class Main {


    public static void main(String[] args) {
        String path = "full_input.txt";
        String in = readFile(path);
        String[] splitted = in.split("\n");
        Map<Integer, Set<Integer>> graph = initializeMap(splitted);
        int largestNumber = getLargestNumber(splitted);

        Stack<Integer> stack = new Stack<Integer>();
        stack = topoSort((HashMap<Integer, Set<Integer>>) graph, largestNumber, stack);
        Stack<Integer> reversed = reverse(stack);

        ArrayList<ArrayList<Integer>> unsortedNumbers = getUnsortedNumbers(splitted);
        System.out.println(reversed);
        System.out.println(getSolution(reversed, unsortedNumbers));



    }

    public static int getSolution(Stack<Integer> ruleNumbers, ArrayList<ArrayList<Integer>> unsorted) {
        int sum = 0;
        for (ArrayList<Integer> unsortedLine : unsorted) {
            int[] sorted = new int[ruleNumbers.size()];
            for (int i : unsortedLine) {
                int foo = ruleNumbers.indexOf(i);
                sorted[foo] = i;
            }
            ArrayList<Integer> arrayListSorted = new ArrayList<>();
            for (int element : sorted) {
                if (element != 0) {
                    arrayListSorted.add(element);
                }
            }
            int middleIndex = arrayListSorted.size() / 2;
            int middle_element = arrayListSorted.get(middleIndex);

            boolean hasChanged = false;
            for (int i = 0; i < arrayListSorted.size(); i++) {
                if (unsortedLine.get(i) != arrayListSorted.get(i)) {
                    hasChanged = true;
                    break;
                }
            }
            if (hasChanged) {
                sum += middle_element;
                System.out.println(arrayListSorted);
            }
        }
        return sum;
    }

    public static ArrayList<ArrayList<Integer>> getUnsortedNumbers(String[] input) {
        int idx = 0;
        for (String line : input) {
            if (line.trim().isEmpty()) {
                break;
            }
            idx += 1;
        }
        ArrayList<ArrayList<Integer>> numbers = new ArrayList<ArrayList<Integer>>();

        for (int i = idx + 1; i < input.length; i++) {
            String line = input[i];
            ArrayList<Integer> lineNumbers = new ArrayList<Integer>();
            for (String element : line.split(",")) {
                lineNumbers.add(Integer.valueOf((element)));
            }
            numbers.add(lineNumbers);
        }
        return numbers;
    }

    public static Stack<Integer> reverse(Stack<Integer> arr){
        Stack<Integer> reversed = new Stack<Integer>();
        for (int i = arr.size() - 1; i >= 0; i--) {
                reversed.add(arr.get(i));
        }
        return reversed;
    }

    public static Stack<Integer> topoSort(HashMap<Integer, Set<Integer>> graph, int currentKey, Stack<Integer> stack) {
        // TODO maybe use case for singleton idk :(
        for (Integer next : graph.get(currentKey)) {
            if (next == null) {
                break;
            }

            topoSort(graph, next, stack);
        }
        if (! stack.contains(currentKey)) {
            stack.add(currentKey);
        }
        return stack;
    }

    // TODO why cant change HashMap to HashMap<Integer>
    public static Map<Integer, Set<Integer>> initializeMap(String[] in) {
        Map<Integer, Set<Integer>> graph = new HashMap<>();

        for (String raw : in) {
            if (raw == null) continue;
            String line = raw.trim();
            if (line.isEmpty()) break;

            String[] parts = line.split("\\|");
            if (parts.length != 2) continue;

            int a = Integer.parseInt(parts[0].trim());
            int b = Integer.parseInt(parts[1].trim());

            graph.computeIfAbsent(a, k -> new LinkedHashSet<>()).add(b);
            graph.putIfAbsent(b, new LinkedHashSet<>());
        }

        return graph;
    }

    public static int getLargestNumber(String[] in) {
        HashSet<Integer> rightNumbers = new HashSet<Integer>();
        for (String raw : in) {
            String line = raw.trim();
            if (line.isEmpty()) break;

            String[] parts = line.split("\\|");

            int a = Integer.parseInt(parts[1].trim());
            rightNumbers.add(a);
        }

        for (String raw : in) {
            String line = raw.trim();
            if (line.isEmpty()) break;

            String[] parts = line.split("\\|");
            int a = Integer.parseInt(parts[0].trim());

            if (! rightNumbers.contains(a)) {
                return a;
            }
        }
        return -1;
    }

    private static String readFile(String path) {
        Scanner scanner = null;
        try {
            scanner = new Scanner(new File(path));
        } catch (FileNotFoundException e) {
            throw new RuntimeException(e);
        }
        String in = "";
        while (scanner.hasNext()) {
            in += scanner.nextLine() + "\n";
        }
        return in;
    }
}