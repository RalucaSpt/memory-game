#include "GameUI.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    gameLogic::Game game;
    GameUI w (&game) ;
    w.show();
    return a.exec();
}
