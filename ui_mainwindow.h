/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "ellipsview.h"
#include "graphview.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *VvodLabel;
    EllipsView *ellipsView;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *GraphLabel;
    GraphView *graphView;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *PowerLabel;
    QTextEdit *PowerView;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *RallButton;
    QPushButton *ComputationButton;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_6;
    QLabel *Emptylabel;
    QLabel *CenterLabel;
    QLabel *WidthLabel;
    QLabel *HeightLabel;
    QVBoxLayout *verticalLayout_5;
    QGridLayout *gridLayout;
    QLineEdit *YEdit;
    QLabel *XLabel;
    QLabel *YLabel;
    QLineEdit *XEdit;
    QLineEdit *WidthEdit;
    QLineEdit *HeightEdit;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *ResetButton;
    QPushButton *AddButton;
    QTableWidget *EllipsTable;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1039, 675);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(30, 20, 632, 455));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        VvodLabel = new QLabel(verticalLayoutWidget);
        VvodLabel->setObjectName(QStringLiteral("VvodLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(VvodLabel->sizePolicy().hasHeightForWidth());
        VvodLabel->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(VvodLabel, 0, Qt::AlignHCenter);

        ellipsView = new EllipsView(verticalLayoutWidget);
        ellipsView->setObjectName(QStringLiteral("ellipsView"));
        ellipsView->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(ellipsView->sizePolicy().hasHeightForWidth());
        ellipsView->setSizePolicy(sizePolicy1);
        ellipsView->setMinimumSize(QSize(630, 430));
        ellipsView->setMouseTracking(false);

        verticalLayout->addWidget(ellipsView);

        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(690, 20, 321, 281));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        GraphLabel = new QLabel(verticalLayoutWidget_2);
        GraphLabel->setObjectName(QStringLiteral("GraphLabel"));
        sizePolicy.setHeightForWidth(GraphLabel->sizePolicy().hasHeightForWidth());
        GraphLabel->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(GraphLabel, 0, Qt::AlignHCenter);

        graphView = new GraphView(verticalLayoutWidget_2);
        graphView->setObjectName(QStringLiteral("graphView"));

        verticalLayout_2->addWidget(graphView);

        verticalLayoutWidget_3 = new QWidget(centralwidget);
        verticalLayoutWidget_3->setObjectName(QStringLiteral("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(690, 320, 321, 241));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        PowerLabel = new QLabel(verticalLayoutWidget_3);
        PowerLabel->setObjectName(QStringLiteral("PowerLabel"));
        sizePolicy.setHeightForWidth(PowerLabel->sizePolicy().hasHeightForWidth());
        PowerLabel->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(PowerLabel, 0, Qt::AlignHCenter);

        PowerView = new QTextEdit(verticalLayoutWidget_3);
        PowerView->setObjectName(QStringLiteral("PowerView"));

        verticalLayout_3->addWidget(PowerView);

        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(750, 600, 201, 29));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        RallButton = new QPushButton(horizontalLayoutWidget);
        RallButton->setObjectName(QStringLiteral("RallButton"));

        horizontalLayout->addWidget(RallButton);

        ComputationButton = new QPushButton(horizontalLayoutWidget);
        ComputationButton->setObjectName(QStringLiteral("ComputationButton"));
        ComputationButton->setAutoDefault(false);
        ComputationButton->setDefault(false);

        horizontalLayout->addWidget(ComputationButton);

        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 490, 301, 159));
        verticalLayout_7 = new QVBoxLayout(layoutWidget);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(-1, 0, -1, -1);
        Emptylabel = new QLabel(layoutWidget);
        Emptylabel->setObjectName(QStringLiteral("Emptylabel"));

        verticalLayout_6->addWidget(Emptylabel);

        CenterLabel = new QLabel(layoutWidget);
        CenterLabel->setObjectName(QStringLiteral("CenterLabel"));

        verticalLayout_6->addWidget(CenterLabel);

        WidthLabel = new QLabel(layoutWidget);
        WidthLabel->setObjectName(QStringLiteral("WidthLabel"));

        verticalLayout_6->addWidget(WidthLabel);

        HeightLabel = new QLabel(layoutWidget);
        HeightLabel->setObjectName(QStringLiteral("HeightLabel"));

        verticalLayout_6->addWidget(HeightLabel);


        horizontalLayout_5->addLayout(verticalLayout_6);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        YEdit = new QLineEdit(layoutWidget);
        YEdit->setObjectName(QStringLiteral("YEdit"));

        gridLayout->addWidget(YEdit, 1, 1, 1, 1);

        XLabel = new QLabel(layoutWidget);
        XLabel->setObjectName(QStringLiteral("XLabel"));

        gridLayout->addWidget(XLabel, 0, 0, 1, 1, Qt::AlignHCenter);

        YLabel = new QLabel(layoutWidget);
        YLabel->setObjectName(QStringLiteral("YLabel"));

        gridLayout->addWidget(YLabel, 0, 1, 1, 1, Qt::AlignHCenter);

        XEdit = new QLineEdit(layoutWidget);
        XEdit->setObjectName(QStringLiteral("XEdit"));
        XEdit->setInputMethodHints(Qt::ImhNone);

        gridLayout->addWidget(XEdit, 1, 0, 1, 1);


        verticalLayout_5->addLayout(gridLayout);

        WidthEdit = new QLineEdit(layoutWidget);
        WidthEdit->setObjectName(QStringLiteral("WidthEdit"));

        verticalLayout_5->addWidget(WidthEdit);

        HeightEdit = new QLineEdit(layoutWidget);
        HeightEdit->setObjectName(QStringLiteral("HeightEdit"));

        verticalLayout_5->addWidget(HeightEdit);


        horizontalLayout_5->addLayout(verticalLayout_5);


        verticalLayout_7->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        ResetButton = new QPushButton(layoutWidget);
        ResetButton->setObjectName(QStringLiteral("ResetButton"));

        horizontalLayout_4->addWidget(ResetButton);

        AddButton = new QPushButton(layoutWidget);
        AddButton->setObjectName(QStringLiteral("AddButton"));
        AddButton->setEnabled(false);

        horizontalLayout_4->addWidget(AddButton);


        verticalLayout_7->addLayout(horizontalLayout_4);

        EllipsTable = new QTableWidget(centralwidget);
        if (EllipsTable->columnCount() < 4)
            EllipsTable->setColumnCount(4);
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font);
        EllipsTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font);
        EllipsTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font);
        EllipsTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font);
        EllipsTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        EllipsTable->setObjectName(QStringLiteral("EllipsTable"));
        EllipsTable->setGeometry(QRect(340, 490, 321, 161));
        EllipsTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        EllipsTable->horizontalHeader()->setDefaultSectionSize(76);
        MainWindow->setCentralWidget(centralwidget);
        QWidget::setTabOrder(XEdit, YEdit);
        QWidget::setTabOrder(YEdit, WidthEdit);
        QWidget::setTabOrder(WidthEdit, HeightEdit);
        QWidget::setTabOrder(HeightEdit, AddButton);
        QWidget::setTabOrder(AddButton, ResetButton);
        QWidget::setTabOrder(ResetButton, PowerView);
        QWidget::setTabOrder(PowerView, EllipsTable);

        retranslateUi(MainWindow);
        QObject::connect(ResetButton, SIGNAL(clicked()), XEdit, SLOT(clear()));
        QObject::connect(ResetButton, SIGNAL(clicked()), WidthEdit, SLOT(clear()));
        QObject::connect(ResetButton, SIGNAL(clicked()), HeightEdit, SLOT(clear()));
        QObject::connect(ResetButton, SIGNAL(clicked()), YEdit, SLOT(clear()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        VvodLabel->setText(QApplication::translate("MainWindow", "\320\222\320\262\320\276\320\264 \320\264\320\260\320\275\320\275\321\213\321\205", 0));
        GraphLabel->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\262\320\276\320\264 \320\263\321\200\320\260\321\204\320\260", 0));
        PowerLabel->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\262\320\276\320\264 \320\274\320\276\321\211\320\275\320\276\321\201\321\202\320\270", 0));
        RallButton->setText(QApplication::translate("MainWindow", "Reset All", 0));
        ComputationButton->setText(QApplication::translate("MainWindow", "Computation", 0));
        Emptylabel->setText(QString());
        CenterLabel->setText(QApplication::translate("MainWindow", "\320\246\320\265\320\275\321\202\321\200", 0));
        WidthLabel->setText(QApplication::translate("MainWindow", "\320\250\320\270\321\200\320\270\320\275\320\260", 0));
        HeightLabel->setText(QApplication::translate("MainWindow", "\320\222\321\213\321\201\320\276\321\202\320\260", 0));
        XLabel->setText(QApplication::translate("MainWindow", "x", 0));
        YLabel->setText(QApplication::translate("MainWindow", "y", 0));
        ResetButton->setText(QApplication::translate("MainWindow", "Reset", 0));
        AddButton->setText(QApplication::translate("MainWindow", "&Add", 0));
        QTableWidgetItem *___qtablewidgetitem = EllipsTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "X", 0));
        QTableWidgetItem *___qtablewidgetitem1 = EllipsTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Y", 0));
        QTableWidgetItem *___qtablewidgetitem2 = EllipsTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Height", 0));
        QTableWidgetItem *___qtablewidgetitem3 = EllipsTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Widht", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
