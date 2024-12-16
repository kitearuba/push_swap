/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 20:51:26 by chrrodri          #+#    #+#             */
/*   Updated: 2024/08/14 20:58:37 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	handle_int(va_list args, int fd)
{
	int	num;

	num = va_arg(args, int);
	ft_putnbr_fd(num, fd);
	return (get_int_length(num));
}
