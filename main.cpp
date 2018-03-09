#include <iostream>
#include <deal.II/base/mpi.h>

int
main(int argc, char **argv) {
    try {
        dealii::Utilities::MPI::MPI_InitFinalize mpi(argc, argv);

        return EXIT_SUCCESS;
    } catch (std::exception &ex) {
        std::cerr << "-----------------------------------------\r\n"
                     " Error: " << ex.what() << "\r\n"
                     "-----------------------------------------\r\n\r\n" << std::flush; 
        return EXIT_FAILURE;
    } catch (...) {
        std::cerr << "-----------------------------------------\r\n"
                     " Error: Unknown error\r\n"
                     "-----------------------------------------\r\n\r\n" << std::flush; 
        return EXIT_FAILURE;
    }
}
