#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char    *ft_strjoin(int size, char **strs, char *sep);

void test_and_print(int size, char **strs, char *sep, char *expected)
{
    char *result;
    
    printf("Test with %d strings and separator \"%s\":\n", size, sep);
    printf("Input: ");
    for (int i = 0; i < size; i++)
    {
        printf("\"%s\"", strs[i]);
        if (i < size - 1)
            printf(", ");
    }
    printf("\n");
    
    result = ft_strjoin(size, strs, sep);
    printf("Result: \"%s\"\n", result);
    
    if (expected)
    {
        printf("Expected: \"%s\"\n", expected);
        printf("Test %s\n", strcmp(result, expected) == 0 ? "PASSED" : "FAILED");
    }
    
    free(result);
    printf("\n");
}

int main(void)
{
    // Test case 1: Empty array
    {
        char **strs = malloc(0);
        test_and_print(0, strs, ", ", "");
        free(strs);
    }
    
    // Test case 2: Single string
    {
        char *strs[] = {"Hello"};
        test_and_print(1, strs, ", ", "Hello");
    }
    
    // Test case 3: Multiple strings
    {
        char *strs[] = {"Hello", "world", "this", "is", "a", "test"};
        test_and_print(6, strs, ", ", "Hello, world, this, is, a, test");
    }
    
    // Test case 4: Empty separator
    {
        char *strs[] = {"Hello", "world", "this", "is", "a", "test"};
        test_and_print(6, strs, "", "Helloworldthisisatest");
    }
    
    // Test case 5: Longer separator
    {
        char *strs[] = {"Hello", "world", "this", "is", "a", "test"};
        test_and_print(6, strs, " - ", "Hello - world - this - is - a - test");
    }
    
    // Test case 6: Array with empty strings
    {
        char *strs[] = {"", "Hello", "", "world", ""};
        test_and_print(5, strs, ", ", ", Hello, , world, ");
    }

    return (0);
}
