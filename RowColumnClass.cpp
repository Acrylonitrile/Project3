#include"RowColumnClass.h"
#include"constants.h"
#include<iostream>


RowColumnClass::RowColumnClass():rowIndex(INITIAL_ROW_VALUE),
                                 colIndex(INITIAL_COL_VALUE)
{ ; }

RowColumnClass::RowColumnClass(const int inRow, const int inCol):
                               rowIndex(inRow),colIndex(inCol)
{ ; }

void RowColumnClass::setRowCol(const int inRow, const int inCol)
{
    rowIndex = inRow;
    colIndex = inCol;
}

void RowColumnClass::setRow(const int inRow)
{
    rowIndex = inRow;
}

void RowColumnClass::setCol(const int inCol)
{
    colIndex = inCol;
}

void RowColumnClass::addRowColTo(const RowColumnClass &inRowCol)
{
    rowIndex += inRowCol.rowIndex;
    colIndex += inRowCol.colIndex;
}

int RowColumnClass::getRow() const
{
    return rowIndex;
}

int RowColumnClass::getCol() const
{
    return colIndex;
}

void RowColumnClass::printRowCol() const
{
    std::cout << "[" << rowIndex << "," << colIndex << "]";
}
