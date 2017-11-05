/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Field.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <akaplyar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 17:02:00 by akaplyar          #+#    #+#             */
/*   Updated: 2017/11/04 17:02:00 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Field.hpp"

Field::Field() :
		h(H), w(W), f(new AObject **[h]),
		win(newwin(h, w, 0, 0)),
		info(newwin(10, w, h - 1, 0)) {
	for (int i = 0; i < h; i++)
		f[i] = new AObject *[w];
	wborder(win, 0, 0, 0, 0, 0, 0, 0, 0);
	wborder(info, 0, 0, 0, 0, '|', '|', 0, 0);
	wrefresh(win);
	wrefresh(info);
}

Field::Field(Field const &copy) : h(H), w(W), win(copy.win) {}

Field::~Field() {}

Field &Field::operator=(Field const &) {
	return *this;
}

int Field::getH() {
	return h;
}

int Field::getW() {
	return w;
}

void Field::erase(const int y, const int x) {
	if (y > 0 && y < h && x > 0 && x < w){
		mvwaddch(this->win, y, x, Field::empty);
		f[y][x] = nullptr;
	}
}

void Field::update(const int y, const int x, const int sym, AObject *obj) {
	if (y > 0 && y < h && x > 0 && x < w) {
		mvwaddch(this->win, y, x, sym);
		f[y][x] = obj;
	}
}

WINDOW *Field::getWin() const {
	return win;
}

bool Field::isEmpty(int y, int x) {
	if (y > 0 && y < h && x > 0 && x < w) {
		return !f[y][x];
	}
	else return false;
}

AObject *Field::getObject(int y, int x) {
	if (y > 0 && y < h && x > 0 && x < w) {
		return f[y][x];
	}
	else
		return nullptr;
}

void Field::storeObject(int y, int x, AObject *obj) {
	f[y][x] = obj;
}
