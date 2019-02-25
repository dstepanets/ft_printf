#include "ft_printf.h"

int		main(void)
{
	int		ret = 0;
	float	fnum3 = -1312.52;
/*
	printf("==============CHARS==============\n");
	ret = printf("pf_Chars\n1:%5c:\n2:%0-5c:\n3:%010.5c:\n4|%c|999\n", 'x', 'y', 'z', 0); //4:^@ Need to correct!
	printf("  ret: %d\n--------\n", ret);
	ret = ft_printf("ft_Chars\n1:%5c:\n2:%0-5c:\n3:%010.5c:\n4|%c|999\n", 'x', 'y', 'z', 0);
	printf("  ret: %d\n========\n", ret);
	ret = printf("1|%2c\n", 0);
	printf("  ret: %d\n--------\n", ret);
	ret = ft_printf("2|%2c\n", 0);
	printf("  ret: %d\n========\n", ret);
	printf("\n>>ret: %d\n--------\n", printf("c:|%03c|", 0));
	printf("\n>>ret: %d\n========\n", ft_printf("c:|%03c|", 0));

	printf("==============%%%%%%%%%%==============\n");
	ret = printf("pf_%%\n1:%7%:\n2:%0-7%:\n3:%07.5%:\n4:%%%\n");
	printf("  ret: %d\n--------\n", ret);
	ret = ft_printf("ft_%%\n1:%7%:\n2:%0-7%:\n3:%07.5%:\n4:%%%\n");
	printf("  ret: %d\n========\n", ret);
	printf("|%5%|\n");
	ft_printf("|%5%|\n");
	printf("|%-5%|\n");
	ft_printf("|%-5%|\n");
	printf("|%.0%|\n");
	ft_printf("|%.0%|\n");
	ret = printf("|%   %|\n", "test");
	printf("  ret: %d\n--------\n", ret);
	ret = ft_printf("|%   %|\n", "test");
	printf("  ret: %d\n========\n", ret);
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
	printf("\n>>ret: %d\n========\n", ft_printf("d:|%.d %.0d|", 0, 0));
	printf("\n>>ret: %d\n--------\n", printf("d:|%5.d %5.0d|", 0, 0));
	printf("\n>>ret: %d\n========\n", ft_printf("d:|%5.d %5.0d|", 0, 0));
	printf("\n>>ret: %d\n--------\n", printf("d:|%0+5.0d|", 25));
	printf("\n>>ret: %d\n========\n", ft_printf("d:|%0+5.0d|", 25));
	printf("\n>>ret: %d\n--------\n", printf("d:|% .0d|", 0));
	printf("\n>>ret: %d\n========\n", ft_printf("d:|% .0d|", 0));


	printf("==============UNSIGNED==============\n");
	printf("\n>>ret: %d\n--------\n", printf("u:|%U|", 4294967296));
	printf("\n>>ret: %d\n========\n", ft_printf("u:|%U|", 4294967296));
	printf("\n>>ret: %d\n--------\n", printf("u:|%.u, %.0u|", 0, 0));
	printf("\n>>ret: %d\n========\n", ft_printf("u:|%.u, %.0u|", 0, 0));
	printf("\n>>ret: %d\n--------\n", printf("u:|%0.0u|", 0));
	printf("\n>>ret: %d\n========\n", ft_printf("u:|%0.0u|", 0));

	printf("==============OCTAL==============\n");
	printf("\n>>ret: %d\n--------\n", printf("o:|%-#6o|", 2500));
	printf("\n>>ret: %d\n========\n", ft_printf("o:|%-#6o|", 2500));
	printf("\n>>ret: %d\n--------\n", printf("o:|%#6o|", 2500));
	printf("\n>>ret: %d\n========\n", ft_printf("o:|%#6o|", 2500));
	printf("\n>>ret: %d\n--------\n", printf("o:|%.o %.0o|", 42, 42));
	printf("\n>>ret: %d\n========\n", ft_printf("o:|%.o %.0o|", 42, 42));
	printf("\n>>ret: %d\n--------\n", printf("o:|%o|", 0));
	printf("\n>>ret: %d\n========\n", ft_printf("o:|%o|", 0));
	printf("\n>>ret: %d\n--------\n", printf("o:|%5.o %5.0o|", 0, 0));
	printf("\n>>ret: %d\n========\n", ft_printf("o:|%5.o %5.0o|", 0, 0));
	printf("\n>>ret: %d\n--------\n", printf("o:|%#o|", 0));
	printf("\n>>ret: %d\n========\n", ft_printf("o:|%#o|", 0));
	printf("\n>>ret: %d\n--------\n", printf("o:|%#5o|", 0));
	printf("\n>>ret: %d\n========\n", ft_printf("o:|%#5o|", 0));
	printf("\n>>ret: %d\n--------\n", printf("o:|%-#.4zo|", 0));
	printf("\n>>ret: %d\n========\n", ft_printf("o:|%-#.4zo|", 0));
	printf("\n>>ret: %d\n--------\n", printf("o:|%0-#5o|", 0));
	printf("\n>>ret: %d\n========\n", ft_printf("o:|%0-#5o|", 0));

	printf("==============HEXADECIMAL==============\n");
	printf("\n>>ret: %d\n--------\n", printf("x:|%028.18x|", 4242));
	printf("\n>>ret: %d\n========\n", ft_printf("x:|%028.18x|", 4242));
	printf("\n>>ret: %d\n--------\n", printf("x:|%#5.3x|", 25));
	printf("\n>>ret: %d\n========\n", ft_printf("x:|%#5.3x|", 25));
	printf("\n>>ret: %d\n--------\n", printf("x:|%#7.3x|", 25));
	printf("\n>>ret: %d\n========\n", ft_printf("x:|%#7.3x|", 25));
	printf("\n>>ret: %d\n--------\n", printf("x:|%#5.4hx|", -25));
	printf("\n>>ret: %d\n========\n", ft_printf("x:|%#5.4hx|", -25));
	printf("\n>>ret: %d\n--------\n", printf("x:|%#5.4hhx|", -25));
	printf("\n>>ret: %d\n========\n", ft_printf("x:|%#5.4hhx|", -25));
	printf("\n>>ret: %d\n--------\n", printf("x:|%#.4hhx|", 0));
	printf("\n>>ret: %d\n========\n", ft_printf("x:|%#.4hhx|", 0));

	printf("==============POINTERS==============\n");
	float 	*fptr = &fnum3;
	printf("\n>>ret: %d\n--------\n", printf("p:|%028.18p|", fptr));
	printf("\n>>ret: %d\n========\n", ft_printf("p:|%028.18p|", fptr));
	printf("\n>>ret: %d\n--------\n", printf("p:|%.18p|", fptr));
	printf("\n>>ret: %d\n========\n", ft_printf("p:|%.18p|", fptr));
	printf("\n>>ret: %d\n--------\n", printf("p:|%p|", fptr));
	printf("\n>>ret: %d\n========\n", ft_printf("p:|%p|", fptr));
	printf("\n>>ret: %d\n--------\n", printf("p:|%20.20p|", fptr));
	printf("\n>>ret: %d\n========\n", ft_printf("p:|%20.20p|", fptr));
	printf("\n>>ret: %d\n--------\n", printf("p:|%.0p, %.p|", 0, 0));
	printf("\n>>ret: %d\n========\n", ft_printf("p:|%.0p, %.p|", 0, 0));
	printf("\n>>ret: %d\n--------\n", printf("p:|%5p|", 0));
	printf("\n>>ret: %d\n========\n", ft_printf("p:|%5p|", 0));
	printf("\n>>ret: %d\n--------\n", printf("p:|%05p|", 0));
	printf("\n>>ret: %d\n========\n", ft_printf("p:|%05p|", 0));

	printf("==============FLOAT==============\n");
	float 	fnum = -100;
	float 	fnum2 = 0;
	printf("\n>>ret: %d\n--------\n", printf("f:|%11.2f|", -127.32435));
	printf("\n>>ret: %d\n========\n", ft_printf("f:|%11.2f|", -127.32435));
	printf("\n>>ret: %d\n--------\n", printf("f:|%11.2f|", -99.32335));
	printf("\n>>ret: %d\n========\n", ft_printf("f:|%11.2f|", -99.32335));
	printf("\n>>ret: %d\n--------\n", printf("f:|%11f|", -0.0));
	printf("\n>>ret: %d\n========\n", ft_printf("f:|%11f|", -0.0));
	printf("\n>>ret: %d\n--------\n", printf("f:|%+-f|", 0.0));
	printf("\n>>ret: %d\n========\n", ft_printf("f:|%+-f|", 0.0));
	printf("\n>>ret: %d\n--------\n", printf("f:|%11.2f|", 9.999));
	printf("\n>>ret: %d\n========\n", ft_printf("f:|%11.2f|", 9.999));
	printf("\n>>ret: %d\n--------\n", printf("f:|%f|", -25.0));
	printf("\n>>ret: %d\n========\n", ft_printf("f:|%f|", -25.0));
	printf("\n>>ret: %d\n--------\n", printf("f:|%f|", -9223372036854775808.7));
	printf("\n>>ret: %d\n========\n", ft_printf("f:|%f|", -9223372036854775808.7));
	printf("\n>>ret: %d\n--------\n", printf("f:|%f|", 1.42));
	printf("\n>>ret: %d\n========\n", ft_printf("f:|%f|", 1.42));
	printf("\n>>ret: %d\n--------\n", printf("f:|%.2f|", 1.388));
	printf("\n>>ret: %d\n========\n", ft_printf("f:|%.2f|", 1.388));
	printf("\n>>ret: %d\n--------\n", printf("f:|%-10.2F|", fnum/fnum2));
	printf("\n>>ret: %d\n========\n", ft_printf("f:|%-10.2F|", fnum/fnum2));
	printf("\n>>ret: %d\n--------\n", printf("f:|%010.5f|", 0/fnum2));
	printf("\n>>ret: %d\n========\n", ft_printf("f:|%010.5f|", 0/fnum2));

 	printf("==============COLORS==============\n");
	ft_printf("normal text {b}bold %f {0}norm {red}red %d {blue}blue \n{0}", 1.42, 42);
	ft_printf("normal {u}uderlined {d}dim {i}italic {I}inverted {0}norm\n");
	ft_printf("{green}green {yellow}yellow {magenta}magenta {I}inverted {-}def {0}norm\n");
	ft_printf("{cyan}cyan {_white}{black}_white-black{I}inverted {0}0 {b}{_green}{white}b_green-white{_}\n");
	ft_printf("{0}{lightgray}lightgray {darkgray}darkgray{I}inverted {0}0\n");
	ft_printf("{-}{_}def_def {_red}_red {_blue}_blue {_green}_green {_yellow}_yellow{_}\n");
	ft_printf("{_magenta}_magenta {_cyan}_cyan {_black}_black {_white}_white {_lightgray}_lightgray{_darkgray}_darkgray\n");
	ret = ft_printf("{b}bold {red}red{0}{-}\n");
	printf("ret: %d\n", ret);
*/	printf("\n>>ret: %d\n--------\n", printf("{%10d}", 42));
	printf("\n>>ret: %d\n========\n", ft_printf("{red}{%10d}", 42));
	printf("\n>>ret: %d\n--------\n", printf("{%s}", 0));
	printf("\n>>ret: %d\n========\n", ft_printf("{%s}", 0));


/*	printf("==============BINARY==============\n");
	printf("\n>>ret: %d\n--------\n", ft_printf("b:|%-20.10b|", 42));
	printf("\n>>ret: %d\n--------\n", ft_printf("b:|%20b|", -42));
	printf("\n>>ret: %d\n--------\n", ft_printf("b:|%12b|", 0));
	printf("\n>>ret: %d\n--------\n", ft_printf("b:|%-12.3b|", 0));
	printf("\n>>ret: %d\n--------\n", ft_printf("b:|%012b|", 2));

*/

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
• binary conversion
• colors
•
•
*/
