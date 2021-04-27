#include "test.h"

static void	test_split_case(char *s, char c)
{
	char	**out;
	size_t		i;

	out = ft_split(s, c);

	if (s)
		printf("s: \"%s\"\n", s);
	else
		printf("s: %s\n", s);
	if (c)
		printf("c: '%c'\n", c);
	else
		printf("c: '%s'\n", "\\0");
	printf("================\n");
	i = 0;
	if (out)
	{
		while (out[i])
		{
			printf("%zu: \"%s\"\n", i, out[i]);
			free(out[i]);
			i++;
		}
		printf("%zu: %s\n\n\n", i, out[i]);
		free(out);
	} else {
		printf("NULL\n\n\n");
	}
}

void	test_split(void)
{
	printf("\n-----------------------------------\n");
	printf("ft_split\n");
	printf("-----------------------------------\n");

	test_split_case("split,this,string", ',');
	test_split_case(",,,split,,,,this,string,,,", ',');
	test_split_case("!!!split!!!!this!string!!!", '!');
	test_split_case(",split\xAAthis,string,", 0xAA);
	test_split_case(",,,,,,,,", ',');
	test_split_case("split,this,string", (char)NULL);
	test_split_case("", ',');
	test_split_case("", '\0');
	test_split_case(NULL, ',');
	test_split_case(NULL, (char)NULL);
}
