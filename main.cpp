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
#include "StarObject.hpp"

static void init_ncurses() {
	initscr();
	refresh();
	cbreak();
	noecho();
	curs_set(0);
	nodelay(stdscr, true);
	keypad(stdscr, true);
	start_color();
}

static void game_loop() {
	Field *f = new Field();
	AObject::setF(f);
	Player player;
	int key = 0;
	int i = 0;

	do {
		key = getch();
		player.keyHook(key);
		StarObject::update();
		i++;
		usleep(10000);
	} while (key != 'q');
}

int main() {

	srand(time(nullptr));
	init_ncurses();
	game_loop();
	return (0);
}