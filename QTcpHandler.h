#ifndef QTCPHANDLER_H
#define QTCPHANDLER_H


#include <QtNetwork/QTcpSocket>
#include <QThread>
#include <QFile>

#include <vector>
#include <string>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

using namespace std;


class QTcpHandler: public QObject{
    Q_OBJECT

public:
    QTcpHandler(std::shared_ptr<QTcpSocket> sock);


private:


    std::shared_ptr<QTcpSocket> socket;

    bool connect(const QString &addr, const int &port);

    //helper functions
    bool contains(std::string str, std::string val);
    bool pong(string& msg);
    vector<std::string> msg_split(std::string str);
    void fileLog(const QString &data);
    QString parser(const QString &data);

public slots:
    void read();
    void send(const QString &message);
    QTcpSocket *socket;

signals:
    void dataReady(const QString &data);
    void connectedToServer();

};

#endif // QTCPHANDLER_H
