/* Copyright (c) 2019-2022 hors<horsicq@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#ifndef GUIMAINWINDOW_H
#define GUIMAINWINDOW_H

#include <QMainWindow>

#include "../global.h"
#include <QDragEnterEvent>
#include <QFileDialog>
#include <QMainWindow>
#include <QMimeData>
#include "dialogabout.h"
#include "dialogoptions.h"
#include "dialogshortcuts.h"
#include "elfwidget.h"

namespace Ui {
class GuiMainWindow;
}

class GuiMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GuiMainWindow(QWidget *pParent=nullptr);
    ~GuiMainWindow();

private slots:
    void on_actionOpen_triggered();
    void on_actionClose_triggered();
    void on_actionExit_triggered();
    void on_actionDemangle_triggered();
    void on_actionShortcuts_triggered();
    void on_actionOptions_triggered();
    void on_actionAbout_triggered();
    void adjustWindow();
    void processFile(QString sFileName);
    void closeCurrentFile();

protected:
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void dropEvent(QDropEvent *event) override;

private:
    Ui::GuiMainWindow *ui;
    XOptions g_xOptions;
    XShortcuts g_xShortcuts;
    FW_DEF::OPTIONS g_formatOptions;

    QFile *g_pFile;
};

#endif // GUIMAINWINDOW_H
