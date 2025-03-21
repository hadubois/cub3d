/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asritz <asritz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:35:53 by asritz            #+#    #+#             */
/*   Updated: 2023/12/13 15:56:16 by asritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_putchar_fd_print(int c, int fd);
int	ft_putstr_fd_print(char *s, int fd);
int	ft_putnbr_fd_print(int nb, int fd);
int	ft_putunbr_fd_print(unsigned int nb, int fd);
int	ft_putptr(void *ptr);
int	ft_putlow_hexa(unsigned int nbr);
int	ft_putupp_hexa(unsigned int nbr);

#endif
