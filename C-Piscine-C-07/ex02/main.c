#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int min, int max);
int	ft_ultimate_range(int **range, int min, int max);

int	main(void)
{
	int	*range;
	int	size;
	int	i;

	// Test 1: Normal case
	size = ft_ultimate_range(&range, 1, 10);
	printf("Test 1: min=1, max=10\n");
	printf("Size returned: %d\n", size);
	printf("Values: ");
	for (i = 0; i < size; i++)
		printf("%d ", range[i]);
	printf("\n\n");
	free(range);

	// Test 2: min equals max
	size = ft_ultimate_range(&range, 5, 5);
	printf("Test 2: min=5, max=5\n");
	printf("Size returned: %d\n", size);
	printf("Range pointer: %p\n\n", (void*)range);

	// Test 3: min greater than max
	size = ft_ultimate_range(&range, 10, 5);
	printf("Test 3: min=10, max=5\n");
	printf("Size returned: %d\n", size);
	printf("Range pointer: %p\n\n", (void*)range);

	// Test 4: With negative numbers
	size = ft_ultimate_range(&range, -5, 5);
	printf("Test 4: min=-5, max=5\n");
	printf("Size returned: %d\n", size);
	printf("Values: ");
	for (i = 0; i < size; i++)
		printf("%d ", range[i]);
	printf("\n\n");
	free(range);

	// Test 5: Large range
	size = ft_ultimate_range(&range, 0, 100);
	printf("Test 5: min=0, max=100\n");
	printf("Size returned: %d\n", size);
	printf("First few values: ");
	for (i = 0; i < 10; i++)
		printf("%d ", range[i]);
	printf("...\n");
	free(range);

	return (0);
}
