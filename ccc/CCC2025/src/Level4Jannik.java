import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.nio.file.Files;
import java.nio.file.Path;

import java.util.ArrayList;
import java.util.Arrays;

public class Level4Jannik {
    public static void main(String[] args) throws IOException {
        String inputPath = "src/level4(1)/level4_1_small.in";
        String outputPath = "out.txt";
        String[] lines = Files.readAllLines(Path.of(inputPath)).toArray(new String[0]);

        String output = "";

        int n = Integer.parseInt(lines[0]);

        int lineCounter = 1;
        for(int i = 0; i< n; i++){
            String[] firstLine = lines[lineCounter].split(" ");
            int width = Integer.parseInt(firstLine[0]);
            int height = Integer.parseInt(firstLine[1]);
            int digLimit = Integer.parseInt(firstLine[2]);
            char[][] input = toCharArray(lines, lineCounter + 1, lineCounter + 3 + height);
            int s = searchS(input[0]);

            if(width == 3){
                for(int j = 1; j<height; j++){
                    input[j][2] = 'X';
                }
                break;
            } else if(height % 3 == 0 && (width % 3 != 0 || height < width)){


                for(int j = 0; j < height/3; j++){

                    int index = j*3 + 2;

                    for(int k = 1; k <= width; k++){
                        input[index][k] = 'X';
                    }
                }

                for(int j = 1; j < height + 1; j++){
                    input[j][1] = ':';
                }
                for(int j = 2; j < height + 1; j++){
                    input[j][2] = 'X';

                }
                input[1][s] = 'X';
                input[2][s] = 'X';
                input[1][2] = 'X';




            } else if (width % 3 == 0){

                for(int j = 2; j < height +1 ; j++){
                    for(int k = 0; k < width/3; k++){
                        int index = k*3 + 2;

                        input[j][index] = 'X';
                    }
                }
                for(int j = 1; j <= width; j++){
                    input[2][j] = 'X';
                }

                input[1][s] = 'X';
                input[2][s] = 'X';
                input[1][2] = 'X';


            } else{
                throw new RuntimeException();
            }
            
            if(amountOfX(input) > digLimit){
                System.out.print(charArrayToString(input));
                throw new RuntimeException("To many X" + i);
            }

            output = output.concat(charArrayToString(input) + "\n");

            lineCounter += 4 + height;
        }








        PrintWriter out = new PrintWriter(new FileWriter(outputPath));

        out.println(output);
        out.flush();

    }
    
    public static int amountOfX(char[][] charArray) {
        int amount = 0;
        for (int i = 0; i < charArray.length; i++) {
            for (int j = 0; j < charArray[i].length; j++) {
                if (charArray[i][j] == 'X') {
                    amount +=1;
                }
            }
        }
        return amount;
    }

    public static String charArrayToString(char[][] charArray) {
        String out = "";
        for (int i = 0; i < charArray.length; i++) {
            for(int j = 0; j < charArray[i].length; j++) {
                out += charArray[i][j];
            }
            out += '\n';
        }
        return out;
    }


    public static int searchS(char[] i){
        for(int j = 0; j < i.length; j++){
            if(i[j] == 'S'){
                return j;
            }
        }
        throw new RuntimeException("s not found");
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

    public static String getSolution(char[][] charArray) {
        int outpostIndex = -1;
        for (int i = 0; i < charArray[0].length; i++) {
            if (charArray[0][i] == 'S') {
                outpostIndex = i;
            }
        }

        if (charArray.length == 5) {


        }
        return null;
    }

}