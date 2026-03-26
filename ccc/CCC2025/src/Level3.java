import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.ArrayList;

public class Level3 {


    private static String nextNonEmpty(String[] lines, int[] index) {
        while (index[0] < lines.length && lines[index[0]].trim().isEmpty()) {
            index[0]++;
        }
        return lines[index[0]++];
    }

    public static void main(String[] args) throws IOException {
        String inputPath = "src/level3_2_large.in";
        String outputPath = "out.txt";
        String[] lines = Files.readAllLines(Path.of(inputPath)).toArray(new String[0]);

        String output = "";


        int[] idx = {0};

        int n = Integer.parseInt(nextNonEmpty(lines, idx));
        ArrayList<String> results = new ArrayList<>();

        for (int a = 0; a < n; a++) {


            String[] parts = nextNonEmpty(lines, idx).split(" ");
            int w = Integer.parseInt(parts[0]);
            int h = Integer.parseInt(parts[1]);
            int limit = Integer.parseInt(parts[2]);

            int totalRows = h + 2;


            String[] ast = new String[totalRows];
            for (int i = 0; i < totalRows; i++) {
                ast[i] = nextNonEmpty(lines, idx);
            }

            int cols = ast[0].length();
            char[][] out = new char[totalRows][cols];
            for (int r = 0; r < totalRows; r++) {
                out[r] = ast[r].toCharArray();
            }


            int firstMineRow = 1;
            int firstMineCol = ast[firstMineRow].indexOf(':');
            int sCol = ast[0].indexOf('S');

            int used = 0;


            if (w == 3) {
                int centerMineCol = firstMineCol + 1;
                int row = 1;
                int col = sCol;


                if (out[row][col] == ':') {
                    out[row][col] = 'X';
                    used++;
                }
                while (col != centerMineCol) {
                    if (col < centerMineCol) col++;
                    else col--;
                    if (out[row][col] == ':') {
                        out[row][col] = 'X';
                        used++;
                    }
                }


                for (int r = 2; r <= h; r++) {
                    if (out[r][centerMineCol] == ':') {
                        out[r][centerMineCol] = 'X';
                        used++;
                    }
                }
            }

            else if (h == 3) {
                int midRow = 2;

                if (out[1][sCol] == ':') {
                    out[1][sCol] = 'X';
                    used++;
                }


                for (int c = firstMineCol; c < firstMineCol + w; c++) {
                    if (out[midRow][c] == ':') {
                        out[midRow][c] = 'X';
                        used++;
                    }
                }
            }


            ArrayList<String> outAst = new ArrayList<>();
            for (int r = 0; r < totalRows; r++) {
                outAst.add(new String(out[r]));
            }
            results.add(String.join("\n", outAst));
        }

        output = String.join("\n\n", results);


        PrintWriter out = new PrintWriter(new FileWriter(outputPath));
        out.println(output);
        out.flush();
    }
}
