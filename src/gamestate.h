#ifndef GAMESTATE_H
#define GAMESTATE_H
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QTimer>
#include "pacman.h"
#include "map.h"
#include "ghost.h"
#include "key.h"
#include "backend.h"
class GameState: public QObject{
public:
    GameState(QGraphicsView *view, Backend *backend);
    ~GameState();
    void add_ghost(Ghost &ghost);
    void add_key(Key &key);
    void set_pacman_dir(int direction);
    std::pair<int, int> end;
    void replay_print();
    bool stopped();
private slots:
    void update();
private:
    Pacman *pacman;
    QGraphicsView *view;
    Backend *backend;
    QTimer *timer;
    std::vector<Ghost*> ghosts;
    std::vector<Key*> keys;
    bool stop;
};


#endif // GAMESTATE_H
