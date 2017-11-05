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

ObjectSpawner::ObjectSpawner() :
		stars(new StarObject *[50]),
		asteroids(new Asteroid *[10]),
		enemies(new Enemy*[10]),
		starCount(50), asterCount(10),
		starClock(clock()) {}

ObjectSpawner::ObjectSpawner(ObjectSpawner const &) {}

ObjectSpawner::~ObjectSpawner() {
	delete[](stars);
	delete[](asteroids);
}

ObjectSpawner &ObjectSpawner::operator=(ObjectSpawner const &) {
	return *this;
}

void ObjectSpawner::update() {
	float diff = (static_cast<float>((clock() - starClock)) / CLOCKS_PER_SEC *
				  10000);

	if (diff > 1000) {
		updateStars();
		updateAsteroids();
	}
}

void ObjectSpawner::updateStars() {
	for (int i = 0; i < starCount; i++) {
		if (!stars[i])
			stars[i] = new StarObject();
		if (!stars[i]->fall()) {
			delete (stars[i]);
			stars[i] = nullptr;
		}
	}
}

void ObjectSpawner::updateAsteroids() {
	for (int i = 0; i < asterCount; i++) {
		if (!asteroids[i])
			asteroids[i] = new Asteroid();
		if (!asteroids[i]->fall()) {
			delete (asteroids[i]);
			asteroids[i] = nullptr;
		}
	}
	starClock = clock();
}
