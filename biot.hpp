#ifndef BIOT_BIOT_HPP_
#define BIOT_BIOT_HPP_ 1

#include <string>
#include <deal.II/distributed/tria.h>
#include <deal.II/fe/fe_system.h>
#include <deal.II/dofs/dof_handler.h>
#include <deal.II/lac/trilinos_parallel_block_vector.h>
#include <deal.II/lac/trilinos_block_sparse_matrix.h>


namespace biot {

template <int dim>
class Problem {
public:
    void generate_mesh();
    void distribute_dofs(unsigned int degree);
    void assemble_system();
    void set_initial_condition();
    void step(double dt);
    void save_solution(const std::string &filename);

private:
    using Triangulation = dealii::parallel::distributed::Triangulation<dim>;
    using FESystem = dealii::FESystem<dim>;
    using DoFHandler = dealii::DoFHandler<dim>;
    using BlockSparseMatrix = dealii::TrilinosWrappers::BlockSparseMatrix;
    using BlockVector = dealii::TrilinosWrappers::MPI::BlockVector;

    Triangulation tria_;

    FESystem displacement_fe_,
             pressure_fe_,
             fe_;

    DoFHandler dofs_;

    BlockSparseMatrix system_matrix_;
    BlockVector system_rhs_,
                system_solution_,
                solution_,
                solution_old_;
};

} // namespace biot

#endif // BIOT_BIOT_HPP_
