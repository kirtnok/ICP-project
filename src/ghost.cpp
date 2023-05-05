#include <tuple>
#include "map_object.h"
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QBrush>
#include <QColor>
#include <QPen>
#include <QGraphicsItem>
#include "ghost.h"
#include "map.h"
#include <iostream>
#include <random>
#include <utility>
#include "pacman.h"
#include <QObject>
#include <QGraphicsView>
#include <utility>

Ghost::Ghost(std::pair<int,int> map_index, QGraphicsView *view) : QObject(), view(view){
    this->direction = 0;
    this->position = std::make_pair(map_index.first*50, map_index.second*50);
    this->setBrush(QBrush(QImage("./textures/ghosts/ghost1.png").scaled(50,50)));
    this->setRect(0,0,50,50);
    this->setPen(Qt::NoPen);
    this->setPos(this->position.first, this->position.second);
    this->view->scene()->addItem(this);
    this->movement.push_back(this->position);

    mAnimation = new QVariantAnimation(this);
    mAnimation->setDuration(200);

    connect(mAnimation, &QVariantAnimation::valueChanged, this, &Ghost::onAnimationChanged);
    
}
Ghost::~Ghost(){
    delete mAnimation;
}

void Ghost::move(std::pair<int, int>old_position){
    mAnimation->setStartValue(QRectF(old_position.first, old_position.second, 50, 50));
    mAnimation->setEndValue(QRectF(this->position.first, this->position.second, 50, 50));
    mAnimation->start();
}
void Ghost::onAnimationChanged(const QVariant &value){
    this->setPos(value.toRectF().topLeft());
    update();
}


void Ghost::check_collision(QGraphicsScene &scene, Map &map, Pacman &pacman){
    if (pacman.position == this->position){
        pacman.pacman_end();
    // todo
    }
}
