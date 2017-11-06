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

StarObject::StarObject() :	AObject('.', RANDY, RANDX, 0, 0) {}

StarObject::StarObject(StarObject const &copy) : AObject(copy) {}

StarObject::~StarObject() {}

StarObject &StarObject::operator=(StarObject const & ass) {
	if (this != &ass) {
		this->sym = ass.sym;
		this->y = ass.y;
		this->x = ass.x;
		this->hp = ass.hp;
		this->dmg = ass.dmg;
		this->sp = ass.sp;
		this->type = ass.type;
	}
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
