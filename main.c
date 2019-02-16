#include "ft_printf.h"

int		main(void)
{
	int		ret = 0;
	float 	fnum = -0.0;
	float 	fnum2 = -12412412.42424242;
	float 	*fptr = &fnum2;
/*
	printf("==============CHARS==============\n");
	ret = printf("pf_Chars\n1:%5c:\n2:%0-5c:\n3:%010.5c:\n4|%c|999\n", 'x', 'y', 'z', 0); //4:^@ Need to correct!
	printf("  ret: %d\n--------\n", ret);
	ret = ft_printf("ft_Chars\n1:%5c:\n2:%0-5c:\n3:%010.5c:\n4|%c|999\n", 'x', 'y', 'z', 0);
	printf("  ret: %d\n--------\n", ret);
	ret = printf("1|%2c\n", 0);
	printf("  ret: %d\n--------\n", ret);
	ret = ft_printf("2|%2c\n", 0);
	printf("  ret: %d\n--------\n", ret);

	printf("==============%%%%%%%%%%==============\n");
	ret = printf("pf_%%\n1:%7%:\n2:%0-7%:\n3:%07.5%:\n4:%%%\n");
	printf("  ret: %d\n--------\n", ret);
	ret = ft_printf("ft_%%\n1:%7%:\n2:%0-7%:\n3:%07.5%:\n4:%%%\n");
	printf("  ret: %d\n--------\n", ret);
	printf("|%5%|\n");
	ft_printf("|%5%|\n");
	printf("|%-5%|\n");
	ft_printf("|%-5%|\n");
	printf("|%.0%|\n");
	ft_printf("|%.0%|\n");
	ret = printf("|%   %|\n", "test");
	printf("  ret: %d\n--------\n", ret);
	ret = ft_printf("|%   %|\n", "test");
	printf("  ret: %d\n--------\n", ret);
	printf("% ");
	ft_printf("% ");
	printf("% h");
	ft_printf("% h");
	printf("|% %|\n", "test");
	ft_printf("|% %|\n", "test");

	printf("==============STRINGS==============\n");
	ret = printf("%6.6s is a string", "this");
	printf("\n>>ret: %d\n--------\n", ret);
	ret = ft_printf("%6.6s is a string", "this");
	printf("\n>>ret: %d\n--------\n", ret);
	ret = printf("%-010s is a string", "this");
	printf("\n>>ret: %d\n--------\n", ret);
	ret = ft_printf("%-010s is a string", "this");
	printf("\n>>ret: %d\n--------\n", ret);
	ret = printf("%s %s", NULL, "string");
	printf("\n>>ret: %d\n--------\n", ret);
	ret = ft_printf("%s %s", NULL, "string");
	printf("\n>>ret: %d\n--------\n", ret);

	printf("==============INTS==============\n");
	printf("\n>>ret: %d\n--------\n", printf("d:|%.d %.0d|", 0, 0));
	printf("\n>>ret: %d\n--------\n", ft_printf("d:|%.d %.0d|", 0, 0));
	printf("\n>>ret: %d\n--------\n", printf("d:|%5.d %5.0d|", 0, 0));
	printf("\n>>ret: %d\n--------\n", ft_printf("d:|%5.d %5.0d|", 0, 0));
*/
	printf("==============UNSIGNED==============\n");
	printf("\n>>ret: %d\n--------\n", printf("u:|%U|", 4294967296));
	printf("\n>>ret: %d\n--------\n", ft_printf("u:|%U|", 4294967296));
	printf("\n>>ret: %d\n--------\n", printf("u:|%.u, %.0u|", 0, 0));
	printf("\n>>ret: %d\n--------\n", ft_printf("u:|%.u, %.0u|", 0, 0));

/*
	printf("==============OCTAL==============\n");
	printf("\n>>ret: %d\n--------\n", printf("o:|%#.o %#.0o|", 0, 0));
	printf("\n>>ret: %d\n--------\n", ft_printf("o:|%#.o %#.0o|", 0, 0));

	printf("==============HEXADECIMAL==============\n");
	printf("\n>>ret: %d\n--------\n", printf("x:|%028.18x|", 4242));
	printf("\n>>ret: %d\n--------\n", ft_printf("x:|%028.18x|", 4242));

	printf("==============POINTERS==============\n");
	printf("\n>>ret: %d\n--------\n", printf("p:|%028.18p|", fptr));
	printf("\n>>ret: %d\n--------\n", ft_printf("p:|%028.18p|", fptr));
	printf("\n>>ret: %d\n--------\n", printf("p:|%.18p|", fptr));
	printf("\n>>ret: %d\n--------\n", ft_printf("p:|%.18p|", fptr));
	printf("\n>>ret: %d\n--------\n", printf("p:|%p|", fptr));
	printf("\n>>ret: %d\n--------\n", ft_printf("p:|%p|", fptr));
	printf("\n>>ret: %d\n--------\n", printf("p:|%20.20p|", fptr));
	printf("\n>>ret: %d\n--------\n", ft_printf("p:|%20.20p|", fptr));
	printf("\n>>ret: %d\n--------\n", printf("p:|%.p, %.0p|", 0, 0));
	printf("\n>>ret: %d\n--------\n", ft_printf("p:|%.p, %.0p|", 0, 0));
*/

//	printf("------------TO FIX???-------------\n");
//	printf("|%%%777\n");
//	ft_printf("|%%%777\n");

//	printf("\n++++++++++++++++++++++++LEAKS++++++++++++++++++++++++++++++++++++++\n");
//	system("leaks a.out");
	return (0);
}

//	ccw -g main.c ft_printf.c parser.c convert_c_s.c ./libft/libft.a


/*
You have to manage the following conversions: 
• csp
• diouxX 	with flags: 	hh, h, l and ll.
• f 		with flags: 	l and L.
• You must manage 	%%
• the flags 		#0-+ and space
• minimum field-width
• precision
--------------------------------------------
		BONUS:
• More detailed conversions management: e and g. Be careful, your L flag must work
with both of them to validate this bonus.
• More detailed flags management: *, $ and ’.
• Non-existing flags management: %b to print in binary, %r to print a string of 
nonprintable characters, %k to print a date in any ordinary ISO format etc.
• Management of alter tools for colors, fd or other fun stuff like that :)
---------------------------------------------
		BONUS IDEAS:
• char l (ell) flag: wint_t -> wchar_t.
• 

*/
