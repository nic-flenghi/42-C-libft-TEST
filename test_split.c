#include "test.h"

static void	test_split_case(char *s, char c)
{
	char	**out;
	size_t		i;

	out = ft_split(s, c);

	printf("s: %s\nc: %c\n", s, c);
	printf("================\n");
	i = 0;
	while (out[i])
	{
		printf("%zu: %s\n", i, out[i] ? out[i] : "(null)");
		free(out[i]);
		i++;
	}
	printf("%zu: %s\n\n\n", i, out[i] ? out[i] : "(null)");
	free(out);
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
	test_split_case("split,this,string", (char)NULL);
	test_split_case("", ',');
	test_split_case("", (char)NULL);
	test_split_case(NULL, ',');
	test_split_case(NULL, (char)NULL);
}
