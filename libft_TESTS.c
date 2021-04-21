#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "libft.h"
// #include <bsd/string.h>
#include <stdlib.h>

void red (void) {
  printf("\033[1;31m");
}

void green (void) {
  printf("\033[1;32m");
}

void reset (void) {
  printf("\033[0m");
}

void print_result (int result) {
	if (result){
		green();
		printf("::OK::\n");
		reset();
	} else {
		red();
		printf("::FAIL::\n");
		reset();
	};
}

void	test_memset(void)
{
	char	output;
	char	*s = malloc(4);
	void	*s2;
	int		c;
	int		result;

	printf("\n-----------------------------------\n");
	printf("ft_memset\n");
	printf("-----------------------------------\n");

	c = 42;
	result = 1;
	s2 = ft_memset(s, c, 4);
	if (s2 != s)
		result = 0;
	printf("c = %d\n", c);
	for (int i = 0; i < 4; i++)
	{
		printf("%p: %d\n", &s[i], output = s[i]);
		if (output != c)
			result = 0;
	}
	print_result(result);

	printf("\n-----------------------------------\n");
	printf("ft_bzero\n");
	printf("-----------------------------------\n");

	ft_bzero(s, 4);
	result = 1;
	for (int i = 0; i < 4; i++)
	{
		printf("%p: %d\n", &s[i], output = s[i]);
		if (output != 0)
			result = 0;
	}
	print_result(result);
	free(s);
}

void	test_memchr(void)
{
	char	s[] = "abcdefg42";
	char	c = 'e';
	char	*reference;
	char	*output;

	printf("\n-----------------------------------\n");
	printf("ft_memchr\n");
	printf("-----------------------------------\n");
	printf("s: %s\nc: %c\nmemchr: %s\n", s, c, reference = (char *)memchr(s, c, sizeof(s)));
	printf("ft_memchr: %s\n", output = (char *)ft_memchr(s, c, sizeof(s)));
	print_result(!strcmp(reference, output));

	// doesn't exist, should return NULL
	c = 'h';
	printf("s: %s\nc: %c\nmemchr: %s\n", s, c, reference = (char *)memchr(s, c, sizeof(s)));
	printf("ft_memchr: %s\n", output = (char *)ft_memchr(s, c, sizeof(s)));
	print_result(reference == output);
}

void	test_memcmp(void)
{
	char	s1[] = "abc123";
	char	s2[] = "abc456";
	int		n = 3;
	int		reference;
	int		output;

	printf("\n-----------------------------------\n");
	printf("ft_memcmp\n");
	printf("-----------------------------------\n");
	printf("s1: %s\ns2: %s\nn: %d\nmemcmp: %d\n", s1, s2, n, reference = memcmp(s1, s2, n));
	printf("ft_memcmp: %d\n", output = ft_memcmp(s1, s2, n));
	print_result(reference == output);
	printf ("\n");

	n = 4;
	printf("s1: %s\ns2: %s\nn: %d\nmemcmp: %d\n", s1, s2, n, reference = memcmp(s1, s2, n));
	printf("ft_memcmp: %d\n", output = ft_memcmp(s1, s2, n));
	print_result(reference < 0 && output < 0);
}
void	test_memcpy(void)
{
	char src[] = "Hello World!";
	char buff1[50];
	char buff2[50];

	printf("\n-----------------------------------\n");
	printf("ft_memcpy\n");
	printf("-----------------------------------\n");

	memset(buff1, 0, sizeof(buff1));
	char *r1 = memcpy(buff1, src, sizeof(src));
	char *r2 = ft_memcpy(buff2, src, sizeof(src));
	printf("r1: %s\nr2: %s\n", r1, r2);
	print_result(!strcmp(r1, r2));
}

void	test_memccpy(void)
{
	char src[] = "test basic du memccpy !";
	char buff1[50];

	printf("\n-----------------------------------\n");
	printf("ft_memccpy\n");
	printf("-----------------------------------\n");

	memset(buff1, 0, sizeof(buff1));
	char *r1 = memccpy(buff1, src, 'm', 22);
	char *r2 = ft_memccpy(buff1, src, 'm', 22);
	printf("r1: %s\nr2: %s\n", r1, r2);
	print_result(!strcmp(r1, r2));

	r1 = memccpy("", src, 'm', 0);
	r2 = ft_memccpy("", src, 'm', 0);
	printf("r1: %s\nr2: %s\n", r1, r2);
	print_result(r1 == NULL && r2 == NULL);
}

