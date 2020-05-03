#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTableView>
#include <QFile>
#include <QTextStream>
#include <QStandardItemModel>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    QTable *table = new QTable( 100, 250, this );
//    table->setPixmap( 3, 2, pix );
//    table->setText( 3, 2, "A pixmap" );
//    QTableView::

    ui->radioButton->setChecked(true);

    QStandardItemModel *model = new QStandardItemModel();

    QFile file(":/files/files/test.csv");
    if (file.open(QFile::ReadOnly)) {

        int lineindex = 0;                     // file line counter
        QTextStream in(&file);                 // read to text stream

        while (!in.atEnd()) {

            // read one line from textstream(separated by "\n")
            QString fileLine = in.readLine();

            // parse the read line into separate pieces(tokens) with "," as the delimiter
            QStringList lineToken = fileLine.split(",", QString::SkipEmptyParts);

            // load parsed data to model accordingly
            for (int j = 0; j < lineToken.size(); j++) {
                QString value = lineToken.at(j);
                QStandardItem *item = new QStandardItem(value);
                model->setItem(lineindex, j, item);
            }

            lineindex++;
        }

        file.close();
    }
    else QMessageBox::critical(this,"Invalid","Not an invalid file!");
    ui->tableView->setModel(model);// It doesn't work
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->tableView->setSortingEnabled(true);
    if(ui->radioButton->isChecked())
        ui->tableView->sortByColumn(0,Qt::AscendingOrder);
    if(ui->radioButton_2->isChecked())
        ui->tableView->sortByColumn(0,Qt::DescendingOrder);
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->tableView->setSortingEnabled(true);
    if(ui->radioButton->isChecked())
        ui->tableView->sortByColumn(1,Qt::AscendingOrder);
    if(ui->radioButton_2->isChecked())
        ui->tableView->sortByColumn(1,Qt::DescendingOrder);
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->tableView->setSortingEnabled(true);
    if(ui->radioButton->isChecked())
        ui->tableView->sortByColumn(2,Qt::AscendingOrder);
    if(ui->radioButton_2->isChecked())
        ui->tableView->sortByColumn(2,Qt::DescendingOrder);
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->tableView->setSortingEnabled(true);
    if(ui->radioButton->isChecked())
        ui->tableView->sortByColumn(3,Qt::AscendingOrder);
    if(ui->radioButton_2->isChecked())
        ui->tableView->sortByColumn(3,Qt::DescendingOrder);
}
