/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StarObject.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <akaplyar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 18:08:00 by akaplyar          #+#    #+#             */
/*   Updated: 2017/11/04 18:08:00 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef STAROBJECT_HPP
# define STAROBJECT_HPP

#include "AObject.hpp"
#include "List.hpp"

class StarObject :
		public AObject {

public:
	explicit StarObject(Field *);

	StarObject(StarObject const &);

	~StarObject();

	StarObject &operator=(StarObject const &);

	static int getCount();

	static void	update(Field *f);

private:
	void	fall();

	static List	*stack;

	static int count;

	static void	clean();

};


#endif
