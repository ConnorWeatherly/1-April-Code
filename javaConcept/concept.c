#include "concept.h"

public class TreeSort {
  public static int main() {
    int val = 1;
    System.out.println("This works with %s string", "any");
    System.out.println("The value of val is %d", val);

    System.out.println(9);

    String str = new String("This works well");
    System.out.println(str);
    System.out.println(str.length());
    System.out.println(str.charAt(2));

    String secondStr = new String("Second string");
    System.out.println(secondStr);
    System.out.println(secondStr.length());
    for (int i = 0; i < secondStr.length()-1; i++) {
      System.out.print(secondStr.charAt(i));
    }
    System.out.println("");

    return 1;
  }
}
