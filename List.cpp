/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <akaplyar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 18:15:00 by akaplyar          #+#    #+#             */
/*   Updated: 2017/11/04 18:15:00 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "List.hpp"

List::s_list::s_list() : data(nullptr), next(nullptr), prev(nullptr) {}

List::s_list::s_list(void *data) :
		data(data), next(nullptr), prev(nullptr) {}

List::s_list::s_list(void *data, List::s_list * p) :
	data(data), next(nullptr), prev(p) {}

List::s_list::~s_list() {}

List::List() : list(new s_list()), start(list), end(list) {}

List::List(void *data) : list(new s_list(data)), start(list), end(list) {}

List::List(void *data, List *l) :
		list(new s_list(data, l->list)), start(l->start), end(list) {}

List::List(List const &copy) :
		list(copy.list), start(copy.start), end(copy.end) {}

List::~List() {
	s_list	*del;

	while (list) {
		del = list;
		list = list->next;
		delete(del);
	}
}

List &List::operator=(List const &) {
	return (*this);
}

void List::push(void *data) {
	if (this->list->data == nullptr)
		this->list->data = data;
	else {
		this->end->next = new s_list(data, this->end);
		this->end = this->end->next;
	}
}

void List::iterate(int (*f)(void *)) {
	s_list	*iterator = list, *del;

	while (iterator && iterator->data) {
		if (!f(iterator->data)) {
			del = iterator;
			if (iterator == list)
				list = iterator->next;
			if (iterator->prev)
				iterator->prev->next = iterator->next;
			if (iterator->next)
				iterator->next->prev = iterator->prev;
			iterator = iterator->next;
			del->data = nullptr;
			delete(del);
		}
		else
			iterator = iterator->next;
	}
//	if ()
}
