//
//  CTableView.cpp
//  XMLEditor
//
//  Created by Jourdan West on 10/20/14.
//
//

#include "CTableView.h"
#include <QHeaderView>

CTableView::CTableView(QWidget *parent) : QTableView(parent)
{
    setAlternatingRowColors(true);
    verticalHeader()->QWidget::setVisible(false);
}
