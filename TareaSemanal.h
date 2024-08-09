#ifndef TAREASEMANAL_H
#define TAREASEMANAL_H

#include "Tarea.h"

class TareaSemanal : public Tarea {
public:
    TareaSemanal(const QString& descripcion, const QDate& fecha);

    QString tipo() const override;
};

#endif // TAREASEMANAL_H
