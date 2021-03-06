
#ifndef UTILITY_H
#define UTILITY_H

#include <QObject>
#include <QDebug>
#include <QStringList>
#include <QByteArray>
#include <QString>
#include <QDeclarativeComponent>
#include <QDeclarativeEngine>
#include <QDeclarativeItem>
#include <QPointer>
#include <QDeclarativeContext>

class Utility : public QObject
{
    Q_PROPERTY(QString productName READ productName)
    Q_PROPERTY(QString appVersion READ appVersion)
    Q_PROPERTY(QString sysName READ sysName)

    Q_OBJECT
public:
    explicit Utility(QString appVersion, QObject *parent = 0);

    Q_INVOKABLE QByteArray base64Encode(QByteArray in);
    Q_INVOKABLE QByteArray base64Decode(QByteArray in);
    Q_INVOKABLE QString strToASCII(QString in);//
    Q_INVOKABLE void console(QString in);

    int strToInt( QChar in );

private:
#if defined(Q_OS_SYMBIAN)||defined(HARMATTAN_BOOSTER)||defined(Q_WS_SIMULATOR)
    QPointer<QDeclarativeComponent> component;//
    QPointer<QDeclarativeEngine> engine;///////
    QPointer<QDeclarativeItem> item;
#endif

private:
   QString m_productName;
   QString productName();

   QString m_appVersion;
   QString appVersion();

   QString sysName();
};

#endif // UTILITY_H
