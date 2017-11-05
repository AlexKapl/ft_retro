/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AObject.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <akaplyar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 16:46:00 by akaplyar          #+#    #+#             */
/*   Updated: 2017/11/04 16:46:00 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AObject.hpp"

Field* 	AObject::f = nullptr;

AObject::AObject(char c, int y, int x) : sym(c), y(y), x(x) {
	f->update(y, x, c);
}

AObject::AObject(AObject const &copy) : sym(copy.sym), y(copy.y), x(copy.x) {
	f->update(y, x, sym);
}

AObject::~AObject() {
	f->erase(y, x);
}

AObject &AObject::operator=(AObject const &) {
	return *this;
}

void AObject::setF(Field *f) {
	AObject::f = f;
}
