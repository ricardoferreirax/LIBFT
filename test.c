/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 15:31:05 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/11/06 11:21:28 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// LIBC FUNCTIONS #1

/* #include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	printf("=== ft_strlen ===\n\n");
	
	printf("1) ft_strlen: %zu\n", ft_strlen("Hello World!"));
	printf("1) strlen:    %zu\n\n", strlen("Hello World!"));

	printf("2) ft_strlen: %zu\n", ft_strlen("   \t\r\n\v\f-+123f"));
	printf("2) strlen:    %zu\n\n", strlen("   \t\r\n\v\f-+123f"));

	printf("3) ft_strlen: %zu\n", ft_strlen("ABC\0DEF"));
    printf("3) strlen:    %zu\n\n", strlen("ABC\0DEF"));

	printf("4) ft_strlen: %zu\n", ft_strlen(""));
	printf("4) strlen:    %zu\n\n", strlen(""));

	printf("5) ft_strlen: %zu\n", ft_strlen("\0"));
	printf("5) strlen:    %zu\n\n", strlen("\0"));

	// printf("%zu\n", strlen(NULL));  // tem de dar seg fault

	printf("=== ft_memcpy ===\n\n");
	{
		char a[] = "Hello";
		char b[10];
		char *c = "Hello";

		printf("1) ft_memcpy: %s\n", (char *)ft_memcpy(b, "ABC", 5));
		printf("1) memcpy:    %s\n\n", (char *)memcpy(b, "ABC", 5));

		printf("2) ft_memcpy: %s\n", (char *)ft_memcpy(b, "hel\0\0lo", 5));
		printf("2) memcpy:    %s\n\n", (char *)memcpy(b, "hel\0\0lo", 5));

		printf("3) ft_memcpy: %s\n", (char *)ft_memcpy(b, "	ABC", 5));
		printf("3) memcpy:    %s\n\n", (char *)memcpy(b, "ABC", 5));

		printf("4) ft_memcpy: %s\n", (char *)ft_memcpy(b, "\0ABC", 4));
		printf("4) memcpy:    %s\n\n", (char *)memcpy(b, "\0ABC", 4));

		printf("5) ft_memcpy: %s\n", (char *)ft_memcpy(b, "ABp55", 5));
		printf("5) memcpy:    %s\n\n", (char *)memcpy(b, "ABp55", 5));

		// printf("%s\n", (char *)memcpy(b, NULL, 3));  // tem de dar seg fault
		// printf("%s\n", (char *)memcpy(NULL, "ABC", 3)); // tem de dar seg fault
		// printf("%s\n", (char *)memcpy(NULL, NULL, 3)); // tem de dar seg fault
	}

	printf("=== ft_memset ===\n\n");
	{
		char a[] = "Hello, World!";

		printf("ft_memset: %s\n", (char *)ft_memset(a, 'e', 1));
		printf("memset:    %s\n\n", (char *)memset(a, 'e', 1));

		printf("ft_memset: %s\n", (char *)ft_memset(a, 'o', 10));
		printf("memset:    %s\n\n", (char *)memset(a, 'o', 10));

		printf("ft_memset: %s\n", (char *)ft_memset(a, ' ', 4));
		printf("memset:    %s\n\n", (char *)memset(a, ' ', 4));

		// UB:
		// printf("%s\n", (char *)ft_memset(a, 'a', 500));
		// printf("%s\n", (char *)ft_memset(NULL, 'a', 1));
	}

	printf("=== ft_bzero ===\n\n");
	{
		char str[10] = "Hello";
		ft_bzero(str + 3, 5);
		printf("After ft_bzero: '%s'\n\n", str);
	}

	printf("=== ft_memmove ===\n\n");
	{
		char str1[] = "abcdef";
		char str2[] = "abcdef";

		ft_memmove(str1 + 2, str1, 4);
		printf("ft_memmove: %s\n", str1);

		memmove(str2, str2 + 2, 4);
		printf("memmove:    %s\n\n", str2);
	}

	printf("=== ft_memcmp ===\n\n");
	
	printf("ft_memcmp: %d\n", ft_memcmp("ABC", "ABC", 3));
	printf("memcmp:    %d\n\n", memcmp("ABC", "ABC", 3));

	printf("ft_memcmp: %d\n", ft_memcmp("ABC", "AC", 2));
	printf("memcmp:    %d\n\n", memcmp("ABC", "AC", 2));

	printf("ft_memcmp: %d\n", ft_memcmp("BC", "ABC", 0));
	printf("memcmp:    %d\n\n", memcmp("BC", "ABC", 0));

	printf("ft_memcmp: %d\n", ft_memcmp("ABC", "AB", 3));
	printf("memcmp:    %d\n\n", memcmp("ABC", "AB", 3));

	printf("ft_memcmp: %d\n", ft_memcmp("AB", "ABC", 3));
	printf("memcmp:    %d\n\n", memcmp("AB", "ABC", 3));

	// segfaults:
	// printf("ft_memcmp: %d\n", ft_memcmp("ABC", NULL, 3));
	// printf("ft_memcmp: %d\n", ft_memcmp(NULL, "ABC", 3));
	// printf("ft_memcmp: %d\n", ft_memcmp(NULL, NULL, 3));

	printf("=== ft_memchr ===\n\n");
	{
		const char s[] = "Hello, World!";

		printf("ft_memchr: %s\n", (char *)ft_memchr(s, 'e', 5));
		printf("memchr:    %s\n\n", (char *)memchr(s, 'e', 5));

		printf("ft_memchr: %s\n", (char *)ft_memchr(s, 'o', 10));
		printf("memchr:    %s\n\n", (char *)memchr(s, 'o', 10));

		printf("ft_memchr: %s\n", (char *)ft_memchr(s, 'l', 3));
		printf("memchr:    %s\n\n", (char *)memchr(s, 'l', 3));

		printf("ft_memchr: %s\n", (char *)ft_memchr(s, 101, 2));
		printf("memchr:    %s\n\n", (char *)memchr(s, 101, 2));

		// segfault:
		// printf("%p\n", ft_memchr(NULL, 'a', 1));
		// printf("%p\n", memchr(NULL, 'a', 1));
	}

	return (0);
} */

