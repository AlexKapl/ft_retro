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

	int getW();

	int getH();

	WINDOW *getWin() const;

private:
	const int	h;
	const int	w;
	char		**f;
	WINDOW		*win;
	static const int	empty = ' ';
};


#endif
