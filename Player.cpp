/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <akaplyar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 16:14:00 by akaplyar          #+#    #+#             */
/*   Updated: 2017/11/04 16:14:00 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"

Player::Player() : AObject('A' + COLOR_PAIR(1), H - 3, W / 2, 2, 10),
				   pause(true), bullet('^' + COLOR_PAIR(3)) {
	sp = 0;
	type = SHIP;
}

Player::Player(Player const &copy) : AObject(copy) {}

Player::~Player() {
}

Player &Player::operator=(Player const & ass) {
	if (this != &ass) {
		this->sym = ass.sym;
		this->y = ass.y;
		this->x = ass.x;
		this->hp = ass.hp;
		this->dmg = ass.dmg;
		this->sp = ass.sp;
		this->type = ass.type;
		this->pause = ass.pause;
		this->bullet = ass.bullet;
	}
	return *this;
}

void Player::move(int x, int y) {
	f->erase(this->y, this->x);
	if (y > 0 && y < f->getH() - 2)
		this->y = y;
	if (x > 0 && x < f->getW() - 1)
		this->x = x;
	f->update(this->y, this->x, this->sym, this);
}

void Player::keyHook(int key, ObjectSpawner *spawner) {
	switch (key) {
		case LEFT:
			this->move(this->x - 1, this->y);
			break;
		case RIGHT:
			this->move(this->x + 1, this->y);
			break;
		case UP:
			this->move(this->x, this->y + 1);
			break;
		case DOWN:
			this->move(this->x, this->y - 1);
			break;
		case ATTACK:
			spawner->spawnBullet(bullet, y, x, dmg);
			break;
		default:
			this->move(this->x, this->y);
			break;
	}
}

bool Player::setPause(int key) {
	if (key == PAUSE) {
		pause = !pause;
		nodelay(stdscr, pause);
	}
	if (!hp) {
		wattron(f->getInfo(), COLOR_PAIR(2));
		mvwprintw(f->getInfo(), 5, W / 2 - 5, "GAME OVER");
		wrefresh(f->getInfo());
		nodelay(stdscr, false);
		while (getch() != 'q');
		endwin();
		exit(1);
	}
	return pause;
}

int Player::fall() {
	return 0;
}

void Player::getDamage(int dmg) {
	if (dmg > 32 && dmg < 40) {
		this->bullet = dmg + COLOR_PAIR(rand() % 3 + 3);
		if (++this->hp > 5)
			this->hp = 5;
	}
	else {
		this->hp -= dmg;
		if (this->hp < 0)
			this->hp = 0;
	}
}
