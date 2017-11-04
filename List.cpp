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

List::List() : data(nullptr), next(nullptr){}

List::List(void *data) : data(data), next(nullptr){}

List::List(List const &copy) : data(copy.data), next(copy.next) {}

List::~List() {
	this->data = nullptr;
	this->next = nullptr;
}

List &List::operator=(List const &) {
	return (*this);
}

void	List::push(void *data) {
	List *list = this;

	if (this->data == nullptr)
		this->data = data;
	else {
		while (list->next)
			list = list->next;
		list->next = new List(data);
	}
}

void *List::pop() {
	List *list = this;

	while (this->list) {
		list = this->list;
		this->list = this->list->next;
		delete(list->unit);
		delete (list);
	}
	return NULL;
}
