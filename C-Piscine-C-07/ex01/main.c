#include <stdio.h>
#include <stdlib.h>

int *ft_range(int min, int max);

void print_array(int *arr, int size, char *test_name) {
    printf("%s: ", test_name);
    if (arr == NULL) {
        printf("NULL (This is expected if min >= max)\n");
        return;
    }
    
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1)
            printf(", ");
    }
    printf("]\n");
}

int main(void)
{
    int *result;
    int size;
    
    // Test 1: Basic positive range
    int min1 = 5;
    int max1 = 10;
    size = max1 - min1;
    result = ft_range(min1, max1);
    print_array(result, size, "Test 1 (5 to 10)");
    free(result);
    
    // Test 2: Negative to positive range
    int min2 = -3;
    int max2 = 4;
    size = max2 - min2;
    result = ft_range(min2, max2);
    print_array(result, size, "Test 2 (-3 to 4)");
    free(result);
    
    // Test 3: All negative range
    int min3 = -10;
    int max3 = -5;
    size = max3 - min3;
    result = ft_range(min3, max3);
    print_array(result, size, "Test 3 (-10 to -5)");
    free(result);
    
    // Test 4: Zero-length range (should return NULL)
    int min4 = 7;
    int max4 = 7;
    result = ft_range(min4, max4);
    print_array(result, 0, "Test 4 (7 to 7)");
    
    // Test 5: Invalid range (min > max)
    int min5 = 10;
    int max5 = 5;
    result = ft_range(min5, max5);
    print_array(result, 0, "Test 5 (10 to 5)");
    
    // Test 6: Larger range
    int min6 = 1;
    int max6 = 15;
    size = max6 - min6;
    result = ft_range(min6, max6);
    print_array(result, size, "Test 6 (1 to 15)");
    free(result);
    
    return 0;
}
