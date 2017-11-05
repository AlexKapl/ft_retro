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
		stars(new StarObject *[70]),
		asteroids(new Asteroid *[10]),
		enemies(new Enemy *[10]),
		bullets(new Bullet *[20]),
		starCount(50), asterCount(10),
		enemyCount(10), bulletCount(20), bullet(0),
		starClock(clock()), bulletClock(starClock) {
	for (int i = 0; i < bulletCount; ++i) {
		bullets[i] = new Bullet();
	}
}

ObjectSpawner::ObjectSpawner(ObjectSpawner const &)
		: stars(), asteroids(), enemies(), bullets(), starCount(), asterCount(),
		  enemyCount(), bulletCount(), bullet(), starClock(), bulletClock() {}

ObjectSpawner::~ObjectSpawner() {
	delete[](stars);
	delete[](asteroids);
}

ObjectSpawner &ObjectSpawner::operator=(ObjectSpawner const &) {
	return *this;
}

void ObjectSpawner::spawnBullet(int type, int y, int x, int dmg) {
	int i = 0;

	if (bullet < bulletCount)
		while (i < bulletCount) {
			if (bullets[i]->getHp() == -1) {
				bullets[i]->setBullet();
				bullet++;
				return;
			}
			i++;
		}
}

void ObjectSpawner::update() {
	float diff = (static_cast<float>((clock() - starClock)) / CLOCKS_PER_SEC *
				  10000);

	if ((static_cast<float>((clock() - bulletClock))
		 / CLOCKS_PER_SEC * 10000) > 500)
		updateBullets();
	if (diff > 1000) {
		updateStars();
		updateAsteroids();
		updateEnemies();
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
		else if (!asteroids[i]->getHp()) {
			delete (asteroids[i]);
			asteroids[i] = nullptr;
		}
		if (asteroids[i] && !asteroids[i]->fall()) {
			delete (asteroids[i]);
			asteroids[i] = nullptr;
		}
	}
	starClock = clock();
}

void ObjectSpawner::updateEnemies() {
	for (int i = 0; i < enemyCount; i++) {
		if (!enemies[i])
			enemies[i] = new Enemy();
		else if (!enemies[i]->getHp()) {
			delete (enemies[i]);
			enemies[i] = nullptr;
		}
		if (enemies[i] && !enemies[i]->fall()) {
			delete (enemies[i]);
			enemies[i] = nullptr;
		}
	}
}

void ObjectSpawner::updateBullets() {
	for (int i = 0; i < bulletCount; i++) {
		if (bullets[i] && !bullets[i]->fall()) {
			delete (bullets[i]);
			bullets[i] = nullptr;
			bullet--;
		}
	}
	bulletClock = clock();
}
