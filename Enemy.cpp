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
	type = SHIP;
}

Enemy::Enemy(Enemy const &copy) : AObject(copy) {}

Enemy::~Enemy() {
}

Enemy &Enemy::operator=(Enemy const &) {
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
