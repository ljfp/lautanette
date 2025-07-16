#include <stdio.h>

int ft_str_is_uppercase(char *str);

void run_test(char *input, int expected) {
    int result = ft_str_is_uppercase(input);
    printf("ft_str_is_uppercase(\"%s\") = %d | Expected: %d | %s\n",
           input, result, expected, (result == expected) ? "PASS" : "FAIL");
}

int main(void) {
    // Test cases
    run_test("", 1);                  // Empty string
    run_test("ABCDEFGHIJKLMNOPQRSTUVWXYZ", 1); // All uppercase
    run_test("HELLOWORLD", 1);        // All uppercase
    run_test("HelloWorld", 0);        // Mixed case
    run_test("HELLOworld", 0);        // Mixed case
    run_test("123456", 0);            // Digits only
    run_test("!@#$%", 0);             // Symbols only
    run_test("ABC123", 0);            // Letters and numbers
    run_test("abc", 0);               // Lowercase only
    run_test("UPPERCASE", 1);         // All uppercase
    run_test("UPPER CASE", 0);        // Uppercase with space
    run_test("A", 1);                 // Single uppercase
    run_test("a", 0);                 // Single lowercase

    return 0;
}
