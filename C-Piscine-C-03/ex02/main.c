#include <stdio.h>
#include <string.h>

char	*ft_strcat(char *dest, char *src);

int	main(void)
{
	// Test case 1: Basic concatenation
	char str1[50] = "Hello ";
	char str1_std[50] = "Hello ";
	printf("Test 1: Basic concatenation\n");
	printf("Original: \"%s\"\n", str1);
	printf("ft_strcat: \"%s\"\n", ft_strcat(str1, "World!"));
	printf("strcat:    \"%s\"\n", strcat(str1_std, "World!"));
	printf("Match: %s\n\n", strcmp(str1, str1_std) == 0 ? "Yes" : "No");
	
	// Test case 2: Empty destination string
	char str2[50] = "";
	char str2_std[50] = "";
	printf("Test 2: Empty destination string\n");
	printf("Original: \"%s\"\n", str2);
	printf("ft_strcat: \"%s\"\n", ft_strcat(str2, "Appended text"));
	printf("strcat:    \"%s\"\n", strcat(str2_std, "Appended text"));
	printf("Match: %s\n\n", strcmp(str2, str2_std) == 0 ? "Yes" : "No");
	
	// Test case 3: Empty source string
	char str3[50] = "Destination only";
	char str3_std[50] = "Destination only";
	printf("Test 3: Empty source string\n");
	printf("Original: \"%s\"\n", str3);
	printf("ft_strcat: \"%s\"\n", ft_strcat(str3, ""));
	printf("strcat:    \"%s\"\n", strcat(str3_std, ""));
	printf("Match: %s\n\n", strcmp(str3, str3_std) == 0 ? "Yes" : "No");
	
	// Test case 4: Multiple concatenations
	char str4[100] = "First";
	char str4_std[100] = "First";
	printf("Test 4: Multiple concatenations\n");
	printf("Original: \"%s\"\n", str4);
	ft_strcat(str4, " + ");
	ft_strcat(str4, "Second");
	ft_strcat(str4, " + ");
	ft_strcat(str4, "Third");
	
	strcat(str4_std, " + ");
	strcat(str4_std, "Second");
	strcat(str4_std, " + ");
	strcat(str4_std, "Third");
	
	printf("ft_strcat: \"%s\"\n", str4);
	printf("strcat:    \"%s\"\n", str4_std);
	printf("Match: %s\n\n", strcmp(str4, str4_std) == 0 ? "Yes" : "No");
	
	// Test case 5: Return value check
	char str5[50] = "Return ";
	char *result = ft_strcat(str5, "value test");
	printf("Test 5: Return value check\n");
	printf("ft_strcat returned: \"%s\"\n", result);
	printf("Original string:    \"%s\"\n", str5);
	printf("Return value points to original: %s\n\n", 
		result == str5 ? "Yes" : "No");
	
	return (0);
}
