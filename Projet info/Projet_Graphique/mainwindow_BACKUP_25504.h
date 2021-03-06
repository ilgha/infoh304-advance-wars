#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "player.h"
#include "ui_mainwindow.h"
#include <QMainWindow>
#include <utility>
#include <QtNetwork>
#include <QTimer>
#include "infantery.h"
#include "building.h"
#include "game.h"
#include <vector>

namespace Ui {
class MainWindow;
}

typedef std::pair <int, int> IntPair;

class MainWindow : public QMainWindow
{
    Q_OBJECT



    //map 25087
    int t[17][21];
    QWidget* qMap = new QWidget;
    QWidget* Menu = new QWidget;
    Player* player = nullptr;
    Game* game = nullptr;
    std::vector<Unit*> *army;
    std::vector<IntPair> cases;
    std::vector<int> depl;
    bool inMenu = false;
    bool inMove = false;
    bool isConfigured = false;

    Ui::MainWindow *ui;
    quint32 currentSize = 0;
    QTimer timer;
    int a = 5;
    unsigned int x = 21;
    unsigned int y = 17;

    QTcpServer* server = nullptr;
    QTcpSocket* other = nullptr;
    std::vector<int> posX;
    std::vector<int> posY;
    bool myTurn = false;

public:
    explicit MainWindow(QWidget *parent, Game* game);
    ~MainWindow();
    void createUnit(QMouseEvent *event);
    
private:
    void sendJson(QJsonObject obj);
    void music();
    int tDtoIsoX(int x, int y);
    int isoToTDX(int x, int y);
    int tDtoIsoY(int x, int y);
    int isoToTDY(int x, int y);
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent* event);
    void keyPressEvent(QKeyEvent *event);
    void showMove(Unit* unit);
    void showMenu(Building* b, Unit* u);
    QJsonObject unitMove(QMouseEvent *event);
    QJsonObject changeTurn();
    int getXIm(int ID);
    int getYIm(int ID);
    void moveUnit(Unit* unit, int x, int y, int MP);
<<<<<<< HEAD
    void createUnit(QMouseEvent *event);
    void actionOnUnit(QMouseEvent *event);
    
private:
    void sendJson(QJsonObject obj);
    void music();
    int tDtoIsoX(int x, int y);
    int isoToTDX(int x, int y);
    int tDtoIsoY(int x, int y);
    int isoToTDY(int x, int y);
=======
    void checkBlocked();
>>>>>>> 2c98750b6e5313cf8a63ea01e51c432a65a8d086
public slots:
    void tick();
    void onNewConnection();
    void onConnected();
    void onDisconnected();
    void onData();
    void move(QMouseEvent *event);
};

#endif // MAINWINDOW_H


