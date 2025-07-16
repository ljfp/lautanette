#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function prototype
char	*ft_strncat(char *dest, char *src, unsigned int nb);

// Helper function to create a fresh buffer for each test
void reset_buffers(char *buffer1, char *buffer2, const char *initial_value) {
    strcpy(buffer1, initial_value);
    strcpy(buffer2, initial_value);
}

// Function to compare and print test results
void run_test(char *test_name, char *dest1, char *dest2, char *src, unsigned int n) {
    char *result1 = strncat(dest1, src, n);
    char *result2 = ft_strncat(dest2, src, n);
    
    printf("\n=== Test: %s ===\n", test_name);
    printf("strncat:    \"%s\", returns %p\n", dest1, result1);
    printf("ft_strncat: \"%s\", returns %p\n", dest2, result2);
    
    if (strcmp(dest1, dest2) == 0) {
        printf("Result: ✅ Strings match\n");
    } else {
        printf("Result: ❌ Strings differ\n");
    }
    
    if (result2 == dest2) {
        printf("Return: ✅ Correct return value\n");
    } else {
        printf("Return: ❌ Incorrect return value\n");
    }
}

int main(void) {
    // Buffer size to hold our strings (adjust as needed)
    const int BUF_SIZE = 100;
    
    // Create buffers for standard and custom implementations
    char *std_buf = (char *)malloc(BUF_SIZE * sizeof(char));
    char *ft_buf = (char *)malloc(BUF_SIZE * sizeof(char));
    
    if (!std_buf || !ft_buf) {
        printf("Memory allocation failed\n");
        return 1;
    }
    
    printf("=== TESTING ft_strncat vs strncat ===\n");
    
    // Test 1: Basic concatenation
    reset_buffers(std_buf, ft_buf, "Hello");
    run_test("Basic concatenation", std_buf, ft_buf, " World", 6);
    
    // Test 2: Zero characters (n = 0)
    reset_buffers(std_buf, ft_buf, "Hello");
    run_test("Zero characters (n = 0)", std_buf, ft_buf, " World", 0);
    
    // Test 3: n greater than source length
    reset_buffers(std_buf, ft_buf, "Hello");
    run_test("n > source length", std_buf, ft_buf, " World", 20);
    
    // Test 4: n less than source length
    reset_buffers(std_buf, ft_buf, "Hello");
    run_test("n < source length", std_buf, ft_buf, " World!", 3);
    
    // Test 5: Empty destination string
    reset_buffers(std_buf, ft_buf, "");
    run_test("Empty destination string", std_buf, ft_buf, "Hello", 5);
    
    // Test 6: Empty source string
    reset_buffers(std_buf, ft_buf, "Hello");
    run_test("Empty source string", std_buf, ft_buf, "", 5);
    
    // Test 7: Empty strings for both
    reset_buffers(std_buf, ft_buf, "");
    run_test("Empty strings for both", std_buf, ft_buf, "", 5);
    
    // Test 8: Multiple concatenations
    reset_buffers(std_buf, ft_buf, "Hello");
    strncat(std_buf, " ", 1);
    ft_strncat(ft_buf, " ", 1);
    run_test("Multiple concatenations", std_buf, ft_buf, "World", 5);
    
    // Clean up
    free(std_buf);
    free(ft_buf);
    
    return 0;
}
