/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <akaplyar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 17:08:00 by akaplyar          #+#    #+#             */
/*   Updated: 2017/11/05 17:08:00 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP

#include "AObject.hpp"

class Enemy :
		public AObject{

public:
	Enemy();

	Enemy(Enemy const &copy);

	~Enemy();

	Enemy &operator=(Enemy const &assign);

	virtual int		fall();

private:

};


#endif
