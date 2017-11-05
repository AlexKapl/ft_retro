/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ObjectSpawner.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <akaplyar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 12:28:00 by akaplyar          #+#    #+#             */
/*   Updated: 2017/11/05 12:28:00 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ObjectSpawner.hpp"

ObjectSpawner::ObjectSpawner() : stars(new List), asteroids(new List) {}

ObjectSpawner::ObjectSpawner(ObjectSpawner const &obj) :
		stars(new List(obj.stars)) {}

ObjectSpawner::~ObjectSpawner() {
	delete(stars);
	delete(asteroids);
}

ObjectSpawner &ObjectSpawner::operator=(ObjectSpawner const &) {
	return *this;
}

void ObjectSpawner::update() {
	updateStars();
	updateAsteroids();
}

void ObjectSpawner::updateStars() {
	stars->iterate(&ObjectSpawner::clean);
	for (int i = 0; i < STAR; i++) {
		stars->push(new StarObject());
	}
}

void ObjectSpawner::updateAsteroids() {
	asteroids->iterate(&ObjectSpawner::clean);
//	for (int i = 0; i < STAR; i++) {
	asteroids->push(new Asteroid());
//	}
}

int ObjectSpawner::clean(void * data) {
	AObject *obj = static_cast<AObject *>(data);

	if (obj->fall()) {
		return (1);
	}
	else {
		delete (obj);
		return (0);
	}
}
