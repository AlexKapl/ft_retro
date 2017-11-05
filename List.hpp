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

	void	push(void *data);

	void	iterate(int (*f)(void *));

private:
	struct		s_list{
		void	*data;
		s_list	*next;
		s_list	*prev;

		s_list();

		explicit s_list(void *data);

		s_list(void *data, s_list * p);

		~s_list();
	}			*list;

	s_list		*start;
	s_list		*end;
};


#endif
