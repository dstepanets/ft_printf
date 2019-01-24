/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstepane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 20:41:46 by dstepane          #+#    #+#             */
/*   Updated: 2019/01/24 20:41:48 by dstepane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void					convert_string(t_pf *pf)
{
    
}

/*
    NEED TO HANDLE:
        width, prec, -, 

     s       The char * argument is expected to be a pointer to an array of
             character type (pointer to a string).  Characters from the array
             are written up to (but not including) a terminating NUL charac-
             ter; if a precision is specified, no more than the number speci-
             fied are written.  If a precision is given, no null character
             need be present; if the precision is not specified, or is greater
             than the size of the array, the array must contain a terminating
             NUL character.

             If the l (ell) modifier is used, the wchar_t * argument is
             expected to be a pointer to an array of wide characters (pointer
             to a wide string).  For each wide character in the string, the
             (potentially multi-byte) sequence representing the wide character
             is written, including any shift sequences.  If any shift sequence
             is used, the shift state is also restored to the original state
             after the string.  Wide characters from the array are written up
             to (but not including) a terminating wide NUL character; if a
             precision is specified, no more than the number of bytes speci-
             fied are written (including shift sequences).  Partial characters
             are never written.  If a precision is given, no null character
             need be present; if the precision is not specified, or is greater
             than the number of bytes required to render the multibyte repre-
             sentation of the string, the array must contain a terminating
             wide NUL character.

		 `0' (zero)   Zero padding.  For all conversions except n, the
                      converted value is padded on the left with zeros
                      rather than blanks.
         `-'          A negative field width flag; the converted value is
                      to be left adjusted on the field boundary.  Except
                      for n conversions, the converted value is padded on
                      the right with blanks, rather than on the left with
                      blanks or zeros.  A - overrides a 0 if both are
                      given.
     o   An optional decimal digit string specifying a minimum field
         width.  If the converted value has fewer characters than the
         field width, it will be padded with spaces on the left (or right,
         if the left-adjustment flag has been given) to fill out the field
         width.
	
	 The following length modifier is valid for the c or s conversion:
         Modifier    c         s
         l (ell)     wint_t    wchar_t *

*/