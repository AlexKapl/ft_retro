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

List::List() :
		data(nullptr), next(nullptr), prev(nullptr), start(this), end(this) {}

List::List(void *data) : data(data), next(nullptr), prev(nullptr),
						 start(this), end(this) {}

List::List(void *data, List *l) :
		data(data), next(nullptr), prev(l), start(l->start), end(this) {}

List::List(List const &copy) :
		data(copy.data), next(copy.next), prev(copy.prev),
		start(copy.start), end(copy.end) {}

List::~List() {
	this->data = nullptr;
	this->next = nullptr;
}

List &List::operator=(List const &) {
	return (*this);
}

void List::push(void *data) {
	List *list = this;

	if (this->data == nullptr)
		this->data = data;
	else {
		while (list->next)
			list = list->next;
		list->next = new List(data, list);
		this->end = list->next;
	}
}

void *List::pop() {
	void *data;
	List *list;

	if (this == end) {
		data = this->data;
		this->data = nullptr;
		return (data);
	}
	else {
		data = end->data;
		list = end->prev;
		delete (end);
		end = list;
		return (data);
	}
}
