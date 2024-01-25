/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tali <tali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:22:24 by tali              #+#    #+#             */
/*   Updated: 2024/01/25 18:34:29 by tali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CRACK_H
# define CRACK_H

/*	lib	*/
# include "../libft/include_h/libft.h"
# include "hashing.h"

/*	function	*/
int		ft_char_to_hex(uint8_t nb, uint8_t **s, int i);
uint8_t	*ft_str_to_hex(uint8_t *s, uint64_t len);

#endif /* ifndef CRACK_H*/
