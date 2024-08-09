#include "ComandoSubrayado.h"
#include <QTextCursor>
#include <QTextCharFormat>

void ComandoSubrayado::aplicar(QTextCursor &cursor) const
{
    QTextCharFormat format;
    format.setFontUnderline(true);
    cursor.setCharFormat(format);
}
