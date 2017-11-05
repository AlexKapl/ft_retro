/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerUp.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <akaplyar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 22:12:00 by akaplyar          #+#    #+#             */
/*   Updated: 2017/11/05 22:12:00 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PowerUp.hpp"

PowerUp::PowerUp() :
		AObject('%', RANDY, RANDX, 1, 1) {
	this->dmg = (rand() % 7 + 33);
	this->sym = dmg + COLOR_PAIR(rand() % 3 + 3);
	type = REGULAR;
}

PowerUp::PowerUp(PowerUp const &copy) :
		AObject(copy) {}

PowerUp::~PowerUp() {
}

PowerUp &PowerUp::operator=(PowerUp const &) {
	return *this;
}

int PowerUp::fall() {
	AObject *obj;

	if (f->getObject(y, x) == this)
		f->erase(y, x);
	this->y++;
	if (y < H - 2) {
		obj = f->getObject(y, x);
		if (obj == nullptr || obj->getType() == REGULAR) {
			f->update(y, x, sym, this);
			return (1);
		}
		else {
			obj->getDamage(this->dmg);
		}
	}
	return (0);
}

void PowerUp::update() {
	AObject::update();
	this->dmg = (rand() % 7 + 33);
	this->sym = dmg + COLOR_PAIR(rand() % 3 + 3);
}
