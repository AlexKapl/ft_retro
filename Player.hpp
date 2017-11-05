/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <akaplyar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 16:14:00 by akaplyar          #+#    #+#             */
/*   Updated: 2017/11/04 16:14:00 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PLAYER_HPP
# define PLAYER_HPP

# include "ObjectDamageable.hpp"

class Player :
		virtual public ObjectDamageable{

public:
	Player();

	Player(Player const &copy);

	~Player();

	Player &operator=(Player const &assign);

	void keyHook(int key);

	bool setPause(int key);

	virtual int		fall();

private:
	void move(int x, int y);

	bool	pause;
};


#endif
