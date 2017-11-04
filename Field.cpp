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
		: win(newwin(Field::h, Field::w, 0, 0)) {
	wborder(win, '|', '|', 0, 0, 0, 0, 0, 0);
	wrefresh(win);
}

Field::Field(Field const &copy) : win(copy.win) {}

Field::~Field() {}

Field &Field::operator=(Field const &) {
	return *this;
}

int Field::getH() {
	return Field::h;
}

int Field::getW() {
	return Field::w;
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
