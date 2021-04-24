#include "test.h"

static void	test_strrchr_case(char *s, int c)
{
	char	*ref;
	char	*out;

	ref = strrchr(s, c);
	out = ft_strrchr(s, c);

	printf("s: %s\nc: %c (%d)\n", s, c, c);
	printf("================\n");
	printf("strrchr: %p: %s\n", ref, ref);
	printf("ft_strrchr: %p: %s\n", out, out);
	print_result(ref == out);
}

void test_strrchr(void)
{
	printf("\n-----------------------------------\n");
	printf("ft_strrchr\n");
	printf("-----------------------------------\n");

	test_strrchr_case("Hello World!", 'l');
	test_strrchr_case("abcdefgh", 'f');
	test_strrchr_case("abcdefgh", (1 << 10) + 'f');
}
