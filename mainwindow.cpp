#include "mainwindow.h"
#include <QLineEdit>
#include <QLabel>
#include <QProgressBar>
#include <QVBoxLayout>
#include <QWidget>
#include <QRegularExpression>
#include <cmath>
#include <sstream>
#include <iomanip>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupUI();
    connect(passwordInput, &QLineEdit::textChanged, this, &MainWindow::onPasswordChanged);
}

MainWindow::~MainWindow()
{
}

void MainWindow::setupUI()
{
    setWindowTitle("Parola Gücü Analiz Aracı");
    setFixedSize(400, 200);

    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);

    QLabel *inputLabel = new QLabel("Lütfen parolanızı girin:", this);
    passwordInput = new QLineEdit(this);
    passwordInput->setEchoMode(QLineEdit::Password);

    strengthBar = new QProgressBar(this);
    strengthBar->setRange(0, 100);
    strengthBar->setValue(0);
    strengthBar->setTextVisible(false);

    strengthLabel = new QLabel("Parola gücü: ", this);
    timeLabel = new QLabel("Tahmini kırılma süresi: ", this);

    mainLayout->addWidget(inputLabel);
    mainLayout->addWidget(passwordInput);
    mainLayout->addWidget(strengthBar);
    mainLayout->addWidget(strengthLabel);
    mainLayout->addWidget(timeLabel);
    mainLayout->addStretch();

    setCentralWidget(centralWidget);
}

void MainWindow::onPasswordChanged(const QString &password)
{
    int length = password.length();
    if (length == 0) {
        strengthBar->setValue(0);
        strengthLabel->setText("Parola gücü: Lütfen bir parola girin.");
        timeLabel->setText("Tahmini kırılma süresi: ");
        strengthLabel->setStyleSheet("");
        return;
    }

    int score = 0;
    int characterPool = 0;

    score += qMin(length * 4, 40);

    if (password.contains(QRegularExpression("[a-z]"))) {
        score += 10;
        characterPool += 26;
    }
    if (password.contains(QRegularExpression("[A-Z]"))) {
        score += 15;
        characterPool += 26;
    }
    if (password.contains(QRegularExpression("[0-9]"))) {
        score += 15;
        characterPool += 10;
    }
    if (password.contains(QRegularExpression("[^a-zA-Z0-9]"))) {
        score += 20;
        characterPool += 32;
    }

    score = qMin(score, 100);
    strengthBar->setValue(score);

    if (score < 40) {
        strengthLabel->setText("Parola gücü: Çok Zayıf");
        strengthLabel->setStyleSheet("color: red;");
    } else if (score < 60) {
        strengthLabel->setText("Parola gücü: Zayıf");
        strengthLabel->setStyleSheet("color: orange;");
    } else if (score < 80) {
        strengthLabel->setText("Parola gücü: Orta");
        strengthLabel->setStyleSheet("color: blue;");
    } else {
        strengthLabel->setText("Parola gücü: Güçlü");
        strengthLabel->setStyleSheet("color: green;");
    }

    if (characterPool > 0 && length > 0) {
        double combinations = pow((double)characterPool, (double)length);
        double secondsToCrack = combinations / 10'000'000'000.0;
        timeLabel->setText("Tahmini kırılma süresi: " + formatTime(secondsToCrack));
    } else {
        timeLabel->setText("Tahmini kırılma süresi: Hesaplanamıyor");
    }
}

QString MainWindow::formatTime(double seconds)
{
    if (seconds < 1.0) return "Anında";
    if (seconds < 60) return QString::number(qRound(seconds)) + " saniye";
    
    double minutes = seconds / 60.0;
    if (minutes < 60) return QString::number(qRound(minutes)) + " dakika";

    double hours = minutes / 60.0;
    if (hours < 24) return QString::number(qRound(hours)) + " saat";

    double days = hours / 24.0;
    if (days < 365) return QString::number(qRound(days)) + " gün";

    double years = days / 365.0;
    if (years < 1000) return QString::number(qRound(years)) + " yıl";
    
    if (years < 1000000) return QString::number(qRound(years / 1000.0)) + " bin yıl";
    
    return "Milyonlarca yıl";
}