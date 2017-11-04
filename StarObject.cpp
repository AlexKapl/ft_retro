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

StarObject::StarObject(Field *f) :
		AObject(f, '.', (rand() % (H / 2)) + 1, (rand() % (W - 2)) + 1) {
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

void StarObject::fall() {
	f->erase(this->y, this->x);
	this->y++;
	if (this->y < H - 1)
		f->update(this->y, this->x, this->sym);
}

int StarObject::getCount() {
	return count;
}

void StarObject::update(Field *f) {
	StarObject::clean();
	for (int i = 0; i < STAR; i++) {
//	while (StarObject::count < STAR) {
		StarObject::stack->push(new StarObject(f));
	}
}

void StarObject::clean() {
	List *list = new List();
	StarObject *star;
	int i, j = StarObject::count;

	for (i = 0; i < j; i++) {
		star = static_cast<StarObject *>(StarObject::stack->pop());
		star->fall();
		if (star->y >= H - 2) {
			delete (star);
		}
		else {
			list->push(star);
		}
	}
	delete(StarObject::stack);
	StarObject::stack = list;
}
