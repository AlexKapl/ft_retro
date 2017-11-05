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
		ObjectDamageable('*', RANDY, RANDY, 1, 1) {}

Asteroid::Asteroid(Asteroid const &copy) :
		ObjectDamageable(copy) {}

Asteroid::~Asteroid() {
	ObjectDamageable::~ObjectDamageable();
}

Asteroid &Asteroid::operator=(Asteroid const &) {
	return *this;
}

int Asteroid::fall() {
	AObject * obj;
	ObjectDamageable *damageable;

	f->erase(y, x);
	this->y++;
	if (y < H - 2) {
		obj = f->getObject(y, x);
		if (obj == nullptr) {
			f->update(y, x, sym, this);
			return (1);
		}
		else {
			if (obj->getType() > REGULAR) {
				damageable = dynamic_cast<ObjectDamageable *>(obj);
				damageable->getDamage(this->dmg);
			}
			else {
				f->update(y, x, sym, this);
				return (1);
			}
		}
	}
	return (0);
}