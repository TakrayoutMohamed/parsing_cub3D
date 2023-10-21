#include "./libpars.h"

/*romove the string to_trinm  from the start and end of s1*/
char	*ft_strtrim_free(char *s1, char *to_trim)
{
	char	*tmp;

	tmp = s1;
	s1 = ft_strtrim(s1, to_trim);
	// free(tmp); /*this may create a leak here*/
	return (s1);
}
