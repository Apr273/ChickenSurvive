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
	this->m_sprite = sprite;
	this->addChild(m_sprite);

	Size size = m_sprite->getContentSize();
	m_sprite->setPosition(Point(size.width * 0.5f, size.height * 0.5f));
	this->setContentSize(size);
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