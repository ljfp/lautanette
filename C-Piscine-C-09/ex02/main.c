#include <stdio.h>
#include <stdlib.h>

char **ft_split(char *str, char *charset);

void	print_split(char **split)
{
	int i = 0;
	while (split[i])
	{
		printf("split[%d]: \"%s\"\n", i, split[i]);
		i++;
	}
}

int	main(void)
{
	char *test1 = "Hello,world;42:split!";
	char *charset1 = ",;:!";
	char *test2 = "   abc  def ghi   ";
	char *charset2 = " ";
	char *test3 = "abc";
	char *charset3 = ",";
	char *test4 = ",,,abc,,,def,,";
	char *charset4 = ",";

	char **split;

	printf("Test 1:\n");
	split = ft_split(test1, charset1);
	print_split(split);
	for (int i = 0; split[i]; i++) free(split[i]);
	free(split);

	printf("\nTest 2:\n");
	split = ft_split(test2, charset2);
	print_split(split);
	for (int i = 0; split[i]; i++) free(split[i]);
	free(split);

	printf("\nTest 3:\n");
	split = ft_split(test3, charset3);
	print_split(split);
	for (int i = 0; split[i]; i++) free(split[i]);
	free(split);

	printf("\nTest 4:\n");
	split = ft_split(test4, charset4);
	print_split(split);
	for (int i = 0; split[i]; i++) free(split[i]);
	free(split);

	return 0;
}
