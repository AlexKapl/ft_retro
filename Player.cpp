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
#include "Bullet.hpp"

Player::Player() : AObject('A', H - 3, W / 2, 50, 10), pause(true), bullet(0) {
	type = SHIP;
}

Player::Player(Player const &copy) : AObject(copy) {}

Player::~Player() {
}

Player &Player::operator=(Player const &) {
	return *this;
}

void Player::move(int x, int y) {
	f->erase(this->y, this->x);
	if (y > 0 && y < f->getH() - 1)
		this->y = y;
	if (x > 0 && x < f->getW() - 1)
		this->x = x;
	f->update(this->y, this->x, this->sym, this);
}

void Player::keyHook(int key) {
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
			Bullet::Bullet(bullet, x, y, dmg);
			break;
		default:
			//wprintw(f->getWin(), "%d", key);
//			wrefresh(f->getWin());
			break;
	}
}

bool Player::setPause(int key) {
	if (key == ATTACK)
		pause = !pause;
	if (!hp) {
		wprintw(f->getWin(), "GAME OVER");
		while (1);
		endwin();
		exit(1);
	}
	return pause;
}

int Player::fall() {
	return 0;
}
