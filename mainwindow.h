#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "Ellips.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    void keyPressEvent(QKeyEvent* event);
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void delfromTable(int row);

private slots:
    void on_AddButton_clicked(bool checked); //при нажатии кнопки - добавление в таблицу

    void on_RallButton_clicked(); // при нажатии кнопки - удаление всей системы

    void on_ComputationButton_clicked(bool checked); // при нажатии кнопки - расчет системы

    void on_lineEdit_textChanged(); // при заполнении всего текста - активирование кнопки

    void on_EllipsView_ellipsChanged(Ellips data); //при рисовании эллипса занесение его в таблицу

    void on_del_from_EllipsTable(int roww); // удаление строки из таблицы

    void on_del_from_EllipsView(int roww); // удаление строки из таблицы

private:
    Ui::MainWindow *ui;
    int key;
};

#endif // MAINWINDOW_H
