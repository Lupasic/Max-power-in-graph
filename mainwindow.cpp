#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "Ellips.h"
#include "reshenie.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    // QKeyEvent *event;
    QRegExp exp("[-]{0,1}[0-9]{1,}[.]{0,1}[0-9]{0,2}");
    QRegExp exp1("[1-9]{1,}[.]{0,1}[0-9]{0,}");
    ui->XEdit->setValidator(new QRegExpValidator(exp,this));
    ui->YEdit->setValidator(new QRegExpValidator(exp,this));
    ui->HeightEdit->setValidator(new QRegExpValidator(exp1,this));
    ui->WidthEdit->setValidator(new QRegExpValidator(exp1,this));


    connect(ui->XEdit,SIGNAL(textChanged(QString)),this,SLOT(on_lineEdit_textChanged()));
    connect(ui->YEdit,SIGNAL(textChanged(QString)),this,SLOT(on_lineEdit_textChanged()));
    connect(ui->HeightEdit,SIGNAL(textChanged(QString)),this,SLOT(on_lineEdit_textChanged()));
    connect(ui->WidthEdit,SIGNAL(textChanged(QString)),this,SLOT(on_lineEdit_textChanged()));
    connect(ui->ellipsView, SIGNAL(sgFromEllips(Ellips)),this,SLOT(on_EllipsView_ellipsChanged(Ellips)));
    connect(ui->EllipsTable, SIGNAL(cellClicked(int,int)),ui->ellipsView, SLOT(EllipsLook(int)));
    connect(ui->ellipsView, SIGNAL(delfromEllips(int)),this,SLOT(on_del_from_EllipsTable(int)));
    connect(ui->EllipsTable, SIGNAL(cellClicked(int,int)),this,SLOT(on_del_from_EllipsView(int)));
    connect(ui->ellipsView, SIGNAL(sendrow(int)),ui->EllipsTable, SLOT(selectRow(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent* event)
{
   key = event->key();
}

void MainWindow::on_del_from_EllipsTable(int roww)
{
    ui->EllipsTable->removeRow(roww-1);
}

void MainWindow::on_del_from_EllipsView(int roww)
{
    if(key == Qt::Key_Delete)
    {
        ui->EllipsTable->removeRow(roww);
      std::vector<Ellips>::iterator it= ui->ellipsView->lp.begin();
      it += roww;
      ui->ellipsView->lp.erase(it);
      ui->ellipsView->setRow(-1);
        update();
        key=0;
    }
}

void MainWindow::on_AddButton_clicked(bool checked)
{
    double datamas[5];
    if (checked==false)
    {
        QString strr;
        QTableWidgetItem* item = new QTableWidgetItem;


    ui->EllipsTable->setRowCount(ui->EllipsTable->rowCount()+1);


        datamas[0] = ui->EllipsTable->rowCount();


        item = new QTableWidgetItem();
        strr = ui->XEdit->text();
        datamas[1] = strr.toDouble();
        item->setText(strr);
        item->setTextAlignment(Qt::AlignCenter);
        ui->EllipsTable->setItem(ui->EllipsTable->rowCount()-1, 0, item);

        item = new QTableWidgetItem();
        strr = ui->YEdit->text();
        datamas[2] = strr.toDouble();
        item->setText(strr);
        item->setTextAlignment(Qt::AlignCenter);
        ui->EllipsTable->setItem(ui->EllipsTable->rowCount()-1, 1, item);

        item = new QTableWidgetItem();
        strr = ui->WidthEdit->text();
        datamas[3] = strr.toDouble();
        item->setText(strr);
        item->setTextAlignment(Qt::AlignCenter);
        ui->EllipsTable->setItem(ui->EllipsTable->rowCount()-1, 2, item);

        item = new QTableWidgetItem();
        strr = ui->HeightEdit->text();
        datamas[4] = strr.toDouble();
        item->setText(strr);
        item->setTextAlignment(Qt::AlignCenter);
        ui->EllipsTable->setItem(ui->EllipsTable->rowCount()-1, 3, item);
        Ellips *d = new Ellips((int)datamas[0],datamas[1],datamas[2],datamas[3],datamas[4]);

        ui->ellipsView->slotB(d);
          }

}

void MainWindow::on_RallButton_clicked()
{

ui->ComputationButton->setEnabled(true);
ui->ellipsView->lp.clear();
ui->ellipsView->clearall();
ui->EllipsTable->clearContents();
ui->EllipsTable->setRowCount(0);
ui->ResetButton->click();
ui->PowerView->clear();
ui->graphView->SlotDelete();


}

void MainWindow::on_EllipsView_ellipsChanged(Ellips data)
{
 QString strr;
 QTableWidgetItem* item = new QTableWidgetItem;


ui->EllipsTable->setRowCount(ui->EllipsTable->rowCount()+1);



 item = new QTableWidgetItem();
 strr = QString::number(data.getX());
 item->setText(strr);
 item->setTextAlignment(Qt::AlignCenter);
 ui->EllipsTable->setItem(ui->EllipsTable->rowCount()-1, 0, item);

 item = new QTableWidgetItem();
 strr = QString::number(data.getY());
 item->setText(strr);
 item->setTextAlignment(Qt::AlignCenter);
 ui->EllipsTable->setItem(ui->EllipsTable->rowCount()-1, 1, item);

 item = new QTableWidgetItem();
 strr = QString::number(data.getA());
 item->setText(strr);
 item->setTextAlignment(Qt::AlignCenter);
 ui->EllipsTable->setItem(ui->EllipsTable->rowCount()-1, 2, item);

 item = new QTableWidgetItem();
 strr = QString::number(data.getB());
 item->setText(strr);
 item->setTextAlignment(Qt::AlignCenter);
 ui->EllipsTable->setItem(ui->EllipsTable->rowCount()-1, 3, item);

}


void MainWindow::on_ComputationButton_clicked(bool checked)
{
    if (checked == false)
    {
         Reshenie *p = new Reshenie(ui->ellipsView->lp);

         ui->graphView->slotB(p->graph_nodes,p->max_independent);
         ui->ellipsView->slotRaskras(p->max_independent);


        // Вывод ответа
        int i;
        for(i=0; i< p->text.size(); i++)
        {
        ui->PowerView->append(p->text[i]);
        }
     //ui->ComputationButton->setEnabled(false);
    p->ClearGraph();
    delete p;
    }
}

void MainWindow::on_lineEdit_textChanged()
{
    if(ui->XEdit->hasAcceptableInput() && ui->YEdit->hasAcceptableInput() && ui->HeightEdit->hasAcceptableInput() && ui->WidthEdit->hasAcceptableInput())
        ui->AddButton->setEnabled(true);
    else
          ui->AddButton->setEnabled(false);
}
