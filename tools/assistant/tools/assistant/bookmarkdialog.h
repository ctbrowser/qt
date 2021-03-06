/****************************************************************************
**
** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/
**
** This file is part of the Qt Assistant of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this
** file. Please review the following information to ensure the GNU Lesser
** General Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU General
** Public License version 3.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of this
** file. Please review the following information to ensure the GNU General
** Public License version 3.0 requirements will be met:
** http://www.gnu.org/copyleft/gpl.html.
**
** Other Usage
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/
#ifndef BOOKMARKDIALOG_H
#define BOOKMARKDIALOG_H

#include "ui_bookmarkdialog.h"

QT_BEGIN_NAMESPACE

class BookmarkModel;
class BookmarkFilterModel;
class BookmarkTreeModel;

class BookmarkDialog : public QDialog
{
    Q_OBJECT
public:
    BookmarkDialog(BookmarkModel *bookmarkModel, const QString &title,
        const QString &url, QWidget *parent = 0);
    ~BookmarkDialog();

private:
    bool isRootItem(const QModelIndex &index) const;
    bool eventFilter(QObject *object, QEvent *event);

private slots:
    void currentIndexChanged(int index);
    void currentIndexChanged(const QModelIndex &index);

    void accepted();
    void rejected();

    void addFolder();
    void toolButtonClicked();
    void textChanged(const QString& text);
    void customContextMenuRequested(const QPoint &point);

private:
    QString m_url;
    QString m_title;
    Ui::BookmarkDialog ui;
    QList<QPersistentModelIndex> cache;

    BookmarkModel *bookmarkModel;
    BookmarkTreeModel *bookmarkTreeModel;
    BookmarkFilterModel *bookmarkProxyModel;
};

QT_END_NAMESPACE

#endif  // BOOKMARKDIALOG_H
