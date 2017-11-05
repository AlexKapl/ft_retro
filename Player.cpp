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

Player::Player() : AObject('A', 1, 1) {}

Player::Player(Player const &copy) : AObject(copy) {}

Player::~Player() {}

Player &Player::operator=(Player const &) {
	return *this;
}

void Player::move(int x, int y) {
	f->erase(this->y, this->x);
	if (y > 0 && y < f->getH() - 1)
		this->y = y;
	if (x > 0 && x < f->getW() - 1)
		this->x = x;
	f->update(this->y, this->x, this->sym);
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
			nodelay(stdscr, false);
			break;
		default:
//			wprintw(f->getWin(), "%d", key);
//			wrefresh(f->getWin());
			break;
	}
}
