#ifndef HALIDE_SIMPLIFY_H
#define HALIDE_SIMPLIFY_H

/** \file
 * Methods for simplifying halide statements and expressions
 */

#include "IR.h"
#include "Bounds.h"
#include "ModulusRemainder.h"

namespace Halide {
namespace Internal {

/** Perform a a wide range of simplifications to expressions and
 * statements, including constant folding, substituting in trivial
 * values, arithmetic rearranging, etc. Simplifies across let
 * statements, so must not be called on stmts with dangling or
 * repeated variable names.
 */
// @{
Stmt simplify(Stmt, bool remove_dead_lets = true,
              const Scope<Interval> &bounds = Scope<Interval>::empty_scope(),
              const Scope<ModulusRemainder> &alignment = Scope<ModulusRemainder>::empty_scope());
Expr simplify(Expr, bool remove_dead_lets = true,
              const Scope<Interval> &bounds = Scope<Interval>::empty_scope(),
              const Scope<ModulusRemainder> &alignment = Scope<ModulusRemainder>::empty_scope());
// @}

/** A common use of the simplifier is to prove boolean expressions are
 * true at compile time. Equivalent to is_one(simplify(e)) */
bool can_prove(Expr e);

/** Simplify expressions found in a statement, but don't simplify
 * across different statements. This is safe to perform at an earlier
 * stage in lowering than full simplification of a stmt. */
Stmt simplify_exprs(Stmt);

void simplify_test();

}
}

#endif
