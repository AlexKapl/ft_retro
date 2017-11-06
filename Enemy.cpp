/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <akaplyar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 17:08:00 by akaplyar          #+#    #+#             */
/*   Updated: 2017/11/05 17:08:00 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

Enemy::Enemy() : AObject('X' + COLOR_PAIR(2), RANDY, RANDX, 1, 10) {
	sp = 20;
	type = SHIP;
}

Enemy::Enemy(Enemy const &copy) : AObject(copy) {}

Enemy::~Enemy() {
}

Enemy &Enemy::operator=(Enemy const & ass) {
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

int Enemy::fall() {
	AObject *obj;

	if (f->getObject(y, x) == this)
		f->erase(y, x);
	this->y++;
	if (y < H - 2) {
		obj = f->getObject(y, x);
		if (obj == nullptr || obj->getType() < SHIP) {
			f->update(y, x, sym, this);
			return (1);
		}
		else {
			obj->getDamage(this->dmg);
		}
	}
	return (0);
}

void Enemy::update() {
	AObject::update();
	this->dmg = 2;
}
