#include <stdlib.h>
#include <ncurses.h>
#include "main.h"

Player * playerSetUp() {
  Player * newPlayer;
  newPlayer = malloc(sizeof(Player));

  // newPlayer->pos.x = firstRoom->pos.x + (firstRoom->width / 2);
  // newPlayer->pos.y = firstRoom->pos.y + (firstRoom->height / 2);

  return newPlayer;
}






void playerMove(int y, int x, Player *user, Tile ** map) {

  int newX, newY;

  newY = y + user->pos.y;
  newX = x + user->pos.x;
  
  switch (map[newY][newX].ch) {
    case '#':
    case '|':
    case '-':
      move(user->pos.y,user->pos.x);
      break;
    case '.':
      map[user->pos.y][user->pos.x].ch = '.';
      user->pos.x += x;
      user->pos.y += y;
      updatePlayerPosition(user,map);
      break;
    case '+':
    case ' ':
      map[user->pos.y][user->pos.x].ch = '+';
      user->pos.x += x;
      user->pos.y += y;
      updatePlayerPosition(user,map);
      break;
  }
}





void updatePlayerPosition(Player *user, Tile ** map) {
  map[user->pos.y][user->pos.x].ch = '@';
  // mvprintw(0,0,"y: %d | x: %d",user->pos.y, user->pos.x);
  move(user->pos.y,user->pos.x);
}