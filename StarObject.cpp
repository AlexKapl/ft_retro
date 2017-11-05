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

int        StarObject::count = 0;

List *StarObject::stack = new List();

StarObject::StarObject() :
		AObject('.', (rand() % (H / 2)) + 1, (rand() % (W - 2)) + 1) {
	StarObject::count++;
}

StarObject::StarObject(StarObject const &copy) : AObject(copy) {
	StarObject::count++;
}

StarObject::~StarObject() {
	StarObject::count--;
	AObject::~AObject();
}

StarObject &StarObject::operator=(StarObject const &) {
	return *this;
}

int StarObject::fall() {
	f->erase(this->y, this->x);
	this->y++;
	if (this->y < H - 1) {
		f->update(this->y, this->x, this->sym);
		return (1);
	}
	else
		return (0);
}

int StarObject::getCount() {
	return count;
}

void StarObject::update() {
	StarObject::stack->iterate(&StarObject::clean);
	for (int i = 0; i < STAR; i++) {
		StarObject::stack->push(new StarObject());
	}
}

int StarObject::clean(void *data) {
	StarObject *star = static_cast<StarObject *>(data);

	if (star->fall()) {
		return (1);
	}
	else {
		delete (star);
		return (0);
	}
}
