import java.awt.image.AreaAveragingScaleFilter;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;

import java.util.ArrayList;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws IOException {
        String input = Files.readString(Path.of("src/input2.txt"));
        String output = "";
        String[] splitted = input.split("\n");



        for (int i = 1; i < splitted.length; i++) {
           String currentVelocities = splitted[i];
           String[] currentVelocitiesArray = currentVelocities.split(" ");
           int[] lineNumbers = stringArrayToInt(currentVelocitiesArray);


           output += String.valueOf(getHeight(lineNumbers) + "\n");



        }
        System.out.println(output);
        Files.writeString(Path.of("src/output.txt"), output);
    }

    public static int getHeight(int[] acceleraions) {
        int velocity = 0;
        int acceleraion = 0;
        int height = 0;
        final int gravity = 10;

        for (int i = 0; i < acceleraions.length; i++) {
            acceleraion = acceleraions[i];
            velocity += acceleraion - gravity;
            height += velocity;
        }
        return height;
    }

    public static int getSumOfArray(int[] array) {
        int sum = 0;
        for (int i = 0; i < array.length; i++) {
            sum += array[i];
        }
        return sum;
    }

    public static int[] stringArrayToInt(String[] array) {
        int[] intArray = new int[array.length];
        for (int i = 0; i < array.length; i++) {
            intArray[i] = Integer.parseInt(array[i]);
        }
        return intArray;
    }
}