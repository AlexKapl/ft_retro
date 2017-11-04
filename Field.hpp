/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Field.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <akaplyar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 17:02:00 by akaplyar          #+#    #+#             */
/*   Updated: 2017/11/04 17:02:00 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FIELD_HPP
# define FIELD_HPP

#include "ft_retro.h"

class Field {

public:
	Field();

	Field(Field const &);

	~Field();

	Field &operator=(Field const &);

	void		erase(const int y, const int x);

	void		update(const int y, const int x, const int sym);

	static int getW();

	static int getH();

	WINDOW *getWin() const;

private:
	WINDOW		*win;
	static const int	h = 60;
	static const int	w = 120;
	static const int	empty = ' ';
};


#endif
