#include "calculator.h"
#include "ui_calculator.h"
#include <string>
#include <sstream>
#include <vector>

using namespace std;

//Every number and operand is serperated by commas in the QString
QString eq;

//Holds the equation in a more usable form
QStringList equation;


Calculator::Calculator(QWidget *parent) :
    QMainWindow(parent),

    ui(new Ui::Calculator)
{


    ui->setupUi(this);
}

Calculator::~Calculator()
{
    delete ui;
}


void Calculator::on_negative_Button_clicked()
{
    //UI updates the display to show the users current input
    ui->textEdit->insertPlainText("-");
    QString s = ui->textEdit->toPlainText();
    //eq adds a 6
    eq += "-";

}

void Calculator::on_ONE_Button_clicked()
{
    //UI updates the display to show the users current input
    ui->textEdit->insertPlainText("1");
    QString s = ui->textEdit->toPlainText();

    //eq adds a one
    eq += "1";

}


void Calculator::on_TWO_Button_clicked()
{
    //UI updates the display to show the users current input
    ui->textEdit->insertPlainText("2");
    QString s = ui->textEdit->toPlainText();
    //eq adds a 2
    eq += "2";

}

void Calculator::on_THREE_Button_clicked()
{
    //UI updates the display to show the users current input
    ui->textEdit->insertPlainText("3");
    QString s = ui->textEdit->toPlainText();
    //eq adds a 3
    eq += "3";
}

void Calculator::on_FOUR_Button_clicked()
{
    //UI updates the display to show the users current input
    ui->textEdit->insertPlainText("4");
    QString s = ui->textEdit->toPlainText();
    //eq adds a 4
    eq += "4";
}

void Calculator::on_FIVE_Button_clicked()
{
   //UI updates the display to show the users current input
    ui->textEdit->insertPlainText("5");
    QString s = ui->textEdit->toPlainText();
    //eq adds a 5
    eq += "5";
}

void Calculator::on_SIX_Button_clicked()
{
    //UI updates the display to show the users current input
    ui->textEdit->insertPlainText("6");
    QString s = ui->textEdit->toPlainText();
    //eq adds a 6
    eq += "6";
}

void Calculator::on_SEVEN_Button_clicked()
{
    ui->textEdit->insertPlainText("7");
    QString s = ui->textEdit->toPlainText();
     eq += "7";
}

void Calculator::on_EIGHT_Button_clicked()
{
    //UI updates the display to show the users current input
    ui->textEdit->insertPlainText("8");
    QString s = ui->textEdit->toPlainText();
    //eq adds a 8
     eq += "8";
}

void Calculator::on_NINE_Button_clicked()
{
    ui->textEdit->insertPlainText("9");
    QString s = ui->textEdit->toPlainText();
    eq += "9";
}

void Calculator::on_ZERO_Button_clicked()
{
    //UI updates the display to show the users current input
    ui->textEdit->insertPlainText("0");
    QString s = ui->textEdit->toPlainText();
    //eq adds a 0
    eq += "0";
}

void Calculator::on_CLEAR_Button_clicked()
{
    ui->textEdit->clear();
    QString s = ui->textEdit->toPlainText();
    eq.clear();
    s.clear();
    equation.clear();


}

void Calculator::on_DIVIDE_Button_clicked()
{
    //UI updates the display to show the users current input
    ui->textEdit->insertPlainText("/");
    QString s = ui->textEdit->toPlainText();
    //We add comma, operand, comma to eq to indicate a new term to follow
   eq+=",/,";


}

void Calculator::on_MULTIPLY_Button_clicked()
{
    //UI updates the display to show the users current input
    ui->textEdit->insertPlainText("*");
    QString s = ui->textEdit->toPlainText();
    //We add comma, operand, comma to eq to indicate a new term to follow
   eq+=",*,";

}

void Calculator::on_MINUS_Button_clicked()
{
    //UI updates the display to show the users current input
    ui->textEdit->insertPlainText("-");
    QString s = ui->textEdit->toPlainText();
    //We add comma, operand, comma to eq to indicate a new term to follow
   eq+=",N,";

}

void Calculator::on_ADDITION_Button_clicked()
{
    //UI updates the display to show the users current input
    ui->textEdit->insertPlainText("+");
    QString s = ui->textEdit->toPlainText();
    //We add comma, operand, comma to eq to indicate a new term to follow
    eq+=",+,";

}


