# Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

# HXT (reparametrization)
set(SRC
  hxt_context.cpp
  hxt_curvature.cpp
  hxt_edge.cpp
  hxt_laplace.cpp
  hxt_linear_system.cpp
  hxt_linear_system_lu.cpp
  hxt_linear_system_petsc.cpp
  hxt_mean_values.cpp
  hxt_mesh.cpp
  hxt_message.cpp
  hxt_parametrization.cpp
  hxt_tools.cpp
 )

# HXT3D (3D meshing)
if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/hxt_tetDelaunay.cpp)
set(SRC ${SRC}
  hxt_bbox.cpp
  hxt_boundary_recovery.cxx
  hxt_mesh3d.cpp
  hxt_mesh3d_main.cpp
  hxt_mesh_size.cpp
  hxt_opt.cpp
  hxt_option.cpp
  hxt_sort.cpp
  hxt_tetColor.cpp
  hxt_tetDelaunay.cpp
  hxt_tetFlag.cpp
  hxt_tetOpti.cpp
  hxt_tetPostpro.cpp
  hxt_tetRepair.cpp
  hxt_tetUtils.cpp
  hxt_tet_aspect_ratio.cpp
  hxt_vertices.cpp
  hxt_octree.cpp
  predicates.cpp
)
endif()

# do not use arithmetic contraction in predicates.cpp
if("x${CMAKE_C_COMPILER_ID}" STREQUAL "xMSVC" )
  set_source_files_properties(predicates.cpp PROPERTIES COMPILE_FLAGS
                              "/fp:strict")
endif()
if(CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
  set_source_files_properties(predicates.cpp PROPERTIES COMPILE_FLAGS
                              "-fno-unsafe-math-optimizations -ffp-contract=off")
endif()
if(CMAKE_C_COMPILER_ID STREQUAL "Intel")
 set_source_files_properties(predicates.cpp PROPERTIES COMPILE_FLAGS
                             "-fp-model strict")
endif()

file(GLOB_RECURSE HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)
append_gmsh_src(contrib/hxt "${SRC};${HDR}")
