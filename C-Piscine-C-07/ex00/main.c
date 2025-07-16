#include <stdio.h>
#include <stdlib.h>

char *ft_strdup(char *src);

int ft_strcmp(char *s1, char *s2)
{
    while (*s1 && (*s1 == *s2))
    {
        s1++;
        s2++;
    }
    return (*s1 - *s2);
}

void test_case(char *test_name, char *input) 
{
    char *duplicate = ft_strdup(input);
    int i = 0;
    int match = 1;
    
    printf("Test: %s\n", test_name);
    printf("Input: \"%s\"\n", input);
    printf("Output: \"%s\"\n", duplicate);
    
    // Manual character by character comparison
    while (input[i] || duplicate[i])
    {
        if (input[i] != duplicate[i])
        {
            match = 0;
            break;
        }
        i++;
    }
    
    if (match)
        printf("Content check: ✅ PASS\n");
    else
        printf("Content check: ❌ FAIL\n");
    
    if (input != duplicate)
        printf("Address check: ✅ PASS\n");
    else
        printf("Address check: ❌ FAIL\n");
    
    free(duplicate);
    printf("------------------------------------\n");
}

int main(void)
{
    test_case("Basic String", "Hello, world!");
    test_case("Empty String", "");
    test_case("Special Characters", "!@#$%^&*()_+{}|:<>?~");
    test_case("Long String", "This is a very long string to test!");
    test_case("Single Character", "X");
    
    return 0;
}
