#include"Entity.h"


Entity::Entity()
{
	m_sprite = NULL;
}
Entity::~Entity()
{

}

Sprite* Entity::getSprite()
{
	return this->m_sprite;
}

void Entity::bindSprite(Sprite* sprite)
{
	m_sprite = sprite;
	this->addChild(m_sprite);
}

void Entity::setController(MyController* controller)
{
	this->m_controller = controller;
	m_controller->setControllerListener(this);
}

void Entity::setTagPosition(int x, int y)
{
	setPosition(Point(x, y));
}

Point Entity::getTagPosition()
{
	return getPosition();
}