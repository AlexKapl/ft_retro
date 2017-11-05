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

# include "ft_retro.h"
# include "Field.hpp"

class AObject {

public:
	AObject();

	AObject(char, int, int);

	AObject(AObject const &copy);

	virtual ~AObject();

	AObject &operator=(AObject const &assign);

	static void setF(Field *f);

protected:
	char sym;
	int y;
	int x;

	static Field *f;
};


#endif
