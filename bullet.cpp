#include "bullet.h"
#include "enemy.h"
#include "mainwindow.h"
#include <QPainter>
#include <QPropertyAnimation>

const QSize Bullet::ms_fixedSize(8, 8);

Bullet::Bullet(QPoint startPos, QPoint targetPoint, int damage, Enemy *target,
			   MainWindow *game, const QPixmap &sprite/* = QPixmap(":/image/bullet.png")*/)
	: m_startPos(startPos)
	, m_targetPos(targetPoint)
	, m_sprite(sprite)
	, m_currentPos(startPos)
	, m_target(target)
	, m_game(game)
	, m_damage(damage)
{
}

void Bullet::draw(QPainter *painter) const
{
	painter->drawPixmap(m_currentPos, m_sprite);
}

void Bullet::move()
{
	static const int duration = 100;
	QPropertyAnimation *animation = new QPropertyAnimation(this, "m_currentPos");
	animation->setDuration(duration);
	animation->setStartValue(m_startPos);
	animation->setEndValue(m_targetPos);
	connect(animation, SIGNAL(finished()), this, SLOT(hitTarget()));

	animation->start();
}

void Bullet::hitTarget()
{
	if (m_game->enemyList().indexOf(m_target) != -1)
		m_target->getDamage(m_damage);
	m_game->removedBullet(this);
}

void Bullet::setCurrentPos(QPoint pos)
{
	m_currentPos = pos;
}

QPoint Bullet::currentPos() const
{
	return m_currentPos;
}
