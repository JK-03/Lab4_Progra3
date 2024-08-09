#ifndef TAREADIARIA_H
#define TAREADIARIA_H

#include "Tarea.h"

class TareaDiaria : public Tarea {
public:
    TareaDiaria(const QString& descripcion, const QDate& fecha);

    QString tipo() const override;
};

#endif // TAREADIARIA_H