void Calculator::on_DECIMAL_Button_clicked()
{
    //UI updates the display to show the users current input
    ui->textEdit->insertPlainText(".");
    QString s = ui->textEdit->toPlainText();
    //eq adds a decimal
    eq += ".";

}


//Complete 1-operation on two QStrings that represent numbers based on the operand op
QString Calculator::solve(QString a, QString b, QChar op){

    double one;
    double two;

    try{
         one = a.toDouble();
         two = b.toDouble();
    }
    catch(exception e){
        throw(e);
    }



    try {
        if(op == '-'){
            return QString::number(one-two);

        }
        else if(op =='+'){
            return QString::number(one+two);
        }
        else if(op =='*'){
            return QString::number(one*two);
        }
        else if(op=='/'){
            return QString::number(one/two);
        }


    } catch (exception e) {

        throw(e);

    }


    //We will never reach here

}

//returns if the string is an operand
bool Calculator::isOp(QString s){
    if(s == "N"){
        return true;
    }
    if(s=="+"){
        return true;
    }
    if(s=="/"){
        return true;

    }
    if(s=="*"){
        return true;
    }

    return false;



}

void Calculator::on_EQUAL_Button_clicked()
{
    //Bollean Failure keeps track on the validity of the equation entered
    //We assume the user entered a perfect equation at first but then check it for errors
    bool failure = false;
    ui->textEdit->clear();

    qApp->processEvents();
    _sleep(50);

    equation = eq.split(',' );
    equation.removeAll(QString(""));


    //The user hit equals without typing anything
    QString s = ui->textEdit->toPlainText();
    ui->textEdit->clear();
    ui->textEdit->insertPlainText(s);

    //Check if the equation is valid
    // 1:An equation can not start with an operand

    if(equation.at(0) == "N"){
        failure = true;
    }


    if(equation.at(0) == "*"){
            failure = true;
    }
    if(equation.at(0) == "/"){
            failure = true;
    }
    if(equation.at(0) == "+"){
            failure = true;
    }


    // 2:An equation can not end with an operand

    if(isOp(equation.at(equation.size()-1))){
        failure = true;
    }



    int i =0;
   // 3: Check for two or more operators in a row

    while(i< equation.size()){
        //Checks for 2+ ops
        if(isOp(equation.at(i))){
            if((i+1 < equation.size() ) && isOp(equation.at(i+1))){
                failure = true;
            }
        }

        if(equation.at(i).count(".")>1){

               failure = true;
         }

        if((equation.at(i).count("-") >1 ) || ((equation.at(i).at(0) != "-") && equation.at(i).contains("-")) ){

      failure = true;
    }
  i++;
}


    //The equations operators are valid now
    //From this point forward we may assume the operations are correct

   //The result
   double result;



   //We have to go thru the equation left to right and add based on Order of Ops

if(failure == false){
  i=0;
  while (i<equation.size()){
      if(equation.at(i) == "*"){

        //multiply the two numbers and replace the result in the opperands spot
         equation.replace(i,(solve(equation.at(i-1), equation.at(i+1), '*')));
         equation.removeAt(i-1);
         equation.removeAt(i);

         i--;

      }
      else if (equation.at(i) == "/"){
          equation.replace(i,(solve(equation.at(i-1), equation.at(i+1), '/')));
          equation.removeAt(i-1);
          equation.removeAt(i);
          i--;

      }
      i++;
}


i=0;
//Now we solve the remaining subtraction and additions
  while (i < equation.size()){


      if(equation.at(i) == "+"){

        //add the two numbers and replace the result in the opperands spot
         equation.replace(i,(solve(equation.at(i-1), equation.at(i+1), '+')));
         equation.removeAt(i-1);
         equation.removeAt(i);
         i--;

      }
      else if (equation.at(i) == "N"){
          equation.replace(i,(solve(equation.at(i-1), equation.at(i+1), '-')));
          equation.removeAt(i-1);
          equation.removeAt(i);
          i--;

      }

      i++;

  }



    result = equation.at(0).toDouble();
}

    if(failure == true){
        ui->textEdit->clear();
        ui->textEdit->insertPlainText("ERROR");
        s.clear();
        equation.clear();
        eq.clear();


    }
    else{
        //Display the results to the screen
        QString answer = QString::number(result);
        ui->textEdit->clear();
        ui->textEdit->insertPlainText(answer);
        eq = equation.at(0);
        equation.clear();

    }


 }





