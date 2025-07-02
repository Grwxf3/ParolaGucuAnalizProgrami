#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QLineEdit;
class QLabel;
class QProgressBar;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onPasswordChanged(const QString &password);

private:
    void setupUI();
    QString formatTime(double seconds);

    QLineEdit *passwordInput;
    QLabel *strengthLabel;
    QProgressBar *strengthBar;
    QLabel *timeLabel;
};

#endif // MAINWINDOW_H