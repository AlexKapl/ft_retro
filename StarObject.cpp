/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StarObject.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <akaplyar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 18:08:00 by akaplyar          #+#    #+#             */
/*   Updated: 2017/11/04 18:08:00 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "StarObject.hpp"

StarObject::StarObject(Field *f) : AObject(f, 'A', 1, 1) {}

StarObject::StarObject(StarObject const &copy) : AObject(copy) {}

StarObject::~StarObject() {}

StarObject &StarObject::operator=(StarObject const &) {
	return *this;
}

void StarObject::fall() {
	this->y++;
}
