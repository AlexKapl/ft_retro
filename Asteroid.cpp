/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Asteroid.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <akaplyar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 13:35:00 by akaplyar          #+#    #+#             */
/*   Updated: 2017/11/05 13:35:00 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Asteroid.hpp"

Asteroid::Asteroid() :
		AObject('*', RANDY, RANDX, 1, 1) {
	type = ASTEROID;
}

Asteroid::Asteroid(Asteroid const &copy) :
		AObject(copy) {}

Asteroid::~Asteroid() {
}

Asteroid &Asteroid::operator=(Asteroid const &) {
	return *this;
}

int Asteroid::fall() {
	AObject *obj;

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