#ifndef BULLET_HPP
# define BULLET_HPP

# include "AObject.hpp"

class Bullet : public AObject {

public:
	Bullet();
	Bullet(int type, int x, int y, int dmg);
	Bullet(Bullet const &copy);
	~Bullet();
	Bullet 	&operator = (Bullet const &);

	virtual int		fall();

	void			setBullet(int type, int y, int x, int dmg);

	void			freeBullet();

private:

};

#endif