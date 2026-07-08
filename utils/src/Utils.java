import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.List;

public class Utils {

    public static final int MOD = 1_000_000_007;

    public static String readFile(String path) throws IOException {
        String content = Files.readString(Path.of(path));
        if (content.startsWith("\uFEFF")) { // utf-8 BOM
            content = content.substring(1);
        }
        return content;
    }

    public static void writeFile(String path, String content) throws IOException {
        Files.writeString(Path.of(path), content);
    }

    public static List<Integer>   toList(int[]     arr) { List<Integer>   l = new ArrayList<>(arr.length);    for (int     v : arr) l.add(v); return l; }
    public static List<Long>      toList(long[]    arr) { List<Long>      l = new ArrayList<>(arr.length);    for (long    v : arr) l.add(v); return l; }
    public static List<Double>    toList(double[]  arr) { List<Double>    l = new ArrayList<>(arr.length);    for (double  v : arr) l.add(v); return l; }
    public static List<Float>     toList(float[]   arr) { List<Float>     l = new ArrayList<>(arr.length);    for (float   v : arr) l.add(v); return l; }
    public static List<Short>     toList(short[]   arr) { List<Short>     l = new ArrayList<>(arr.length);    for (short   v : arr) l.add(v); return l; }
    public static List<Byte>      toList(byte[]    arr) { List<Byte>      l = new ArrayList<>(arr.length);    for (byte    v : arr) l.add(v); return l; }
    public static List<Character> toList(char[]    arr) { List<Character> l = new ArrayList<>(arr.length);    for (char    v : arr) l.add(v); return l; }
    public static List<Boolean>   toList(boolean[] arr) { List<Boolean>   l = new ArrayList<>(arr.length);    for (boolean v : arr) l.add(v); return l; }

    public static boolean inBounds(char[][] grid, int x, int y) {return x >= 0 && x < grid[0].length && y >= 0 && y < grid.length;}
    public static boolean inBounds(int[][] grid, int x, int y) {return x >= 0 && x < grid[0].length && y >= 0 && y < grid.length;}

    public static int[] findInGrid(char[][] grid, char target) {
        for (int i = 0; i < grid.length; i++)
            for (int j = 0; j < grid[i].length; j++)
                if (grid[i][j] == target) return new int[]{j, i};
        return null;
    }

    public static void printGrid(char[][] grid) {
        for (char[] row : grid) System.out.println(new String(row));
    }
}
