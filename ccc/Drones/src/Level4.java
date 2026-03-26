import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.ArrayList;

public class Level4 {
    public static void main(String[] args) throws IOException {
        String inputPath = "src/level3/level3_1.in";
        String outputPath = "level1Out/out1.txt";
        String[] lines = Files.readAllLines(Path.of(inputPath)).toArray(new String[0]);
        int maxNumberOfTicks = Integer.parseInt(lines[1]);
        String output = "";
        for(int i = 2; i < lines.length; i++) {
            output = output.concat(arrayListToString(getAcceleration(maxNumberOfTicks, Integer.parseInt(lines[i]))) + "\n");
        }

        PrintWriter out = new PrintWriter(new FileWriter(outputPath));

        out.println(output);
        out.flush();

        System.out.println(output);

    }

    public static ArrayList<Integer> getAcceleration(int maxNumberOfTicks, int goalHeight) {
        ArrayList<Integer> acceleration = new ArrayList<>();

        acceleration.add(20);
        int velocity = 10;
        int height = 0;
        while (height < goalHeight) {
            height += velocity;
            acceleration.add(10);
        }

        acceleration.add(0);
        acceleration.add(0);
        while (height > 10) {
            height -= 10;
            acceleration.add(10);
        }
        acceleration.add(11);
        acceleration.add(18);
        if(acceleration.size() > maxNumberOfTicks) {
            throw new IllegalArgumentException("Too many acceleration");
        }
        return acceleration;
    }

    public static String arrayListToString(ArrayList<Integer> acceleration) {
        String solution = "";
        for (Integer integer : acceleration) {
            solution += integer.toString() + " ";
        }
        return solution;
    }
}