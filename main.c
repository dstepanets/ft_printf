#include "ft_printf.h"

int		main(void)
{
	int ret = 0;
	float num = -0.0;
	
/*	printf("pf_dec: %d\n", -135555);
	printf("pf_float: %2.f\n", num);
	printf("procent::%#05%::\n");
	printf("------------------------------------------\n");
*/
	printf("==============CHARS==============\n");
	ret = printf("pf_Chars\n1:%5c:\n2:%0-5c:\n3:%010.5c:\n4|%c|\n", 'x', 'y', 'z', 0); //4:^@ Need to correct!
	printf("  ret: %d\n--------\n", ret);
	ret = ft_printf("ft_Chars\n1:%5c:\n2:%0-5c:\n3:%010.5c:\n4|%c|\n", 'x', 'y', 'z', 0);
	printf("  ret: %d\n--------\n", ret);

/*
	printf("==============%%%%%%%%%%==============\n");
	ret = printf("pf_%%\n1:%7%:\n2:%0-7%:\n3:%07.5%:\n4:%%%\n");
	printf("  ret: %d\n--------\n", ret);
	ret = ft_printf("ft_%%\n1:%7%:\n2:%0-7%:\n3:%07.5%:\n4:%%%\n");
	printf("  ret: %d\n--------\n", ret);
*/
//	printf("|%5%|\n");
//	ft_printf("|%5%|\n");

//	printf("|%-5%|\n");
//	ft_printf("|%-5%|\n");

//	printf("|%.0%|\n");
//	ft_printf("|%.0%|\n");

//	printf("|%   %|\n", "test");
//	ft_printf("|%   %|\n", "test");
//	printf("-------------------------\n");
//	printf("%");
//	ft_printf("% ");
//	ft_printf("% h");
//	printf("|% %|\n", "test");
//	ft_printf("|% %|\n", "test");

	system("leaks a.out");
	return 0;
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
