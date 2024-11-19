#include <QApplication>
#include "TheWordWhispererUI.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    TheWordWhispererUI window;
    window.show();

    return app.exec();
}
