/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ObjectSpawner.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <akaplyar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 12:28:00 by akaplyar          #+#    #+#             */
/*   Updated: 2017/11/05 12:28:00 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef OBJECTSPAWNER_HPP
# define OBJECTSPAWNER_HPP

# include "StarObject.hpp"
# include "Asteroid.hpp"
# include "List.hpp"
# include "Enemy.hpp"

class ObjectSpawner {

public:
	ObjectSpawner();

	ObjectSpawner(ObjectSpawner const &copy);

	~ObjectSpawner();

	ObjectSpawner &operator=(ObjectSpawner const &assign);

	void		update();

private:
	void		updateStars();

	void		updateAsteroids();

	StarObject**	stars;
	Asteroid**		asteroids;
	Enemy**			enemies;
	int				starCount;
	int				asterCount;
	clock_t			starClock;
};


#endif
