#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::findAllKeyword(QString keyword)
{

    QTextDocument *document = ui->textEdit->document();

    _found = false;


     document->undo();

     int cursorCnt = 0;

        if (keyword.isEmpty()) {
            QMessageBox::information(this, tr("Empty Search Field"),
                    "The search field is empty. Please enter a word and click Find.");
        } else {

            QTextCursor highlightCursor(document);
            QTextCursor cursor(document);


            // change All found characters in yellow background.

            cursor.beginEditBlock();

            QTextCharFormat plainFormat(highlightCursor.charFormat());
            QTextCharFormat colorFormat = plainFormat;
            colorFormat.setBackground(Qt::yellow);

            while (!highlightCursor.isNull() && !highlightCursor.atEnd()) {
                highlightCursor = document->find(keyword, highlightCursor, QTextDocument::FindCaseSensitively);

                if (!highlightCursor.isNull()) {
                    _found = true;

                    highlightCursor.movePosition(QTextCursor::Right,
                                           QTextCursor::KeepAnchor);
                    highlightCursor.mergeCharFormat(colorFormat);

                    cursorCnt++;
                }
            }
            cursor.endEditBlock();
        }

        setCursorNum(cursorCnt);
        setCursorPosition(0);

}

void MainWindow::findKeywordSequence(QString keyword)
{

    QTextDocument *document = ui->textEdit->document();


        if (keyword.isEmpty()) {
            QMessageBox::information(this, tr("Empty Search Field"),
                    "The search field is empty. Please enter a word and click Find.");
        } else {

            QTextCursor highlightCursor(document);
            QTextCursor cursor(document);


            // change All found characters in yellow background.

            cursor.beginEditBlock();

            QTextCharFormat plainFormat(highlightCursor.charFormat());
            QTextCharFormat colorFormat = plainFormat;
            QTextCharFormat previousColorFormat = plainFormat;

            colorFormat.setBackground(Qt::green);

            previousColorFormat.setBackground(Qt::yellow);


            int position = 0;
            int cursorPosition = getCursorPosition();

            if(cursorPosition==(getCursorNum()-1)) cursorPosition = 0;

            while (!highlightCursor.isNull() && !highlightCursor.atEnd()) {
                highlightCursor = document->find(keyword, highlightCursor, QTextDocument::FindCaseSensitively);

                if (!highlightCursor.isNull()) {
                    _found = true;

                    if(position == cursorPosition){

                        highlightCursor.mergeCharFormat(colorFormat);
                        setCursorPosition(cursorPosition+1);
                        highlightCursor.movePosition(QTextCursor::Right,QTextCursor::KeepAnchor);
                        ui->textEdit->setTextCursor(highlightCursor);
                    }
                    else
                        highlightCursor.mergeCharFormat(previousColorFormat);

                }
                position++;
            }
            cursor.endEditBlock();
        }

}


