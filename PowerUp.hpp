/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerUp.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <akaplyar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 22:12:00 by akaplyar          #+#    #+#             */
/*   Updated: 2017/11/05 22:12:00 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef POWERUP_HPP
# define POWERUP_HPP


#include "AObject.hpp"

class PowerUp :
		public AObject {

public:
	PowerUp();

	PowerUp(PowerUp const &copy);

	~PowerUp();

	PowerUp &operator=(PowerUp const &assign);

	virtual int		fall();

	virtual void update();

private:

};


#endif
