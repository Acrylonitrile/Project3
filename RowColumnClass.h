#ifndef ROWCOLUMNCLASS_H
#define ROWCOLUMNCLASS_H

class RowColumnClass
{
    private:
        int rowIndex;
        int colIndex;
    public:
        // Initializes object with the row and column values provided in the 
        // specifications (INITIAL_ROW_VALUE, INITIAL_COLUMN_VALUE)
        RowColumnClass();

        // Initialized object with the row and column values provided in the
        // input
        RowColumnClass(const int inRow, const int inCol);

        // Sets the row and (or) column value(s) to the value(s) provided in the
        // input
        void setRowCol(const int inRow, const int inCol);
        void setRow(const int inRow);
        void setCol(const int inCol);

        // Add the row and column values of the input RowColumnClass object to
        // the row and column values of the object the method is called on
        void addRowColTo(const RowColumnClass &inRowCol);

        // Getter functions for row and column values
        int getRow() const;
        int getCol() const;

        // Prints row and column values in the format "[<rowIndex>,<colIndex>]"
        void printRowCol() const;
};

#endif