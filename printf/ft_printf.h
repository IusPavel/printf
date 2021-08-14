#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_list
{
	int		start;
	char	specifier;
	char	*value;
	int		value_len;
	char	*rawstr;
	char	*sign;
	char	*size;
	int		flag_minus;
	int		flag_zero;
	int		width;
	int		dot;
	int		precision;
	int		precision_if_negative;
	int		counter;
}			t_list;
int		ft_printf(const char *format, ...);
void	ft_cleaner(t_list *argv);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_putchar(char c);
char	*ft_itoa(long long int n);
char	*ft_ctoa(int n);
char	*ft_utoa(unsigned long long int n);
char	*ft_xtoa(unsigned long long int n);
char	*ft_xxtoa(unsigned long long int n);
char	*ft_ptoa(unsigned long long n);
void	ft_print_arg(t_list *argv);
int		ft_distributor(char c, t_list *argv, va_list ap);
void	ft_arg_fill(char c, t_list *argv, va_list ap);
void	ft_exception(t_list *argv);
void	ft_release(t_list *argv, va_list ap);
void	ft_release_di(t_list *argv, long long int result);
void	ft_release_c(t_list *argv, int result);
void	ft_release_u(t_list *argv, unsigned long long int result);
void	ft_release_x(t_list *argv, unsigned long long int result);
void	ft_release_xx(t_list *argv, unsigned long long int result);
void	ft_release_p(t_list *argv, unsigned long long int result);
void	ft_release_s(t_list *argv, char *result);
void	ft_release_percent(t_list *argv);

#endif
