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

Field *AObject::f = nullptr;

AObject::AObject() :
		sym(0), y(0), x(0), hp(0), dmg(0), sp(0), type(BULLET) {}

AObject::AObject(int c, int y, int x, int dmg) :
		sym(c), y(y), x(x), hp(1), dmg(dmg), sp(10), type(BULLET) {
	f->update(y, x, c, this);
}

AObject::AObject(int c, int y, int x, int hp, int dmg) :
		sym(c), y(y), x(x), hp(hp), dmg(dmg), sp(10), type(REGULAR) {
	while (!f->isEmpty(this->y, this->x)) {
		this->x = RANDX;
		this->y = RANDY;
	}
	f->update(y, x, c, this);
}

AObject::AObject(AObject const &copy) :
		sym(copy.sym), y(copy.y), x(copy.x), type(copy.type) {
	f->update(y, x, sym, this);
}

AObject::~AObject() {
	if (f->getObject(y, x) == this)
		f->erase(y, x);
}

AObject &AObject::operator=(AObject const &ass) {
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

void AObject::setF(Field *f) {
	AObject::f = f;
}

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

void AObject::erase() {
	this->dmg = -1;
	f->erase(y, x);
}

void AObject::update() {
	this->dmg = 1;
	this->hp = 1;
	this->x = RANDX;
	this->y = RANDY;
	while (!f->isEmpty(this->y, this->x)) {
		this->x = RANDX;
		this->y = RANDY;
	}
	f->update(y, x, sym, this);
}

int AObject::getDmg() const {
	return dmg;
}

int AObject::getSp() const {
	return sp;
}
