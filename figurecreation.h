#ifndef FIGURE_CREATION_H
#define FIGURE_CREATION_H

#include "Figure.h"

/**
 * @brief Template factory function to create a specific chess figure.
 *
 * This template allows the creation of any derived class of `Figure`
 * by passing the desired type `T` along with its constructor parameters.
 *
 * Example usage:
 * @code
 * Figure* queen = createFigure<Queen>('Q', 1);
 * @endcode
 *
 * @tparam T The type of the chess figure to create (e.g., Pawn, Rook).
 * @param kind Character representing the kind of figure (e.g., 'Q' for Queen).
 * @param team Team of the figure (1 for white, 2 for black).
 * @return A pointer to the newly created figure object.
 */

template <typename T>
Figure* createFigure(char kind, int team) {
    return new T(kind, team);
}

#endif // FIGURE_CREATION_H
