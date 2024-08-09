// ComandoFormato.h
#ifndef COMANDOINTERFACE_H
#define COMANDOINTERFACE_H

#include <QTextCursor>

class ComandoFormato
{
public:
    virtual ~ComandoFormato() = default;
    virtual void aplicar(QTextCursor &cursor) const = 0; // Método virtual puro
};

#endif // COMANDOINTERFACE_H
