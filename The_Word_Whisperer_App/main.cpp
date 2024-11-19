#include <QApplication>
#include "TheWordWhispererUI.h"
#include <QFile>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Load the stylesheet
    QFile file(":/styles.qss");
    if (file.open(QFile::ReadOnly)) {
        QString stylesheet = QLatin1String(file.readAll());
        app.setStyleSheet(stylesheet);
    } else {
        qWarning("Could not open styles.qss file!");
    }

    TheWordWhispererUI window;
    window.show();

    return app.exec();
}