void	test_memmove(void)
{
	char *src = "this is a good nyancat !";
	char dst1[0xF0];
	char dst2[0xF0];
	int size = strlen(src) + 1;

	printf("\n-----------------------------------\n");
	printf("ft_memmove\n");
	printf("-----------------------------------\n");
	memmove(dst1, src, size);
	ft_memmove(dst2, src, size);
	printf("memmove: %s\n", dst1);
	printf("ft_memmove: %s\n", dst2);
	print_result(!strcmp(dst1, dst2));
}

void	test_strncmp(void)
{
	char	*s1 = strdup("");
	char	*s2 = strdup("Hello World");
	int		n = 5;
	int		reference;
	int		output;

	printf("\n-----------------------------------\n");
	printf("ft_strncmp\n");
	printf("-----------------------------------\n");
	printf("s1: %s\n", s1);
	printf("s2: %s\n", s2);
	printf("n: %d\n", n);
	printf("ft_strncmp: %d\n", output = ft_strncmp(s1, s2, n));
	printf("strncmp: %d\n", reference = strncmp(s1, s2, n));
	print_result((reference == 0  && output == 0)||(reference < 0 && output < 0)||(reference > 0 && output > 0));

	free(s1);
	s1 = strdup("Hello");
	printf("s1: %s\n", s1);
	printf("s2: %s\n", s2);
	printf("n: %d\n", n);
	printf("ft_strncmp: %d\n", output = ft_strncmp(s1, s2, n));
	printf("strncmp: %d\n", reference = strncmp(s1, s2, n));
	print_result((reference == 0  && output == 0)||(reference < 0 && output < 0)||(reference > 0 && output > 0));

	free(s1);
	s1 = strdup("He");
	printf("s1: %s\n", s1);
	printf("s2: %s\n", s2);
	printf("n: %d\n", n);
	printf("ft_strncmp: %d\n", output = ft_strncmp(s1, s2, n));
	printf("strncmp: %d\n", reference = strncmp(s1, s2, n));
	print_result((reference == 0  && output == 0)||(reference < 0 && output < 0)||(reference > 0 && output > 0));

	free(s1);
	free(s2);
}

void	test_strlen(void)
{
	char	s[] = "Hello World!";

	int		reference;
	int		output;

	printf("-----------------------------------\n");
	printf("ft_strlen\n");
	printf("-----------------------------------\n");
	printf("s: %s\n", s);
	printf("ft_strlen: %d\n", output = ft_strlen(s));
	printf("strlen: %d\n", reference = strlen(s));
	print_result(reference == output);
	printf("\n");

	s[0] = '\0';
	printf("s: %s\n", s);
	printf("ft_strlen: %d\n", output = ft_strlen(s));
	printf("strlen: %d\n", reference = strlen(s));
	print_result(reference == output);
	printf("\n");
}


void	test_strlcpy(void)
{
	char	src[20] = "Hello World!";
	char	dst_ref[20];
	char	dst_out[20];
	size_t	size = 10;

	int		reference;
	int		output;

	printf("-----------------------------------\n");
	printf("ft_strlcpy\n");
	printf("-----------------------------------\n");
	printf("src: %s\n", src);
	printf("ft_strlcpy: %d, \"%s\"\n", output = ft_strlcpy(dst_out, src, size), dst_out);
	printf("strlcpy: %d, \"%s\"\n", reference = strlcpy(dst_ref, src, size), dst_ref);
	print_result(reference == output && !strcmp(dst_ref, dst_out));
	printf("\n");
}

void	test_strlcat(void)
{
	char	src[50] = "Carl";
	char	dst_ref[50] = "Oh, hi ";
	char	dst_out[50] = "Oh, hi ";
	size_t	size = 1;

	int		reference;
	int		output;

	printf("-----------------------------------\n");
	printf("ft_strlcat\n");
	printf("-----------------------------------\n");
	// size is 1, nothing copied
	printf("dst: %s\n", dst_out);
	printf("src: %s\n", src);
	printf("ft_strlcat: %d, \"%s\"\n", output = ft_strlcat(dst_out, src, size), dst_out);
	printf("strlcat: %d, \"%s\"\n", reference = strlcat(dst_ref, src, size), dst_ref);
	print_result(reference == output && !strcmp(dst_ref, dst_out));
	printf("\n");

	// normal
	size = 20;
	printf("dst: %s\n", dst_out);
	printf("src: %s\n", src);
	printf("ft_strlcat: %d, \"%s\"\n", output = ft_strlcat(dst_out, src, size), dst_out);
	printf("strlcat: %d, \"%s\"\n", reference = strlcat(dst_ref, src, size), dst_ref);
	print_result(reference == output && !strcmp(dst_ref, dst_out));
	printf("\n");

	// src too long, should be cut off at size limit
	size = 20;
	strcpy(dst_out, "Oh, hi ");
	strcpy(dst_ref, dst_out);
	strcpy(src, "src is too big to append!");

	printf("dst: %s\n", dst_out);
	printf("src: %s\n", src);
	printf("ft_strlcat: %d, \"%s\"\n", output = ft_strlcat(dst_out, src, size), dst_out);
	printf("strlcat: %d, \"%s\"\n", reference = strlcat(dst_ref, src, size), dst_ref);
	print_result(reference == output && !strcmp(dst_ref, dst_out));
	printf("\n");

	// dst string is too big (longer than size)
	size = 20;
	strcpy(dst_out, "This dst string is too long!!!");
	strcpy(dst_ref, dst_out);
	strcpy(src, "too big to append oh no!");

	printf("dst: %s\n", dst_out);
	printf("src: %s\n", src);
	printf("ft_strlcat: %d, \"%s\"\n", output = ft_strlcat(dst_out, src, size), dst_out);
	printf("strlcat: %d, \"%s\"\n", reference = strlcat(dst_ref, src, size), dst_ref);
	print_result(reference == output && !strcmp(dst_ref, dst_out));
	printf("\n");

}

