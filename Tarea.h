#ifndef TAREA_H
#define TAREA_H

#include <QString>
#include <QDate>

class Tarea {
public:
    Tarea(const QString& descripcion, const QDate& fecha);
    virtual ~Tarea() = default;

    QString descripcion() const;
    QDate fecha() const;

    virtual QString tipo() const = 0; // Método virtual puro

private:
    QString m_descripcion;
    QDate m_fecha;
};

#endif // TAREA_H
