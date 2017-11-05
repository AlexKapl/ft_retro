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
	StarObject();

	StarObject(StarObject const &);

	virtual ~StarObject();

	StarObject &operator=(StarObject const &);

	int		fall();

private:

};


#endif
