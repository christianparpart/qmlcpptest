#include "main.h"

#include <QtGui/QGuiApplication>
#include <QtQml/QQmlApplicationEngine>
#include <QtQml/QQmlContext>

#include <cstdlib>

auto MyGlobal::createDynamicText() -> QString
{
    static int i = 0;
    auto result = QString("Hello Text, %1.").arg(i++);
    printf("createDynamicText called: \"%s\"\n", result.toStdString().c_str());
    return result;
}

auto main(int argc, char const* argv[]) -> int
{
    auto app = QGuiApplication(argc, (char**) argv);
    auto qmlEngine = QQmlApplicationEngine {};
    auto myGlobal = MyGlobal {};
    auto rootContext = qmlEngine.rootContext();

    auto createAndShowNewWindow = [&]() {
        printf("Creating window.\n");
        qmlEngine.load(QUrl("qrc:/qmlcpptest/main.qml"));
    };

    rootContext->setContextProperty("myGlobal", &myGlobal);

    for (int i = 0; i < 3; ++i)
        createAndShowNewWindow();

    app.exec();

    return EXIT_SUCCESS;
}
