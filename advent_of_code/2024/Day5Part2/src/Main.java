// 11145,
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        String input = Files.readString(Path.of("large_input.txt"));
        String[] inputParts = input.split("\n\n");
        graph = getAdjacencyList(inputParts[0]);
        List<List<Integer>> numbers = getNumbers(inputParts[1]);
        int ans = 0;

        for (List<Integer> currentNumbers : numbers) {
            allowedNumbers = new HashSet<>(currentNumbers);
            for (int i : currentNumbers) {
                topoSort(i);
            }
            if (! sorted.equals(currentNumbers)) {
                ans += sorted.get(sorted.size() / 2);
            }
            // todo print middle of sorted
            allowedNumbers = new HashSet<>();
            visited = new HashSet<>();
            sorted = new ArrayList<>();
        }
        System.out.println(ans);
    }

    static Set<Integer> allowedNumbers = new HashSet<>();
    static Set<Integer> visited = new HashSet<>();
    static List<Integer> sorted = new ArrayList<>();
    static Map<Integer, List<Integer>> graph;

    public static void topoSort(int currentElement) {
        if (visited.contains(currentElement)) {
            return;
        }
        visited.add(currentElement);
        if (! graph.containsKey(currentElement)) {
            sorted.add(currentElement);
            return;
        }
        for (int element : graph.get(currentElement)) {
            if (allowedNumbers.contains(element)) {
                topoSort(element);
            }
        }
        sorted.add(currentElement);
    }

    public static Map<Integer, List<Integer>> getAdjacencyList(String orderingRules) {
        Map<Integer, List<Integer>> adjacencyList = new HashMap<>();
        for (String line : orderingRules.split("\n")) {
            String[] parts = line.split("\\|");
            int key = Integer.parseInt(parts[0]);
            int value = Integer.parseInt(parts[1]);
            // graph is reversed
            if (! adjacencyList.containsKey(value)) {
                adjacencyList.put(value, new ArrayList<>());
            }
            adjacencyList.get(value).add(key);
        }
        return adjacencyList;
    }

    public static List<List<Integer>> getNumbers(String stringNumbers) {
        List<List<Integer>> numbers = new  ArrayList<>();
        for (String line : stringNumbers.split("\n")) {
            List<Integer> foo = Arrays.stream(line.split(",")).map(Integer::parseInt).toList();
            numbers.add(foo);
        }
        return numbers;
    }
}