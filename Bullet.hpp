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
	
private:

};

#endif