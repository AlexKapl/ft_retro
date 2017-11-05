/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ObjectDamageable.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <akaplyar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 12:42:00 by akaplyar          #+#    #+#             */
/*   Updated: 2017/11/05 12:42:00 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef OBJECTDAMAGEABLE_HPP
# define OBJECTDAMAGEABLE_HPP

# include "AObject.hpp"

class ObjectDamageable :
		virtual public AObject {

public:
	ObjectDamageable();

	ObjectDamageable(char, int, int, int, int);

	ObjectDamageable(ObjectDamageable const &copy);

	virtual ~ObjectDamageable();

	ObjectDamageable &operator=(ObjectDamageable const &assign);

	int getHp() const;

	void		getDamage(int dmg);

protected:
	int		hp;
	int		dmg;

};


#endif
