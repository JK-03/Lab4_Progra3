#ifndef COMANDOSUBRAYADO_H
#define COMANDOSUBRAYADO_H

#include "ComandoFormato.h"

class ComandoSubrayado : public ComandoFormato
{
public:
    void aplicar(QTextCursor &cursor) const override;
};

#endif // COMANDOSUBRAYADO_H
