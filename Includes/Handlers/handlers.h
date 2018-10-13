#ifndef HANDLERS_H
# define HANDLERS_H
# include <stdarg.h>
# include <inttypes.h>
# include <unistd.h>

# define HH 5
# define H 7
# define L 10
# define LL 11
# define J 13
# define Z 16
# define HASH 3

typedef struct		s_flag
{
	int		more;
	int		less;
	int		zero;
	int		hash;
	int		blank;
	int		champs;
	int		precision;
	int		pointer;
	int		hexa;
	int 	binary;
	int		octal;
	int		character_or_string;
	int		unicode_c;
	int		unicode_s;
	int		conv_d;
	int 	conv_f;
	int 	conv_f_intpart;
	int 	lenght_conv;
	int 	lenght_print;
	int		len_buffer;
	short	color;
	char	buffer[4096];
}					t_flag;

int			handle_format(const char *format, va_list *ap);
int			handle_conversions(char conversion, va_list *ap, t_flag flag);

//A supprimer apres cette ligne
void			initialize_t_flag(t_flag	*flag);


#endif
