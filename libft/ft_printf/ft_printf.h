/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeerber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 12:18:40 by mmeerber          #+#    #+#             */
/*   Updated: 2023/07/26 19:07:26 by mmeerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_putstr(char *s);
int		ft_hexa_min(unsigned long long n, char *hex);
int		ft_putnbr(long long n);
int		ft_nbr_no_neg(long long nb);
int		ft_hexa_maj(unsigned int n, char *hex);
int		ft_putchar(char c);
void	search_flag(char c, int *count, va_list *ag);
size_t	ft_strlen(const char *s);

#endif
