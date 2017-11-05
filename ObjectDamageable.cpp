/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ObjectDamageable.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <akaplyar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 12:42:00 by akaplyar          #+#    #+#             */
/*   Updated: 2017/11/05 12:42:00 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ObjectDamageable.hpp"

ObjectDamageable::ObjectDamageable(char c, int y, int x, int hp, int dmg) :
		AObject(), hp(hp), dmg(dmg) {
	sym = c;
	type = ASTEROID;
	this->y = y;
	this->x = x;
	f->update(y, x, c, this);
}

ObjectDamageable::ObjectDamageable(ObjectDamageable const &copy) :
		AObject(copy) {}

ObjectDamageable::~ObjectDamageable() {
	AObject::~AObject();
}

ObjectDamageable &ObjectDamageable::operator=(ObjectDamageable const &) {
	return *this;
}

int ObjectDamageable::getHp() const {
	return hp;
}

void ObjectDamageable::getDamage(int dmg) {
	hp -= dmg;
	if (hp < 0)
		hp = 0;
}
