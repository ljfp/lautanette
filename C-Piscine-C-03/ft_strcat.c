#include <stdio.h>
#include <string.h>

char    *ft_strcat(char *dest, char *src);

char    *ft_strcat(char *dest, char *src)
{
    char    *ptr;
    
    ptr = dest;
    while (*dest)
        dest++;
    
    while (*src)
    {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return (ptr);
}

int main(void)
{
    // Test 1: Normal case
    char test1_dest[50] = "Hello, ";
    char test1_src[] = "World!";
    printf("Test 1 (Normal case):\n");
    printf("Before: dest = \"%s\", src = \"%s\"\n", test1_dest, test1_src);
    ft_strcat(test1_dest, test1_src);
    printf("After: dest = \"%s\"\n", test1_dest);
    printf("Expected: \"Hello, World!\"\n\n");

    // Test 2: Empty source string
    char test2_dest[50] = "Hello!";
    char test2_src[] = "";
    printf("Test 2 (Empty source):\n");
    printf("Before: dest = \"%s\", src = \"%s\"\n", test2_dest, test2_src);
    ft_strcat(test2_dest, test2_src);
    printf("After: dest = \"%s\"\n", test2_dest);
    printf("Expected: \"Hello!\"\n\n");

    // Test 3: Concatenate multiple times
    char test3_dest[50] = "Hello";
    printf("Test 3 (Multiple concatenations):\n");
    printf("Initial: dest = \"%s\"\n", test3_dest);
    ft_strcat(test3_dest, " ");
    printf("After 1st concat: dest = \"%s\"\n", test3_dest);
    ft_strcat(test3_dest, "World");
    printf("After 2nd concat: dest = \"%s\"\n", test3_dest);
    ft_strcat(test3_dest, "!");
    printf("After 3rd concat: dest = \"%s\"\n", test3_dest);
    printf("Expected: \"Hello World!\"\n\n");

    // Test 4: Comparison with standard strcat
    char test4_ft_dest[50] = "Testing ";
    char test4_std_dest[50] = "Testing ";
    char test4_src[] = "function";
    
    printf("Test 4 (Comparison with standard strcat):\n");
    printf("Before: ft_dest = \"%s\", std_dest = \"%s\", src = \"%s\"\n", 
           test4_ft_dest, test4_std_dest, test4_src);
    
    ft_strcat(test4_ft_dest, test4_src);
    strcat(test4_std_dest, test4_src);
    
    printf("After ft_strcat: \"%s\"\n", test4_ft_dest);
    printf("After standard strcat: \"%s\"\n", test4_std_dest);
    
    if (strcmp(test4_ft_dest, test4_std_dest) == 0)
        printf("Result: ✅ MATCH\n\n");
    else
        printf("Result: ❌ MISMATCH\n\n");

    return 0;
}
