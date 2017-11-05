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

	void		update(const int y, const int x, const int sym, AObject * obj);

	int getW();

	int getH();

	bool isEmpty(int y, int x);

	AObject *	getObject(int y, int x);

	WINDOW *getWin() const;

	WINDOW *getInfo() const;

private:
	const int	h;
	const int	w;
	AObject		***f;
	WINDOW		*win;
	WINDOW		*info;
	static const int	empty = ' ';
};


#endif
