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
# include "Bullet.hpp"

class ObjectSpawner {

public:
	ObjectSpawner();

	ObjectSpawner(ObjectSpawner const &copy);

	~ObjectSpawner();

	ObjectSpawner &operator=(ObjectSpawner const &assign);

	void		update();

	void		spawnBullet(int type, int x, int y, int dmg);

private:
	void		updateStars();

	void		updateAsteroids();

	void		updateEnemies();

	void		updateBullets();

	StarObject**	stars;
	Asteroid**		asteroids;
	Enemy**			enemies;
	Bullet**		bullets;
	int				starCount;
	int				asterCount;
	int				enemyCount;
	int				bulletCount;
	int				bullet;
	clock_t			starClock;
	clock_t			bulletClock;
};


#endif
