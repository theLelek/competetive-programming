import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;

public class Test {
    public static void main(String[] args) throws IOException {
        String path = "src/input.txt";
        var lines = Files.readAllLines(Path.of(path));
        System.out.println(lines);



    }
}
