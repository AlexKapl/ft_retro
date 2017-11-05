#include "Bullet.hpp"

Bullet::Bullet() : AObject() {
	this->hp = -1;
}

Bullet::Bullet(int type, int y, int x, int dmg) :
		AObject(type, y - 1, x, dmg) {
}

Bullet::Bullet(Bullet const &src) :
		AObject(src) {}

Bullet::~Bullet() {

}

Bullet &Bullet::operator=(Bullet const &) {
	return *this;
}

int Bullet::fall() {
	AObject *obj;

	if (f->getObject(y, x) == this)
		f->erase(y, x);
	this->y--;
	if (y > 0) {
		obj = f->getObject(y, x);
		if (obj == nullptr || obj->getType() == REGULAR) {
			f->update(y, x, sym, this);
			return (1);
		}
		else {
			obj->getDamage(this->dmg);
		}
	}
	return (0);
}