////////////////////////////////////////////////////////////////////////////

// LIBC FUNCTIONS #3

/* #include "libft.h"
#include <stdio.h>
#include <ctype.h>
#include <limits.h>

int main(void)
{
	printf("=== ft_isalpha ===\n\n");
	printf("1) 'A' ft: %d\n", ft_isalpha(65));
	printf("'1) A' orig: %d\n\n", isalpha(65));

	printf("2) 321 ft: %d\n", ft_isalpha((unsigned char)321));
	printf("2) 321 orig: %d\n\n", isalpha((unsigned char)321));

	printf("3) -12918 ft: %d\n", ft_isalpha(-12918));
	printf("3) -12918 orig (UB): %d\n\n", isalpha(-12918));

	printf("4) -1 ft: %d\n", ft_isalpha(-1));
	printf("4) -1 orig (EOF): %d\n\n", isalpha(-1));

	// printf("5) INT_MIN ft: %d\n", ft_isalpha(INT_MIN));
	// printf("5) INT_MIN orig (UB): %d\n\n", isalpha(INT_MIN));

	// printf("6) INT_MAX ft: %d\n", ft_isalpha(INT_MAX));
	// printf("6) INT_MAX orig (UB): %d\n\n", isalpha(INT_MAX));

	printf("=== ft_isascii ===\n\n");
	printf("1) 'A' ft: %d\n", ft_isascii(65));
	printf("1) 'A' orig: %d\n\n", isascii(65));

	printf("2) 321 ft: %d\n", ft_isascii((unsigned char)321));
	printf("2) 321 orig: %d\n\n", isascii((unsigned char)321));

	printf("3) -12918 ft: %d\n", ft_isascii(-12918));
	printf("3) -12918 orig (UB): %d\n\n", isascii(-12918));

	printf("4) -1 ft: %d\n", ft_isascii(-1));
	printf("4) -1 orig: %d\n\n", isascii(-1));

	// printf("5) INT_MIN ft: %d\n", ft_isascii(INT_MIN));
	// printf("5) INT_MIN orig (UB): %d\n\n", isascii(INT_MIN));

	// printf("6) INT_MAX ft: %d\n", ft_isascii(INT_MAX));
	// printf("6) INT_MAX orig (UB): %d\n\n", isascii(INT_MAX));

	printf("=== ft_isalnum ===\n\n");
	printf("1) 'A' ft: %d\n", ft_isalnum(65));
	printf("1) 'A' orig: %d\n\n", isalnum(65));

	printf("2) 321 ft: %d\n", ft_isalnum((unsigned char)321));
	printf("2) 321 orig: %d\n\n", isalnum((unsigned char)321));

	printf("3) -12918 ft: %d\n", ft_isalnum(-12918));
	printf("3) -12918 orig (UB): %d\n\n", isalnum(-12918));

	printf("4) -1 ft: %d\n", ft_isalnum(-1));
	printf("4) -1 orig: %d\n\n", isalnum(-1));

	// printf("5) INT_MIN ft: %d\n", ft_isalnum(INT_MIN));
	// printf("5) INT_MIN orig (UB): %d\n\n", isalnum(INT_MIN));

	// printf("6) INT_MAX ft: %d\n", ft_isalnum(INT_MAX));
	// printf("6) INT_MAX orig (UB): %d\n\n", isalnum(INT_MAX));

	printf("=== ft_isprint ===\n\n");
	printf("1) 'A' ft: %d\n", ft_isprint(65));
	printf("1) 'A' orig: %d\n\n", isprint(65));

	printf("2) 321 ft: %d\n", ft_isprint((unsigned char)321));
	printf("2) 321 orig: %d\n\n", isprint((unsigned char)321));

	printf("3) -12918 ft: %d\n", ft_isprint(-12918));
	printf("3) -12918 orig (UB): %d\n\n", isprint(-12918));

	printf("4) -1 ft: %d\n", ft_isprint(-1));
	printf("4) -1 orig: %d\n\n", isprint(-1));

	// printf("5) INT_MIN ft: %d\n", ft_isprint(INT_MIN));
	// printf("5) INT_MIN orig (UB): %d\n\n", isprint(INT_MIN));

	// printf("6) INT_MAX ft: %d\n", ft_isprint(INT_MAX));
	// printf("6) INT_MAX orig (UB): %d\n\n", isprint(INT_MAX));

	return 0;
} */

