// ComandoCursiva.h
#ifndef COMANDOCURSIVA_H
#define COMANDOCURSIVA_H

#include "ComandoFormato.h"
#include <QTextCursor>

class ComandoCursiva : public ComandoFormato
{
public:
    void aplicar(QTextCursor &cursor) const override;
};

#endif // COMANDOCURSIVA_H
