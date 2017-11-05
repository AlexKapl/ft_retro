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
	enum type_e {REGULAR = 1, ASTEROID, SHIP, BULLET};

	AObject();

	AObject(int, int, int, int, int);

	AObject(int, int, int, int);

	AObject(AObject const &copy);

	virtual ~AObject();

	AObject &operator=(AObject const &assign);

	static void setF(Field *f);

	int getHp() const;

	int getSp() const;

	type_e getType() const;

	void			erase();

	virtual void update();

	virtual int		fall() = 0;

	virtual void	getDamage(int dmg);

	int getDmg() const;

protected:
	int		sym;
	int		y;
	int		x;
	int		hp;
	int		dmg;
	int		sp;
	type_e type;

	static Field *f;
};


#endif