/////////////////////////////////////////////////////////////////////////

/* int	main(void)
{
	printf("=== ft_strchr ===\n\n");
	printf("ft_strchr: %s\n", ft_strchr("Hello World!", 'o'));
	printf("strchr:    %s\n\n", strchr("Hello World!", 'o'));
	
	printf("ft_strchr: %s\n", ft_strchr("Hello World!", ' '));
	printf("strchr:    %s\n\n", strchr("Hello World!", ' '));

	printf("ft_strchr: %s\n", ft_strchr("Hello World!", 0));
	printf("strchr:    %s\n\n", strchr("Hello World!", 0));

	printf("ft_strchr: %s\n", ft_strchr("abbaba", 'b'));
	printf("strchr:    %s\n\n", strchr("abbaba", 'b'));

	{
		const char *s = "lolabcXYZ";
		printf("ft_strchr (s+2,'l'): %p\n", (void *)ft_strchr(s + 2, 'l'));
		printf("strchr    (s+2,'l'): %p\n\n", (void *)strchr(s + 2, 'l'));
	}

	// UB:
	// printf("%s\n", ft_strchr(NULL, 'o'));
	// printf("%s\n", strchr(NULL, 'o'));

	printf("=== ft_strrchr ===\n\n");
	printf("ft_strrchr: %s\n", ft_strrchr("Hello World!", 'o'));
	printf("strrchr:    %s\n\n", strrchr("Hello World!", 'o'));
	
	printf("ft_strrchr: %s\n", ft_strrchr("Hello World!", ' '));
	printf("strrchr:    %s\n\n", strrchr("Hello World!", ' '));

	printf("ft_strrchr: %s\n", ft_strrchr("Hello World!", 0));
	printf("strrchr:    %s\n\n", strrchr("Hello World!", 0));

	printf("ft_strrchr: %s\n", ft_strrchr("abbaba", 'b'));
	printf("strrchr:    %s\n\n", strrchr("abbaba", 'b'));

	{
		const char *s = "lolabcXYZ";
		printf("ft_strrchr (s+2,'l'): %p\n", (void *)ft_strrchr(s + 2, 'l'));
		printf("strrchr    (s+2,'l'): %p\n\n", (void *)strrchr(s + 2, 'l'));
	}

	// UB:
	// printf("%s\n", ft_strrchr(NULL, 'o'));
	// printf("%s\n", strrchr(NULL, 'o'));

	return (0);
} */

