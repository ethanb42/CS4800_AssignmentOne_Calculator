#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>


namespace Ui {
class Calculator;
}

class Calculator : public QMainWindow
{
    Q_OBJECT

public:

    explicit Calculator(QWidget *parent = nullptr);
    ~Calculator();


private slots:

    bool isOp(QString s);

    void on_ONE_Button_clicked();

    void on_TWO_Button_clicked();

    void on_THREE_Button_clicked();

    void on_FOUR_Button_clicked();

    void on_FIVE_Button_clicked();

    void on_SIX_Button_clicked();

    void on_SEVEN_Button_clicked();

    void on_EIGHT_Button_clicked();

    void on_NINE_Button_clicked();

    void on_MINUS_Button_clicked();

    void on_ZERO_Button_clicked();

    void on_CLEAR_Button_clicked();

    void on_DIVIDE_Button_clicked();

    void on_MULTIPLY_Button_clicked();

    void on_ADDITION_Button_clicked();

    void on_EQUAL_Button_clicked();

    void on_DECIMAL_Button_clicked();

    QString solve(QString a, QString b, QChar op);

    void on_negative_Button_clicked();

private:
    Ui::Calculator *ui;
};

#endif // CALCULATOR_H
