import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.nio.file.Files;
import java.nio.file.Path;

import java.util.ArrayList;
import java.util.Arrays;

public class BluePrint {
    public static void main(String[] args) throws IOException {
        String inputPath = "src/level3/level3_1.in";
        String outputPath = "out.txt";
        String[] lines = Files.readAllLines(Path.of(inputPath)).toArray(new String[0]);

        String output = "hello world";

        //solution


        PrintWriter out = new PrintWriter(new FileWriter(outputPath));

        out.println(output);
        out.flush();

    }

}