///////////////////////////////////////////////////////////////////////////////////

/* #include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

int	main(void)
{
	printf("=== ft_strlcat ===\n\n");
	{
		char a[50] = "Hello";
		char b[50] = "Goodbye";
		
		printf("len: %zu + 1\n", ft_strlcat(a, " Sunshine", 15));
		printf("ft_strlcat: %s\n", a);
		printf("strlcat:    %s\n\n", a);

		printf("len: %zu + 1\n", ft_strlcat(b, " Love", 13));
		printf("ft_strlcat: %s\n", b);
		printf("strlcat:    %s\n\n", b);

		char c[10] = "Hi";
		printf("len: %zu + 1\n", ft_strlcat(c, " there!", sizeof(c)));
		printf("ft_strlcat: %s\n\n", c);
	}

	printf("=== ft_strlcpy ===\n\n");
	{
		char b[10];
		size_t numb;
		
		numb = ft_strlcpy(b, "ABC", 4);
		printf("len: %zu + 1\n", numb);
		printf("ft_strlcpy: %s\n", b);
		printf("strlcpy:    %s\n\n", b);

		numb = ft_strlcpy(b, "hello", 6);
		printf("len: %zu + 1\n", numb);
		printf("ft_strlcpy: %s\n", b);
		printf("strlcpy:    %s\n\n", b);
			
		numb = ft_strlcpy(b, "hello", 6);
		printf("len: %zu + 1\n", numb);
		printf("ft_strlcpy: %s\n", b);
		printf("strlcpy:    %s\n\n", b);

		numb = ft_strlcpy(b, "ABC", 4);
		printf("len: %zu + 1\n", numb);
		printf("ft_strlcpy: %s\n", b);
		printf("strlcpy:    %s\n\n", b);
		
		numb = ft_strlcpy(b, "AB", 3);
		printf("len: %zu + 1\n", numb);
		printf("ft_strlcpy: %s\n", b);
		printf("strlcpy:    %s\n\n", b);

		numb = ft_strlcpy(b, "XXXXX", 0);
		printf("len (dstsize=0): %zu + 1\n\n", numb);
	}

	printf("=== ft_atoi ===\n\n");
	{
		printf("ft_atoi: %d\n", ft_atoi("   \t\r\n\v\f-+123f"));
		printf("atoi:    %d\n\n", atoi("   \t\r\n\v\f-+123f"));

		printf("ft_atoi: %d\n", ft_atoi("   \t\r\n\v\f-12 3f"));
		printf("atoi:    %d\n\n", atoi("   \t\r\n\v\f-12 3f"));
		
		printf("ft_atoi: %d\n", ft_atoi("   \t\r\n\v\f -2147483648"));
		printf("atoi:    %d\n\n", atoi("   \t\r\n\v\f -2147483648"));
		
		printf("ft_atoi: %d\n", ft_atoi("   \t\r\n\v\f 2147483647"));
		printf("atoi:    %d\n\n", atoi("   \t\r\n\v\f 2147483647"));
		
		printf("ft_atoi: %d\n", ft_atoi(""));
		printf("atoi:    %d\n\n", atoi(""));

		// printf("%d\n", ft_atoi(NULL));
		// printf("%d\n", atoi(NULL));
	}

	printf("=== ft_calloc ===\n\n");
	{
		printf("ft: %p\n", ft_calloc(4, 4));
		printf("or: %p\n\n", calloc(4, 4));

		printf("ft: %p\n", ft_calloc(0, 16));
		printf("or: %p\n\n", calloc(0, 16));

		printf("ft: %p\n", ft_calloc(16, 0));
		printf("or: %p\n\n", calloc(16, 0));

		printf("ft: %p\n", ft_calloc(0, 0));
		printf("or: %p\n\n", calloc(0, 0));

		printf("ft: %p\n", ft_calloc(SIZE_MAX/2, 1));
		printf("or: %p\n\n", calloc(SIZE_MAX/2, 1));

	}

	return 0;
} */

///////////////////////////////////////////////////////////////////////////////////////

// ADDITIONAL FUNCTIONS #1

#include "libft.h"
#include <stdio.h>
#include <unistd.h>   
#include <fcntl.h>    
#include <stdlib.h>   

