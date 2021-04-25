#include "test.h"

void red (void) {
  printf("\033[1;31m");
}

void green (void) {
  printf("\033[1;32m");
}

void reset (void) {
  printf("\033[0m");
}

void print_result (int result)
{
	if (result){
		green();
		printf("::OK::\n\n");
		reset();
	} else {
		red();
		printf("::FAIL::\n\n");
		reset();
	};
}

int	main(void)
{
	// test_strchr();
	// test_strrchr();
	// test_strnstr();
	// test_atoi();
	test_split();
}
