/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <akaplyar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 15:29:00 by akaplyar          #+#    #+#             */
/*   Updated: 2017/11/04 15:29:00 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_retro.h"
#include "Player.hpp"

static void init_ncurses() {
	initscr();
	refresh();
	cbreak();
	noecho();
	curs_set(0);
	nodelay(stdscr, true);
	keypad(stdscr, true);
	start_color();
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_BLUE, COLOR_BLACK);
	init_pair(4, COLOR_CYAN, COLOR_BLACK);
	init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(6, COLOR_YELLOW, COLOR_BLACK);
}

static void game_loop() {
	Field *f = new Field();
	AObject::setF(f);
	Player *player = new Player();
	ObjectSpawner *spawner = new ObjectSpawner();
	int key;

	do {
		key = getch();
		if (player->setPause(key)) {
			player->keyHook(key, spawner);
			spawner->update();
			f->updateInfo(player->getHp());
			wrefresh(f->getWin());
		}
	} while (key != 'q');
}

int main() {

	srand(time(nullptr));
	init_ncurses();
	game_loop();
	return (0);
}