import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.ArrayList;

public class Level2 {

    private static String nextNonEmpty(String[] lines, int[] index) {
        while (index[0] < lines.length && lines[index[0]].trim().isEmpty()) {
            index[0]++;
        }
        return lines[index[0]++];
    }

    public static void main(String[] args) throws IOException {
        String inputPath = "src/level2(1)/level2_2_large.in";
        String outputPath = "out.txt";
        String[] lines = Files.readAllLines(Path.of(inputPath)).toArray(new String[0]);

        String output = "";


        int[] idx = {0,};

        int n = Integer.parseInt(nextNonEmpty(lines, idx));
        ArrayList<String> results = new ArrayList<>();

        for (int a = 0; a < n; a++) {


            String[] sizeParts = nextNonEmpty(lines, idx).split(" ");
            int w = Integer.parseInt(sizeParts[0]);
            int h = Integer.parseInt(sizeParts[1]);

            ArrayList<String> ast = new ArrayList<>();


            String first = nextNonEmpty(lines, idx);
            ast.add(first);

            int tunnelCol = first.indexOf('S');


            for (int r = 0; r < h; r++) {
                String row = nextNonEmpty(lines, idx);
                char[] arr = row.toCharArray();
                arr[tunnelCol] = 'X';
                ast.add(new String(arr));
            }


            ast.add(nextNonEmpty(lines, idx));

            results.add(String.join("\n", ast));
        }

        output = String.join("\n\n", results);


        PrintWriter out = new PrintWriter(new FileWriter(outputPath));
        out.println(output);
        out.flush();
    }
}
