#ifndef MOVEMENTLIBRARY_H
#define MOVEMENTLIBRARY_H

#include <QObject>

class MovementLibrary: public QObject
{
    Q_OBJECT

public:
    explicit MovementLibrary(QObject *parent = 0);

public slots:

    /**
     * @brief Move robot forward for specified distance
     * @param distance in milimeters
     */
    void move(double distance);

    /**
     * @brief Move robot forward for specified distance
     * @param distance in milimeters
     */
    void moveBack(double distance);

    /**
     * @brief Stop any movement
     */
    void stop();

    /**
     * @brief Rotate robot clockwise on specified angle
     *        Rotate contr-clockwise if angle is negative
     * @param angle in radians
     */
    void rotate(double angle);
};

#endif // MOVEMENTLIBRARY_H
