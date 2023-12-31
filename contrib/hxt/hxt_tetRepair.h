#ifndef _HXT_TETREPAIR_
#define _HXT_TETREPAIR_


#include "hxt_mesh.h"

/**
* \file hxt_tetRepair.h Repair a tetrahedra mesh
* \author Célestin Marot
*/

/** (re-)compute the adjacency of a mesh */
HXTStatus hxtTetAdjacencies(HXTMesh* mesh);

/** orient tetrahedra correctly
 \warning The mesh cannot contain any ghost vertex */
HXTStatus hxtTetOrientNodes(HXTMesh* mesh);

/** verify the consistency of a tetrahedral mesh */
HXTStatus hxtTetVerify(HXTMesh* mesh);

/** reorder tetrahedra in a reproducible manner */
HXTStatus hxtTetReorder(HXTMesh* mesh);

/** Removes ghost tetrahedra */
HXTStatus hxtRemoveGhosts(HXTMesh* mesh);

/** Adds ghost tetrahedra to adjoin tet. whose neighbors are HXT_NO_ADJACENT.\n
 * THIS FUNCTION SUPPOSE 2 THINGS:
 *  - there are no ghost tetrahedra
 *  - face with 1 tetrahedra (neigh[face]==HXT_NO_ADJACENT) are all on the convex hull
 *
 * this function will not work properly in any other cases...
 */
HXTStatus hxtAddGhosts(HXTMesh* mesh);


#endif

