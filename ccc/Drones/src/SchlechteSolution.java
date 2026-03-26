import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class SchlechteSolution {
    public static void main(String[] args) throws IOException {


        try (
                BufferedReader br = new BufferedReader(new FileReader(args[0]));
                PrintWriter out = new PrintWriter(new FileWriter(args[1]))
        ) {

            String line = nextNonEmptyLine(br);
            if (line == null) return;
            int n = Integer.parseInt(line.trim());


            line = nextNonEmptyLine(br);
            if (line == null) return;
            int timeLimit = Integer.parseInt(line.trim());

            for (int i = 0; i < n; i++) {

                line = nextNonEmptyLine(br);
                if (line == null) break;
                int H = Integer.parseInt(line.trim());

                String seq = buildFlightSequence(H, timeLimit);
                out.println(seq);
            }
        }
    }


    private static String nextNonEmptyLine(BufferedReader br) throws IOException {
        String line;
        while ((line = br.readLine()) != null) {
            if (!line.trim().isEmpty()) return line;
        }
        return null;
    }


    private static void appendWithSpace(StringBuilder sb, int value) {
        if (sb.length() > 0) {
            sb.append(' ');
        }
        sb.append(value);
    }


    private static String buildFlightSequence(int H, int timeLimit) {

        int M = (H + 9) / 10;

        StringBuilder sb = new StringBuilder();


        for (int k = 0; k < M; k++) {
            appendWithSpace(sb, 20);
            appendWithSpace(sb, 0);
        }

        int loopsDown = M - 1;
        for (int k = 0; k < loopsDown; k++) {
            appendWithSpace(sb, 0);
            appendWithSpace(sb, 20);
        }


        appendWithSpace(sb, 1);
        appendWithSpace(sb, 18);



        return sb.toString();
    }
}