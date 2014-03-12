#ifndef ENTITY_H
#define ENTITY_H

#include "sprite.h"
#include "types.h"

class Entity
{
public:
    Entity();

    void Move();
    void GoLeft();
    void GoRight();
    void StopLeft();
    void StopRight();


protected:
	enum { DefaultXVelocity = 20,
		DefaultYAcceleration = 60};

	Sprite *m_sprite;

private:
	double m_x, m_y;
	double m_dx, m_dy;

};

#endif // ENTITY_H
