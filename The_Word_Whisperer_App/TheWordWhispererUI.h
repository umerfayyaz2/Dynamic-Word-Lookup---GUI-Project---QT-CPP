#ifndef THEWORDWHISPERERUI_H
#define THEWORDWHISPERERUI_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QListWidget>
#include <QVBoxLayout>
#include <QLabel>

class TheWordWhispererUI : public QMainWindow {
    Q_OBJECT

public:
    explicit TheWordWhispererUI(QWidget *parent = nullptr);
    ~TheWordWhispererUI();

private:
    QLabel *titleLabel;
    QLineEdit *searchBar;
    QListWidget *dropdownMenu;
    QPushButton *whisperButton;
};

#endif // THEWORDWHISPERERUI_H
