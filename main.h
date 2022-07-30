#pragma once

#include <QtCore/QObject>
#include <QtQml/QQmlApplicationEngine>

class MyGlobal: public QObject
{
    Q_OBJECT

public:
    Q_INVOKABLE QString createDynamicText();
};
