/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 20:45:15 by masenjo           #+#    #+#             */
/*   Updated: 2025/10/24 20:49:01 by masenjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H
# define OK 1
# define KO 0

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

/* Token Struct holding flags status, min-width,
** and precission values.                       */
typedef struct s_printf_token
{
	int		zero_flag;
	int		minus_flag;
	int		plus_flag;
	int		hash_flag;
	int		space_flag;
	int		min_width;
	int		precision;
	char	specifier;
}			t_printf_token;

/* Token Printing Format */
typedef struct s_printf_data
{
	char			num_buff[50];
	char			sign[3];
	int				sign_len;
	int				num_len;
	int				content_len;
	int				zero_prec;
	int				padding;
	unsigned long	magnitude;
}					t_printf_data;

/* Token */
int		parse_token(va_list args, const char *str, size_t *i);

/* Handlers for Token */
void	handle_flags(t_printf_token *token, const char *str, size_t *i);
void	handle_width(t_printf_token *token, va_list args,
			char const *str, size_t *i);
void	handle_precision(t_printf_token *token, va_list args,
			char const *str, size_t *i);
void	handle_specifier(t_printf_token *token, char const *str, size_t *i);

/* Output Formatters */
size_t	print_token_char(t_printf_token *token, int c);
size_t	print_token_str(t_printf_token *token, char *str);
size_t	print_token_sint(t_printf_token *token, int nbr, const char *base);
size_t	print_token_uint(t_printf_token *token,
			unsigned int n, const char *base);

/* Output Aux Functions */
int		ft_max(int a, int b);
int		ft_print_n_char(char c, int times);
int		ulong_to_dec(unsigned long n, char *buff, const char *base);
void	init_data_to_print_s(t_printf_data *data,
			t_printf_token *token, int nbr, const char *base);
void	init_data_to_print_u(t_printf_data *data,
			t_printf_token *token, unsigned int n, const char *base);
void	init_data_to_print_ptr(t_printf_data *data,
			t_printf_token *token, void *p, const char *base);

/* Token Printing Functions */

/* Main func */
int		ft_printf(const char *str, ...);

/* AUX FUNCTIONS */
/* Chars */
int		ft_print_count_char(char c);
int		ft_print_count_str(char *str, size_t len);
int		ft_iscinstr(const char *str, char c);
int		ft_isdigit(char c);
size_t	ft_strlen(char *str);

/* Numbers */
int		ft_check_base(const char *base);
size_t	ft_print_number_with_flags(t_printf_token *token,
			t_printf_data *data);
size_t	print_token_ptr(t_printf_token *token, void *p,
			const char *base);

#endif
