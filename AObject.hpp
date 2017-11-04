/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AObject.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <akaplyar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 16:46:00 by akaplyar          #+#    #+#             */
/*   Updated: 2017/11/04 16:46:00 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef AOBJECT_HPP
# define AOBJECT_HPP

# include "Field.hpp"

class AObject {

public:
	AObject();

	AObject(Field *, char, int, int);

	AObject(AObject const &copy);

	virtual ~AObject();

	AObject &operator=(AObject const &assign);

protected:
	Field *f;
	char sym;
	int y;
	int x;

};


#endif
