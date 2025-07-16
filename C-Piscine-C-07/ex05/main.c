#include <stdio.h>
#include <stdlib.h>

// Function prototypes
char **ft_split(char *str, char *charset);

// Helper function to print split result
void print_split(char **split)
{
    int i = 0;
    printf("[");
    while (split && split[i])
    {
        if (i > 0)
            printf(", ");
        printf("\"%s\"", split[i]);
        i++;
    }
    printf("]\n");
}

// Helper function to free split array
void free_split(char **split)
{
    int i = 0;
    if (!split) return;
    while (split[i])
    {
        free(split[i]);
        i++;
    }
    free(split);
}

// Test runner
void run_test(char *str, char *charset, char *desc)
{
    printf("Test: %s\n", desc);
    printf("Input string: \"%s\"\n", str);
    printf("Separators:   \"%s\"\n", charset);

    char **result = ft_split(str, charset);
    printf("Result: ");
    print_split(result);
    free_split(result);
    printf("-----\n");
}

int main(void)
{
    run_test("Hello World Split Test", " ", "Basic split by space");
    run_test("Hello,World,Split,Test", ",", "Split by comma");
    run_test(",Hello,,World,,", ",", "Leading/trailing/extra separators");
    run_test("abc:def;ghi", ":;", "Multiple separators");
    run_test("no-separators-here", ",", "No separator in string");
    run_test("", ",", "Empty string");
    run_test("   ", " ", "Only separators");
    run_test("a,b,c", ",", "Single characters");
    run_test("one--two---three", "-", "Multiple consecutive separators");
    run_test("split\tby\ttab", "\t", "Tab separator");
    run_test("split\nby\nnewline", "\n", "Newline separator");
    run_test("a b,c;d", " ,;", "Multiple mixed separators");
    run_test("word", "xyz", "No matching separator in charset");
    run_test("a b  c   d", " ", "Multiple spaces as separator");

    return 0;
}
