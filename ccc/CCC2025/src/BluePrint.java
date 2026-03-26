import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.nio.file.Files;
import java.nio.file.Path;

import java.util.ArrayList;

public class BluePrint {
    public static void main(String[] args) throws IOException {
        String inputPath = "src/level3/level3_1.in";
        String outputPath = "out.txt";
        String[] lines = Files.readAllLines(Path.of(inputPath)).toArray(new String[0]);

        String output = "";

        //solution
        int n = Integer.parseInt(lines[0]);  // number of asteroids
        ArrayList<String> results = new ArrayList<>();

        for (int i = 1; i <= n; i++) {
            String[] parts = lines[i].split(" ");
            int w = Integer.parseInt(parts[0]); // minable width
            int h = Integer.parseInt(parts[1]); // minable height

            int totalW = w + 2; // + bedrock left + right
            int totalH = h + 2; // + bedrock top + bottom

            StringBuilder asteroid = new StringBuilder();

            // top row
            asteroid.append("#".repeat(totalW)).append("\n");

            // middle rows
            for (int r = 0; r < h; r++) {
                asteroid.append("#");
                asteroid.append(":".repeat(w));
                asteroid.append("#\n");
            }

            // bottom row
            asteroid.append("#".repeat(totalW));

            results.add(asteroid.toString());
        }

        output = String.join("\n\n", results);
        //solution end

        PrintWriter out = new PrintWriter(new FileWriter(outputPath));
        out.println(output);
        out.flush();
    }
}
