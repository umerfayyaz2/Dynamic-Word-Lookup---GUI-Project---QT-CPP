#include "TheWordWhispererUI.h"
#include <QVBoxLayout>
#include <QDebug>

TheWordWhispererUI::TheWordWhispererUI(QWidget *parent)
    : QMainWindow(parent) {
    // Central Widget
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    // Layout
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    // Title Label
    titleLabel = new QLabel("The Word Whisperer", this);
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setStyleSheet("font-size: 36px; font-weight: bold; color: #EEEEEE;");
    layout->addWidget(titleLabel);

    // Search Bar
    searchBar = new QLineEdit(this);
    searchBar->setPlaceholderText("Type your query...");
    searchBar->setStyleSheet(R"(
        QLineEdit {
            background-color: #D4BEE4;
            border: 2px solid #9B7EBD;
            border-radius: 10px;
            padding: 10px;
            font-size: 16px;
            color: #3B1E54;
        }
        QLineEdit:hover {
            border-color: #EEEEEE;
            box-shadow: 0px 4px 8px rgba(0, 0, 0, 0.2);
        }
    )");
    layout->addWidget(searchBar);

    // Dropdown Menu
    dropdownMenu = new QListWidget(this);
    dropdownMenu->setStyleSheet(R"(
        QListWidget {
            background-color: #D4BEE4;
            border: 1px solid #9B7EBD;
            border-radius: 10px;
            font-size: 16px;
            color: #3B1E54;
        }
        QListWidget::item:hover {
            background-color: #EEEEEE;
            transform: scale(1.02);
        }
    )");
    layout->addWidget(dropdownMenu);

    // Whisper Button
    whisperButton = new QPushButton("Whisper", this);
    whisperButton->setStyleSheet(R"(
        QPushButton {
            background-color: #9B7EBD;
            color: #EEEEEE;
            font-size: 18px;
            border-radius: 12px;
            padding: 10px;
        }
        QPushButton:hover {
            background-color: #D4BEE4;
            transform: scale(1.05);
            box-shadow: 0px 6px 12px rgba(0, 0, 0, 0.25);
        }
    )");
    layout->addWidget(whisperButton);

    // Connect Search Bar and Button Events
    connect(searchBar, &QLineEdit::textChanged, this, [=](const QString &text) {
        dropdownMenu->clear();
        if (!text.isEmpty()) {
            dropdownMenu->addItem(text + "apple");
            dropdownMenu->addItem(text + "application");
            dropdownMenu->addItem(text + "algorithm");
        }
    });

    connect(whisperButton, &QPushButton::clicked, this, [=]() {
        qDebug() << "Query Submitted:" << searchBar->text();
    });

    // Set Window Properties
    setWindowTitle("The Word Whisperer");
    setStyleSheet("background-color: #3B1E54;");
    resize(600, 400);
}

TheWordWhispererUI::~TheWordWhispererUI() {
    // Cleanup if needed
}
