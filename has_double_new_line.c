#include "./libpars.h"

/*return true if the str has newline folowed by new line*/
bool	has_double_new_line(char *str)
{
	if (!str)
		return (true);
	while (*str)
	{
		if (*str == '\n' && *(str + 1) == '\n')
			return (true);
		str++;
	}
	return (false);
}
