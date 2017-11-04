/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <akaplyar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 18:15:00 by akaplyar          #+#    #+#             */
/*   Updated: 2017/11/04 18:15:00 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef LIST_HPP
# define LIST_HPP

# include <iostream>

class List {

public:

	List();

	explicit List(void * data);

	List(List const &copy);

	List(void *data, List *l);

	~List();

	List &operator=(List const &assign);

	void*	pop();

	void	push(void *data);

private:
	void		*data;
	List		*next;
	List		*prev;
	List		*start;
	List		*end;
};


#endif
