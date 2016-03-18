/* File game.h */
#ifndef GAME_H
#define GAME_H

#include <cstdlib>
#include <cmath>
#include <time.h>

#include "game_const.h"
#include "global.h"
#include "scene.h"

#include "object.h"
#include "player.h"
#include "asteroid.h"
#include "bullet.h"
#include "collision.h"
#include "lifes_line.h"
#include "score.h"

class Game : public Scene{
  private:
    int touch_id;
    Player player;
    std::list<Bullet> bullets;
    int amount_bullets;
    float bullets_timer;
    std::list<Asteroid> asteroids;
    int amount_asteroids;
    float asteroids_timer;
    LifesLine lifes_line;
    Score score;
    Polygon GetRandomPolygon(float size);
    bool SplitAsteroid(Asteroid parent, Asteroid* child1, Asteroid* child2);
  public:
    void Init();
    void Input(int type, int id, float x, float y);
    void Loop();
    void Render();
    void Cleanup();
};

#endif
/* GAME_H */