int main(void)
{
    printf("=== ft_substr ===\n\n");
    {
        char *s;

        s = ft_substr("Hello World", 6, 5);      // "World"
        printf("1) %s\n", s);
        free(s);

        s = ft_substr("Hello", 2, 50);           // "llo"
        printf("2) %s\n", s);
        free(s);

        s = ft_substr("Hello", 5, 10);           // ""
        printf("3) '%s'\n", s);
        free(s);

        s = ft_substr("Hello", 42, 10);          // ""
        printf("4) '%s'\n", s);
        free(s);

        s = ft_substr("Hello", 2, 0);            // ""
        printf("5) '%s'\n", s);
        free(s);
    }

    printf("\n");

    printf("=== ft_strjoin ===\n\n");
    {
        char *j;

        j = ft_strjoin("Hello", "World");
        printf("1) %s\n", j);
        free(j);

        j = ft_strjoin("Hello", "");
        printf("2) %s\n", j);
        free(j);

        j = ft_strjoin("", "World");
        printf("3) %s\n", j);
        free(j);

        j = ft_strjoin("", "");
        printf("4) '%s'\n", j);
        free(j);

        {
            char *a = ft_substr("abcdef", 0, 3);   // "abc"
            char *b = ft_substr("abcdef", 3, 3);   // "def"
            j = ft_strjoin(a, b);                  // "abcdef"
            printf("5) %s\n", j);
            free(a);
            free(b);
            free(j);
        }
    }

    printf("\n");

    printf("=== ft_putchar_fd / ft_putstr_fd / ft_putendl_fd / ft_putnbr_fd ===\n\n");

    /* stdout (1) */
    ft_putchar_fd('A', 1);
    ft_putchar_fd('\n', 1);

    ft_putstr_fd("linha com putstr_fd no stdout", 1);
    ft_putchar_fd('\n', 1);

    ft_putendl_fd("linha com putendl_fd no stdout", 1);

    ft_putnbr_fd(42, 1);
    ft_putchar_fd('\n', 1);

    ft_putnbr_fd(-2147483648, 1);
    ft_putchar_fd('\n', 1);

    /* stderr (2) */
    ft_putstr_fd("erro: isto foi para o stderr\n", 2);
    ft_putendl_fd("erro: putendl_fd no stderr", 2);
    ft_putnbr_fd(9999, 2);
    ft_putchar_fd('\n', 2);

    {
        int fd = open("fd_test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (fd == -1)
        {
            perror("open");
            return (1);
        }

        ft_putstr_fd("Linha 1 no ficheiro\n", fd);
        ft_putendl_fd("Linha 2 no ficheiro (com endl)", fd);
        ft_putchar_fd('X', fd);
        ft_putchar_fd('\n', fd);
        ft_putnbr_fd(123456, fd);
        ft_putchar_fd('\n', fd);

        /* podes também escrever o resultado de uma strjoin lá dentro */
        {
            char *joined = ft_strjoin("File -> ", "conteudo dinamico\n");
            if (joined)
            {
                ft_putstr_fd(joined, fd);
                free(joined);
            }
        }

        close(fd);
        printf("ficheiro 'fd_test.txt' criado/escrito.\n");
    }

    return 0;
}



















// LINKED LISTS

// 1) FT_LSTADD_BACK

/*  int main()
{
	t_list *list = NULL;

	ft_lstadd_back(&list, ft_lstnew("primeiro"));
	ft_lstadd_back(&list, ft_lstnew("segundo"));
	ft_lstadd_back(&list, ft_lstnew("terceiro"));

	while (list != NULL)
	{
		printf("%s -> ", (char *)list->content);
		list = list->next;
	}
	printf("NULL\n");
	return (0);
} */

// 2) FT_LSTADD_FRONT

/* int main()
{
	t_list *list = NULL;

	ft_lstadd_front(&list, ft_lstnew("primeiro"));
	ft_lstadd_front(&list, ft_lstnew("segundo"));
	ft_lstadd_front(&list, ft_lstnew("terceiro"));

	while (list != NULL)
	{
		printf("%s -> ", (char *)list->content);
		list = list->next;
	}
	printf("NULL\n");
	return (0);
}  */

// 3) FT_LSTNEW

/* int main()
{
	char *content = "Hello, World!";

	t_list *new_node = ft_lstnew(content);
	printf("content: %s\n", (char *)new_node->content);
	
	return (0);
} */