void	test_strchr(void)
{
	char	s[] = "Hello World!";
	int		c = 'l';
	char	*reference;
	char	*output;

	printf("\n-----------------------------------\n");
	printf("ft_strchr\n");
	printf("-----------------------------------\n");
	printf("s: %s\nc: %c\n", s, c);
	reference = strchr(s, c);
	printf("strchr: %p: %s\n", reference, reference);
	output = ft_strchr(s, c);
	printf("ft_strchr: %p: %s\n", output, output);
	print_result(reference == output);
	printf("\n");

	c = '\0';
	printf("s: %s\nc: %c\n", s, c);
	reference = strchr(s, c);
	printf("strchr: %p: %s\n", reference, reference);
	output = ft_strchr(s, c);
	printf("ft_strchr: %p: %s\n", output, output);
	print_result(reference == output);
	printf("\n");
}

void	test_strrchr(void)
{
	char	s[] = "Hello World!";
	int		c = 'l';
	char	*reference;
	char	*output;

	printf("\n-----------------------------------\n");
	printf("ft_strrchr\n");
	printf("-----------------------------------\n");
	printf("s: %s\nc: %c\n", s, c);
	reference = strrchr(s, c);
	printf("strrchr: %p: %s\n", reference, reference);
	output = ft_strrchr(s, c);
	printf("ft_strrchr: %p: %s\n", output, output);
	print_result(reference == output);
	printf("\n");

	c = '\0';
	printf("s: %s\nc: %c\n", s, c);
	reference = strrchr(s, c);
	printf("strrchr: %p: %s\n", reference, reference);
	output = ft_strrchr(s, c);
	printf("ft_strrchr: %p: %s\n", output, output);
	print_result(reference == output);
	printf("\n");
}

void	test_chars(void)
{
	int vals[] = {'a', 'B', '!', -10};


	printf("-----------------------------------\n");
	printf("character functions\n");
	printf("-----------------------------------\n");

	for (int i = 0; i < 4; i++)
	{
		int	reference;
		int	output;

		printf("char: %c\n-------\n", vals[i]);
		printf("isalpha: %d \tft_isalpha: %d\t", reference = isalpha(vals[i]), output = ft_isalpha(vals[i]));
		print_result(reference == output);

		printf("isdigit: %d \tft_isdigit: %d\t", reference = isdigit(vals[i]), output = ft_isdigit(vals[i]));
		print_result(reference == output);

		printf("isalnum: %d \tft_isalnum: %d\t", reference = isalnum(vals[i]), output = ft_isalnum(vals[i]));
		print_result(reference == output);

		printf("isascii: %d \tft_isascii: %d\t", reference = isascii(vals[i]), output = ft_isascii(vals[i]));
		print_result(reference == output);

		printf("isprint: %d \tft_isprint: %d\t", reference = isprint(vals[i]), output = ft_isprint(vals[i]));
		print_result(reference == output);

		printf("toupper: %d \tft_toupper: %d\t", reference = toupper(vals[i]), output = ft_toupper(vals[i]));
		print_result(reference == output);

		printf("tolower: %d \tft_tolower: %d\t", reference = tolower(vals[i]), output = ft_tolower(vals[i]));
		print_result(reference == output);
		printf("\n");
	}


}

