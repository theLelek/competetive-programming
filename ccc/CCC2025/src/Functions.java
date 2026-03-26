import java.util.ArrayList;
import java.util.Objects;

public class Functions {
    public static String arrayListToString(ArrayList<Objects> list) {
        String output = "";
        for (Objects objects : list) {
            output += objects.toString() + " ";
        }
        return output;
    }
}
