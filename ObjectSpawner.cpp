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
		stars(new StarObject *[40]),
		asteroids(new Asteroid *[10]),
		enemies(new Enemy *[10]),
		bullets(new Bullet *[20]),
		powerUp(new PowerUp),
		starCount(50), asterCount(10),
		enemyCount(10), bulletCount(20), bullet(0),
		starClock(clock()), enemyClock(starClock),
		bulletClock(starClock) {
	for (int i = 0; i < bulletCount; ++i) {
		bullets[i] = new Bullet();
	}
	for (int i = 0; i < starCount; ++i) {
		stars[i] = new StarObject();
	}
	for (int i = 0; i < enemyCount; ++i) {
		enemies[i] = new Enemy();
		asteroids[i] = new Asteroid();
	}
}

ObjectSpawner::ObjectSpawner(ObjectSpawner const &)
		: stars(), asteroids(), enemies(), bullets(), starCount(), asterCount(),
		  enemyCount(), bulletCount(), bullet(), starClock(), bulletClock() {}

ObjectSpawner::~ObjectSpawner() {
	delete[](stars);
	delete[](asteroids);
}

ObjectSpawner &ObjectSpawner::operator=(ObjectSpawner const &ass) {
	if (this != &ass) {
		this->stars = ass.stars;
		this->asteroids = ass.asteroids;
		this->enemies = ass.enemies;
		this->bullets = ass.bullets;
		this->powerUp = ass.powerUp;
		this->starCount = ass.starCount;
		this->enemyCount = ass.enemyCount;
		this->bullet = ass.bullet;
		this->starClock = ass.starClock;
		this->enemyClock = ass.enemyClock;
		this->bulletClock = ass.starClock;
	}
	return *this;
}

void ObjectSpawner::spawnBullet(int type, int y, int x, int dmg) {
	int i = 0;

	if (bullet < bulletCount)
		while (i < bulletCount) {
			if (bullets[i]->getDmg() == -1) {
				bullets[i]->setBullet(type, y, x, dmg);
				bullet++;
				return;
			}
			i++;
		}
}

void ObjectSpawner::update() {
	float diff = (static_cast<float>((clock() - enemyClock)) / CLOCKS_PER_SEC *
				  10000);

	if ((static_cast<float>((clock() - bulletClock))
		 / CLOCKS_PER_SEC * 10000) > 500)
		updateBullets();
	if ((static_cast<float>((clock() - starClock))
		 / CLOCKS_PER_SEC * 10000) > 800)
		updateStars();
	if (diff > 1000) {
		updateAsteroids();
		updateEnemies();
	}
}

void ObjectSpawner::updateStars() {
	for (int i = 0; i < starCount; i++) {
		if (stars[i]->getDmg() == -1) {
			stars[i]->update();
		}
		else if (!stars[i]->fall()) {
			stars[i]->erase();
		}
	}
	if (powerUp->getDmg() == -1) {
		powerUp->update();
	}
	else if (!powerUp->fall())
		powerUp->erase();
	starClock = clock();
}

void ObjectSpawner::updateAsteroids() {
	for (int i = 0; i < asterCount; i++) {
		if (asteroids[i]->getDmg() == -1) {
			asteroids[i]->update();
		}
		else if (!asteroids[i]->getHp()) {
			asteroids[i]->erase();
		}
		else if (!asteroids[i]->fall()) {
			asteroids[i]->erase();
		}
	}
}

void ObjectSpawner::updateEnemies() {
	for (int i = 0; i < enemyCount; i++) {
		if (enemies[i]->getDmg() == -1) {
			enemies[i]->update();
		}
		else if (!enemies[i]->getHp()) {
			enemies[i]->erase();
		}
		else if (!enemies[i]->fall()) {
			enemies[i]->erase();
		}
	}
	enemyClock = clock();
}

void ObjectSpawner::updateBullets() {
	for (int i = 0; i < bulletCount; i++) {
		if (bullets[i]->getDmg() > 0 && !bullets[i]->fall()) {
			bullets[i]->erase();
			bullet--;
		}
	}
	bulletClock = clock();
}
