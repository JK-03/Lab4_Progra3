#ifndef COMANDONEGRITA_H
#define COMANDONEGRITA_H

#include "ComandoFormato.h"

class ComandoNegrita : public ComandoFormato
{
public:
    void aplicar(QTextCursor &cursor) const override;
};

#endif // COMANDONEGRITA_H
