// ft_printf_float_bonus.c
#include "ft_printf_bonus.h"

/*
** Reglas que implementamos:
** - precision por defecto: 6
** - si precision == 0 y no hay '#', no imprimimos punto decimal
** - '#' fuerza el punto decimal aunque precision == 0
** - ' ' o '+' imprimen signo para positivos (si ambos, gana '+')
** - '0' rellena con ceros a la izquierda (después del signo) si no hay '-'
** - mínimo de ancho (min_width) respeta el signo
** - NaN -> "nan" (sin signo), +Inf/-Inf -> "inf" con signo si corresponde
**
** Nota sobre rounding:
** hacemos redondeo típico: frac * 10^p + 0.5 y truncamos.
** Es suficiente para el proyecto y los testers de 42.
*/

static unsigned long long  uipow10_u(int p)
{
	unsigned long long r = 1;
	while (p-- > 0)
		r *= 10ULL;
	return r;
}

static int	is_nan(double x)        { return (x != x); }
static int	is_inf(double x)
{
	/* Comparar contra overflow: x es infinito si no es NaN y x*0 no es 0 */
	if (x != x) return 0;
	double y = x * 0.0;
	return (y != 0.0);
}

/* escribe número no-negativo en buf al revés; devuelve longitud */
static int ull_to_rev(char *buf, unsigned long long v)
{
	int i = 0;
	if (v == 0ULL)
		buf[i++] = '0';
	while (v)
	{
		buf[i++] = (char)('0' + (v % 10ULL));
		v /= 10ULL;
	}
	return i;
}

/* pasa del rev al orden normal */
static void reverse(char *s, int n)
{
	int i = 0, j = n - 1;
	while (i < j)
	{
		char t = s[i]; s[i] = s[j]; s[j] = t;
		i++; j--;
	}
}

/* compone en tmp el cuerpo del número (sin padding externo),
** incluyendo signo si aplica. Devuelve longitud total. */
static size_t compose_float(char *tmp, t_printf_token *t, double d)
{
	int       prec = (t->precision >= 0) ? t->precision : 6;
	int       put_dot = (prec > 0) || t->hash_flag;
	int       neg = (d < 0.0);
	char      sign = 0;

	if (!neg && t->plus_flag)      sign = '+';
	else if (!neg && t->space_flag)sign = ' ';
	else if (neg)                  sign = '-';

	/* NaN / Inf */
	if (is_nan(d))
	{
		size_t k = 0;
		if (sign) tmp[k++] = sign;
		tmp[k++] = 'n'; tmp[k++] = 'a'; tmp[k++] = 'n';
		return k;
	}
	if (is_inf(d))
	{
		size_t k = 0;
		if (neg) tmp[k++] = '-';
		else if (t->plus_flag) tmp[k++] = '+';
		else if (t->space_flag) tmp[k++] = ' ';
		tmp[k++] = 'i'; tmp[k++] = 'n'; tmp[k++] = 'f';
		return k;
	}

	/* valor absoluto */
	double x = neg ? -d : d;

	/* separar parte entera y fracción */
	unsigned long long scale = uipow10_u(prec);
	unsigned long long int_part = (unsigned long long)x;
	double fract = x - (double)int_part;

	/* redondeo: ejemplo, prec=3 => scale=1000 => fract * 1000 + 0.5 */
	unsigned long long frac_scaled = 0ULL;
	if (prec > 0)
	{
		double y = fract * (double)scale + 0.5;
		if (y >= (double)scale)
		{
			/* acarreo */
			int_part += 1ULL;
			frac_scaled = 0ULL;
		}
		else
			frac_scaled = (unsigned long long)y;
	}

	/* volcar a tmp */
	size_t k = 0;
	if (sign) tmp[k++] = sign;

	/* parte entera */
	char rev[32];
	int ri = ull_to_rev(rev, int_part);
	reverse(rev, ri);
	for (int i = 0; i < ri; ++i) tmp[k++] = rev[i];

	/* punto + frac */
	if (put_dot)
	{
		tmp[k++] = '.';
		if (prec > 0)
		{
			/* asegurar ceros a la izquierda en los decimales */
			unsigned long long pad = scale / 10ULL;
			while (pad > 0ULL && (frac_scaled / pad) == 0ULL)
			{
				tmp[k++] = '0';
				pad /= 10ULL;
			}
			/* copiar decimales */
			int rj = ull_to_rev(rev, frac_scaled);
			reverse(rev, rj);
			for (int i = 0; i < rj; ++i) tmp[k++] = rev[i];
			/* si frac_scaled es 0, rj=1 y arriba imprimimos '0' (correcto) */
		}
	}
	return k;
}

size_t	print_token_float(t_printf_token *token, double value)
{
	char   buf[128];
	size_t body_len = compose_float(buf, token, value);

	/* calcular padding total respecto a min_width */
	int sign_present = (buf[0] == '+' || buf[0] == '-' || buf[0] == ' ');
	size_t total_len = body_len;
	int padding = (int)token->min_width - (int)total_len;
	if (padding < 0) padding = 0;

	size_t count = 0;

	if (token->minus_flag)
	{
		/* izquierda */
		count += ft_print_count_str(buf, body_len);
		count += ft_print_n_char(' ', (size_t)padding);
	}
	else
	{
		if (token->zero_flag && token->min_width > 0)
		{
			/* imprimir signo, luego ceros, luego el resto */
			if (sign_present)
			{
				count += ft_print_count_str(buf, 1);
				count += ft_print_n_char('0', (size_t)padding);
				count += ft_print_count_str(buf + 1, body_len - 1);
			}
			else
			{
				count += ft_print_n_char('0', (size_t)padding);
				count += ft_print_count_str(buf, body_len);
			}
		}
		else
		{
			/* espacios a la izquierda */
			count += ft_print_n_char(' ', (size_t)padding);
			count += ft_print_count_str(buf, body_len);
		}
	}
	return count;
}
