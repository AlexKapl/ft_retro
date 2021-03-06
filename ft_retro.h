/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_retro.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <akaplyar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 15:31:00 by akaplyar          #+#    #+#             */
/*   Updated: 2017/11/04 15:31:00 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RETRO_H
#define FT_RETRO_H

# include <ncurses.h>
# include <iostream>
# include <unistd.h>

#define LEFT 260
#define RIGHT 261
#define DOWN 259
#define UP 258
#define ATTACK 32
#define PAUSE 10
#define H 60
#define W 120

#define RANDY ((rand() % (H / 2)) + 1)
#define RANDX ((rand() % (W - 2)) + 1)

class	AObject;
class	Field;

#endif

///usleep() ± speed game