void	test_substr(void)
{
	char *s = "Hello World!";
	char *output;

	printf("-----------------------------------\n");
	printf("ft_substr\n");
	printf("-----------------------------------\n");

	printf("s: %s\n", s);
	printf("len = %d, sub string: %s\n", 2, output = ft_substr(s, 3, 2));
	print_result(strcmp(output, "lo") == 0);
	free(output);
	printf("len = %d, sub string: %s\n", 0, output = ft_substr(s, 3, 0));
	print_result(strcmp(output, "") == 0);
	free(output);
	printf("len = %d, sub string: %s\n", 100, output = ft_substr(s, 3, 100));
	print_result(strcmp(output, "lo World!") == 0);
	free(output);
	printf("len = %d, sub string: %s\n", -100, output = ft_substr(s, 3, -100));
	print_result(output == NULL);
	free(output);
	printf("\n");
}

void	test_strjoin(void)
{
	printf("\n-----------------------------------\n");
	printf("ft_strjoin\n");
	printf("-----------------------------------\n");

	char *s1 = "Hello ";
	char *s2 = "World!";
	char *output;

	printf("s1 = %s, s2 = %s\n", s1, s2);
	printf("result: %s\n", output = ft_strjoin(s1, s2));
	print_result(strcmp(output, "Hello World!") == 0);
	free(output);
}

void	test_strtrim(void)
{
	char	*s1 = "abcbca";
	char	*output;

	printf("OUTPUT: %s\n", output = ft_strtrim(s1, "abc"));
	free(output);
}

void	test_split(void)
{
	char *s = "      split       this for   me  !       ";

	char **ret = ft_split(s, ' ');

	for (int i = 0; ret[i]; i++)
	{
		printf("[%d]: %s\n", i, ret[i]);
		free(ret[i]);
	}
	free(ret);
}

void	test_strnstr(void)
{
	char	big[] = "Hello World!";
	char	little[] = "ell";
	size_t	len = strlen(big);
	char	*reference, *output;

	printf("\n-----------------------------------\n");
	printf("ft_strnstr\n");
	printf("-----------------------------------\n");
	printf("big = %s\nlittle = %s\nlen = %zu\n", big, little, len);
	printf("strnstr: %s\n", reference = strnstr("Hello World", "ell", len));
	printf("ft_strnstr: %s\n", output = ft_strnstr("Hello World", "ell", len));
	print_result(reference == output);
	printf("\n");

	len = 0;
	printf("big = %s\nlittle = %s\nlen = %zu\n", big, little, len);
	printf("strnstr: %s\n", reference = strnstr("Hello World", "ell", len));
	printf("ft_strnstr: %s\n", output = ft_strnstr("Hello World", "ell", len));
	print_result(reference == output);
	printf("\n");

}

void	test_itoa(void)
{
	char	*output;

	printf("%s\n", output = ft_itoa(0));
	free(output);
	printf("%s\n", output = ft_itoa(42));
	free(output);
	printf("%s\n", output = ft_itoa(-42));
	free(output);
	printf("%s\n", output = ft_itoa(INT_MAX));
	free(output);
	printf("%s\n", output = ft_itoa(INT_MIN));
	free(output);
}

void	test_calloc(void)
{
	t_list	*l1 = calloc(4, sizeof(t_list));
	t_list	*l2 = ft_calloc(4, sizeof(t_list));

	printf("\n-----------------------------------\n");
	printf("ft_strjoin\n");
	printf("-----------------------------------\n");
	printf("l1: %p: ", l1);
	for (size_t i = 0; i < sizeof(t_list) + 4; i++)
		printf("%x ", ((unsigned char *)l1)[i]);
	printf("\n");

	printf("l2: %p: ", l2);
	for (size_t i = 0; i < sizeof(t_list) + 4; i++)
		printf("%x ", ((unsigned char *)l2)[i]);
	printf("\n");
	print_result(!memcmp(l1, l2, sizeof(t_list) * 4));

	free(l1);
	free(l2);
}

void	test_lstadd_back(void)
{
	t_list *l = ((void*)0);
	t_list *n = ft_lstnew(strdup("OK"));

	ft_lstadd_back(&l, n);
	if (l == n && !strcmp(l->content, "OK"))
		printf("Success\n");
	else
		printf("Failure\n");
	free(n->content);
	free(n->next);
	free(n);
}

int		main(void)
{
	// test_memset();
	// test_memcpy();
	// test_memccpy();
	// test_memmove();
	// test_memchr();
	// test_memcmp();
	// test_strlen();
	// test_strlcpy();
	// test_strlcat();
	// test_strchr();
	// test_strrchr();
	// test_strnstr();
	// test_strncmp();

	// test_chars();
	// test_calloc();
	// test_substr();
	// test_strjoin();
	// test_strtrim();
	test_split();
	// test_itoa();
	// test_lstadd_back();
	return (0);
}
