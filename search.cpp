#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::findAllKeyword()
{
    QString keyword = ui->lineEdit->text();

    qDebug()<<keyword<<'\n';

    ui->textEdit->setUndoRedoEnabled(false);
    ui->textEdit->setUndoRedoEnabled(true);


    QTextDocument *document = ui->textEdit->document();

    found = true;

        if(isFirstTime==false)
            document->undo();

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
                    found = true;
                    isFirstTime = true;

                    highlightCursor.movePosition(QTextCursor::Right,
                                           QTextCursor::KeepAnchor);
                    highlightCursor.mergeCharFormat(colorFormat);
                }
            }
            cursor.endEditBlock();
        }
}

void MainWindow::findKeywordSequence()
{

}
