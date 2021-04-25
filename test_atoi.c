#include "test.h"

static void	test_atoi_case(char *s)
{
	int	ref;
	int	out;

	ref = atoi(s);
	out = ft_atoi(s);

	printf("s: %s\n", s);
	printf("================\n");
	printf("atoi: %d\n", ref);
	printf("ft_atoi: %d\n", out);
	print_result(ref == out);
}

void	test_atoi(void)
{
	printf("\n-----------------------------------\n");
	printf("ft_atoi\n");
	printf("-----------------------------------\n");

	test_atoi_case("42");
	test_atoi_case("-42");
	test_atoi_case("+42");
	test_atoi_case("-+42");
	test_atoi_case("     \t42   \t");
	test_atoi_case("42!abc123++-");
	test_atoi_case("\0");
	test_atoi_case("0");
	test_atoi_case("++0");
	test_atoi_case("-0");
	test_atoi_case("2147483647");
	test_atoi_case("-2147483648");
	test_atoi_case("2147483648");
	test_atoi_case("-2147483649");
	test_atoi_case("9223372036854775807");
	test_atoi_case("-9223372036854775808");
	test_atoi_case("9223372036854775806");
	test_atoi_case("-9223372036854775807");
	test_atoi_case("9999999999999999999999");
	test_atoi_case("-9999999999999999999999");
}
