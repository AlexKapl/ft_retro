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
		info(newwin(10, w, h - 1, 0)), start(clock()), score(0) {
	for (int i = 0; i < h; i++)
		f[i] = new AObject *[w];
	wborder(win, 0, 0, 0, 0, 0, 0, 0, 0);
	wborder(info, 0, 0, 0, 0, '|', '|', 0, 0);
	wattron(info, A_BOLD);
	mvwprintw(info, 4, 1, "Time:    0");
	mvwprintw(info, 6, 1, "Life:  0");
	mvwprintw(info, 8, 1, "Score:  0");
	wattron(info, COLOR_PAIR(1));
	mvwprintw(info, 2, 1, "SHIT CODE v1.0");
	wattroff(info, COLOR_PAIR(1));
	wrefresh(win);
	wrefresh(info);
}

Field::Field(Field const &copy) :
		h(H), w(W), win(copy.win), info(copy.info),
		score(copy.score) {}

Field::~Field() {}

Field &Field::operator=(Field const & ass) {
	if (this != &ass) {
		this->f = ass.f;
		this->info = ass.info;
		this->start = ass.start;
		this->score = ass.score;
	}
	return *this;
}

int Field::getH() {
	return h;
}

int Field::getW() {
	return w;
}

void Field::erase(const int y, const int x) {
	if (y > 0 && y < h && x > 0 && x < w) {
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
	if (y > 0 && y < h - 1 && x > 0 && x < w - 1) {
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

WINDOW *Field::getInfo() const {
	return info;
}

void Field::updateInfo(int life) {
	static int seconds = 0;
	double secondsPassed;

	secondsPassed = (clock() - start) / CLOCKS_PER_SEC;
	if (seconds < (int)secondsPassed) {
		seconds = static_cast<int>(secondsPassed);
		mvwprintw(info, 4, 8, "%3d", seconds);
	}
	mvwprintw(info, 6, 8, "%3d", life);
	mvwprintw(info, 8, 8, "%3d", score);
	wrefresh(info);
}

void Field::setScore(int score) {
	Field::score += score;
}
