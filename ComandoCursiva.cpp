// ComandoCursiva.cpp
#include "ComandoCursiva.h"
#include <QTextCharFormat>

void ComandoCursiva::aplicar(QTextCursor &cursor) const
{
    QTextCharFormat format;
    format.setFontItalic(true);
    cursor.setCharFormat(format);
}
