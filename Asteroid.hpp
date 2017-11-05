/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Asteroid.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <akaplyar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 13:35:00 by akaplyar          #+#    #+#             */
/*   Updated: 2017/11/05 13:35:00 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ASTEROID_HPP
# define ASTEROID_HPP

#include "ObjectDamageable.hpp"

class Asteroid :
		public ObjectDamageable {

public:
	Asteroid();

	Asteroid(Asteroid const &copy);

	~Asteroid();

	Asteroid &operator=(Asteroid const &assign);

	virtual int		fall();

private:

};


#endif
