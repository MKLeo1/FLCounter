#include <boost/filesystem.hpp>
#include <algorithm>
#include <fstream>
#include <limits>
#include <string>
#include <vector>
#include <iostream>

/*****************************************************************************
 *   FLCounter helps to count the number of files and empty and non-empty
 *   lines in implemented locations on hard drive and their subfolders. M.K.
 *
 *****************************************************************************/

namespace fs = boost::filesystem;

struct DataInput;  // Holds the entered paths                                   
struct DataOutput; // Holds the result of the execution    

std::ptrdiff_t countFiles(const fs::path &);                            // counts files
std::tuple<int, int> countLines(const fs::path &);                      // counts empty & non_empty lines
std::ostream &operator<<(std::ostream &os, const DataOutput &data_out); // sends output

struct DataInput // Holds the entered paths
{
    DataInput() = default;
    DataInput(const std::vector<fs::path> &args) : paths_vector(args) {}

    std::vector<fs::path> paths_vector;
};

struct DataOutput // Holds the result of the execution
{
    int files_number, num_non_empty, num_empty;
};

int main(int argc, char **argv)
{
    try
    {
        if (argc < 2)
        {
            throw std::invalid_argument("No input path provided");
            return EXIT_FAILURE;
        };

        DataInput Input(std::vector<fs::path>(argv + 1, argv + argc));
        DataOutput Output{};

        for (const auto &path : Input.paths_vector) // calls the countFiles function for all paths
        {
            try
            {
                Output.files_number += countFiles(path);
            }
            catch (std::exception &e)
            {
                std::cerr << "Error counting files for path " << path << ": " << e.what() << "\n";
                return EXIT_FAILURE;
            }
        }

        for (const auto &path : Input.paths_vector) // calls the countLines function for all paths
        {
            try
            {
                int num_empty_lines, num_non_empty_lines;
                std::tie(num_empty_lines, num_non_empty_lines) = countLines(path);
                Output.num_empty += num_empty_lines;
                Output.num_non_empty += num_non_empty_lines;
            }
            catch (std::exception &e)
            {
                std::cerr << "Error counting lines for path " << path << ": " << e.what() << "\n";
                return EXIT_FAILURE;
            }
        }

        std::cout << Output << "\n";

        return 0;
    }
    catch (std::exception &e)
    {
        std::cerr << "Error: " << e.what() << "\n";
        return EXIT_FAILURE;
    }
}

std::ostream &operator<<(std::ostream &os, const DataOutput &data_out) // sends program output
{
    return os << "Files Number: " << data_out.files_number << ", Empty lines: " << data_out.num_empty << ", Non-empty lines: " << data_out.num_non_empty;
}

std::ptrdiff_t countFiles(const fs::path &directory) // counts files
{
    if (!fs::is_directory(directory) || !fs::exists(directory))
    {
        throw std::invalid_argument("Not a valid directory path");
    }
    return std::distance(fs::recursive_directory_iterator{directory}, {});
}

std::tuple<int, int> countLines(const fs::path &directory) // counts empty & non_empty lines
{
    if (!fs::is_directory(directory) || !fs::exists(directory))
    {
        throw std::invalid_argument("Not a valid directory path");
    }
    int num_empty{}, num_non_empty{};

    std::for_each(fs::recursive_directory_iterator(directory), {}, [&num_empty, &num_non_empty](const fs::directory_entry &path)
                  {
    std::ifstream is{path.path().string()};  
    if (!is){
        throw std::runtime_error("Failed to open file " + path.path().string());
    }
    while(is) {
      if(is.peek() == '\n') { 
        ++num_empty; 
      } else {
        ++num_non_empty; 
      }

      is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } });
    return {num_empty, num_non_empty};
}
