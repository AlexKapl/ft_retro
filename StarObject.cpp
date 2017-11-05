/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StarObject.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <akaplyar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 18:08:00 by akaplyar          #+#    #+#             */
/*   Updated: 2017/11/04 18:08:00 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "StarObject.hpp"

StarObject::StarObject() :	AObject('.', RANDY, RANDX) {
//	StarObject::count++;
}

StarObject::StarObject(StarObject const &copy) : AObject(copy) {
//	StarObject::count++;
}

StarObject::~StarObject() {
//	StarObject::count--;
	AObject::~AObject();
}

StarObject &StarObject::operator=(StarObject const &) {
	return *this;
}

int StarObject::fall() {
	if (f->getObject(y, x) == this)
		f->erase(y, x);
	this->y++;
	if (y < H - 2) {
		if (f->isEmpty(y, x))
			f->update(y, x, sym, this);
		return (1);
	}
	else
		return (0);
}
