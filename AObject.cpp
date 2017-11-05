/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AObject.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <akaplyar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 16:46:00 by akaplyar          #+#    #+#             */
/*   Updated: 2017/11/04 16:46:00 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AObject.hpp"

Field* 	AObject::f = nullptr;

AObject::AObject(char c, int y, int x, int hp, int dmg) :
		sym(c), y(y), x(x), hp(hp), dmg(dmg), type(REGULAR) {
	f->update(y, x, c, this);
}

AObject::AObject(AObject const &copy) :
		sym(copy.sym), y(copy.y), x(copy.x), type(copy.type) {
	f->update(y, x, sym, this);
}

AObject::~AObject() {
	f->erase(y, x);
}

AObject &AObject::operator=(AObject const &) {
	return *this;
}

void AObject::setF(Field *f) {
	AObject::f = f;
}

AObject::AObject() : sym(0), y(0), x(0), type(REGULAR) {}

AObject::type_e AObject::getType() const {
	return type;
}

int AObject::getHp() const {
	return hp;
}

void AObject::getDamage(int dmg) {
	this->hp -= dmg;
	if (this->hp < 0)
		this->hp = 0;
}
