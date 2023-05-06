#include "main_scene.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QVBoxLayout>
#include <QGraphicsItem>
#include <iostream>
#include <tuple>
#include <utility>
#include "map.h"
#include <string>

MainScene::MainScene(Map* map,QWidget *parent)
    : QGraphicsScene(parent)
{
    // QPixmap wall(":/textures/misc/wall.png");
    // QPixmap dot(":/textures/misc/dot.png");
    // QPixmap target(":/textures/misc/target.png");
    // QPixmap key(":/textures/misc/key.png");
    // QPixmap pacman(":/textures/pacman/pacman1.png");
    // QPixmap ghost(":/textures/ghost/ghost1.png");

    // if (true){
    //     this->map= new Map("./examples/tmp.txt");
    // }
    // else{
    //     this->map= new Map("./examples/map-01.txt");
    // }
    
    this->map = map;

    for (int row = 0; row < map->map.size(); row++) {
        for (int col = 0; col < map->map[row].size(); col++) {
            map->map[row][col]->setRect(col*50, row*50, 50, 50);
            if (map->map[row][col]->color == Qt::black) {
                // wall, so set texture of wall from ../textures/misc/wall.png
                map->map[row][col]->setBrush(QBrush(QImage("./textures/misc/wall.png").scaled(50,50)));
            }
            else if(map->map[row][col]->color == Qt::blue) {
                map->map[row][col]->setBrush(QBrush(QImage("./textures/misc/targer.png").scaled(50,50)));
            }
            else if (map->map[row][col]->color == Qt::yellow) {
                map->map[row][col]->setBrush(QBrush(QImage("./textures/misc/key.png").scaled(50,50)));
            }
            else if (map->map[row][col]->color == Qt::blue) {
                map->map[row][col]->setBrush(QBrush(QImage("./textures/misc/targer.png").scaled(50,50)));
            }
            else if (map->map[row][col]->color == Qt::green) {
                map->map[row][col]->setBrush(QBrush(QImage("./textures/misc/dot.png").scaled(50,50)));
            }
            else{
                map->map[row][col]->setBrush(QBrush(QImage("./textures/misc/dot.png").scaled(50,50)));
            }
            map->map[row][col]->setPen(Qt::NoPen);
            this->addItem(map->map[row][col]);

        }
    }
    this->movesText = new QGraphicsTextItem();
    this->movesText->setPlainText("Moves: 0");
    this->movesText->setPos(this->map->width*50+10,0);
    this->addItem(movesText);
    // connect 
}
void MainScene::updateMovesText()
{
    static int moves = 0;
    moves++;
    this->movesText->setPlainText("Moves: " + QString::number(moves));
}
MainScene::~MainScene(){
    delete map;
    delete movesText;
}

