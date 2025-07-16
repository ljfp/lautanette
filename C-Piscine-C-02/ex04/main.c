#include <stdio.h>

int	ft_str_is_lowercase(char *str);

int main(void)
{
	char *tests[] = {
		"",              // Empty string
		"hello",         // All lowercase
		"Hello",         // Starts with uppercase
		"hello123",      // Contains digits
		"HELLO",         // All uppercase
		"lowercase",     // All lowercase
		"with space",    // Contains space
		"abcxyz",        // All lowercase, edge cases
		"abcXYZ",        // Mixed case
		"test!",         // Special character
		"z",             // Single lowercase
		"Z",             // Single uppercase
		NULL
	};

	for (int i = 0; tests[i] != NULL; i++) {
		printf("Test %2d: \"%s\" -> %d\n", i + 1, tests[i], ft_str_is_lowercase(tests[i]));
	}
	return 0;
}
