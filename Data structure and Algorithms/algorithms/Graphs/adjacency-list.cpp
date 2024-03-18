#include <iostream>
#include <fstream>
#include <vector>
#include <random>

int main()
{
    int num_nodes = 100;        // Number of nodes (adjust as needed)
    int max_edges_per_node = 5; // Maximum edges per node (adjust as needed)

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1, num_nodes);

    // Open the output file
    std::ofstream outfile("input.txt");
    if (!outfile.is_open())
    {
        std::cerr << "Error opening input.txt\n";
        return 1;
    }

    // Write the number of nodes to the file
    outfile << num_nodes << "\n";

    // Generate adjacency list and write to file
    for (int i = 1; i <= num_nodes; ++i)
    {
        int num_edges = distrib(gen) % max_edges_per_node + 1; // Random edges
        outfile << i << " ";

        for (int j = 0; j < num_edges; ++j)
        {
            int neighbor = distrib(gen);
            while (neighbor == i)
            { // Avoid self-loops
                neighbor = distrib(gen);
            }
            outfile << neighbor << " ";
        }
        outfile << "\n";
    }

    outfile.close();
    std::cout << "Adjacency list generated in input.txt\n";
    return 0;
}
