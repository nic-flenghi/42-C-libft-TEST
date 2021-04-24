#include "test.h"



static void	test_strchr_case(char *s, int c)
{
	char	*ref;
	char	*out;

	ref = strchr(s, c);
	out = ft_strchr(s, c);

	printf("s: %s\nc: %c (%d)\n", s, c, c);
	printf("================\n");
	printf("strchr: %p: %s\n", ref, ref);
	printf("ft_strchr: %p: %s\n", out, out);
	print_result(ref == out);
}

void	test_strchr(void)
{
	printf("\n-----------------------------------\n");
	printf("ft_strchr\n");
	printf("-----------------------------------\n");
	test_strchr_case("Hello World!", 'l');
	test_strchr_case("abcdefgh", 'f');
	test_strchr_case("abcdefgh", (1 << 10) + 'f');
	test_strchr_case("", 'f');
	test_strchr_case("abc", '\0');
}
