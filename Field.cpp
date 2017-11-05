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

Field::Field()
		: h(H), w(W), f(new char*[h]), win(newwin(Field::h, Field::w, 0, 0)) {
	for (int i = 0; i < h; i++)
		f[i] = new char[w];
	wborder(win, '|', '|', 0, 0, 0, 0, 0, 0);
	wrefresh(win);
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
	mvwaddch(this->win, y, x, Field::empty);
	wrefresh(this->win);
}

void Field::update(const int y, const int x, const int sym) {
	mvwaddch(this->win, y, x, sym);
	wrefresh(this->win);
}

WINDOW *Field::getWin() const {
	return win;
}
