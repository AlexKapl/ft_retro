#include "Bullet.hpp"

Bullet::Bullet()
{
}

Bullet::Bullet(int type, int x, int y, int dmg) : AObject(type, x, y - 1, dmg, 1)
{
	type = BULLET;
}

Bullet::Bullet(Bullet const &src) : 
	AObject(src) {}
Bullet::~Bullet() 
{

}

Bullet 	&Bullet::operator=(Bullet const &)
{
	return *this;
}

int		Bullet::fall()
{
	AObject	*obj;
	f->erase(x, y);
	y--;
	if (y > 0) 
	{
		obj = f->getObject(y, x);
		if (obj == nullptr || obj->getType() == REGULAR) 
		{
			f->update(y, x, sym, this);
			return (1);
		}
		else
			obj->getDamage(this->dmg);
	}
	return (0);
}