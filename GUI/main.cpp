#include "widget.h"

#include <QApplication>


std::vector<Player> players;
std::string combatOrder [10];

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}
