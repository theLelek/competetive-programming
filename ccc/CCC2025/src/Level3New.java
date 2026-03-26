import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.nio.file.Files;
import java.nio.file.Path;

import java.util.ArrayList;
import java.util.Arrays;

public class Level3New {
    public static void main(String[] args) throws IOException {
        String inputPath = "src/level4(1)/level4_0_example.in";
        String outputPath = "out.txt";
        String[] lines = Files.readAllLines(Path.of(inputPath)).toArray(new String[0]);

        String output = "hello world";

        int n = Integer.parseInt(lines[0]);

        int lineCounter = 1;
        for(int i = 0; i< n; i++){
            String[] firstLine = lines[lineCounter].split(" ");
            int width = Integer.parseInt(firstLine[0]);
            int height = Integer.parseInt(firstLine[1]);
            int digLimit = Integer.parseInt(firstLine[2]);
            char[][] input = toCharArray(lines, lineCounter + 1, lineCounter + 3 + height);
            char[][] solution = getSolution(input);
            lineCounter += 4 + height;



        }








        PrintWriter out = new PrintWriter(new FileWriter(outputPath));

        out.println(output);
        out.flush();

    }

    public static char[][] toCharArray(String[] stringArray, int start, int end) {
        char[][] charArray = new char[end - start][stringArray[start].length()];
        for (int i = start; i < end; i++) {
            for (int j = 0; j < stringArray[i].length(); j++) {
                charArray[i - start][j] = stringArray[i].charAt(j);
            }
        }
        return charArray;
    }

    public static char[][] getSolution(char[][] charArray) {
        int outpostIndex = -1;
        for (int i = 0; i < charArray[0].length; i++) {
            if (charArray[0][i] == 'S') {
                outpostIndex = i;
            }
        }

        charArray[1][outpostIndex] = 'x';

        for (int i = 2; i < charArray.length; i++) {
            if ((i + 1)% 3 == 0) {
                for (int j = 1; j < charArray[i].length; j++) {
                    charArray[i][j] = 'x';
                }
            } else {
                charArray[i][1] = 'x';
            }
        }
        return charArray;
    }

}