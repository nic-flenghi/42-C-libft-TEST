#include "test.h"

void	test_strnstr_case(char *big, char *little, size_t len)
{
	char	*ref;
	char	*out;

	ref = strnstr(big, little, len);
	out = ft_strnstr(big, little, len);

	printf("big = %s\nlittle = %s\nlen = %zu\n", big, little, len);
	printf("================\n");
	printf("strnstr: %p: %s\n", ref, ref ? ref : "(null)");
	printf("ft_strnstr: %p: %s\n", out, out ? out : "(null)");
	print_result(ref == out);
}

void	test_strnstr(void)
{
	printf("\n-----------------------------------\n");
	printf("ft_strnstr\n");
	printf("-----------------------------------\n");

	test_strnstr_case("Hello World!", "ell", 12);
	test_strnstr_case("Hello World!", "ell", 3);
	test_strnstr_case("Hello World!", "ell", 0);
	test_strnstr_case("Hello World!", "ell", 1);
	test_strnstr_case("Hello World!", "World", 5);
	test_strnstr_case("Hello World!", "", 25);
	test_strnstr_case("Hello World!", "\0", 25);
	test_strnstr_case("Hello World!", "\0", 0);
	test_strnstr_case(NULL, "", 0);
	test_strnstr_case(NULL, "", 10);
}
