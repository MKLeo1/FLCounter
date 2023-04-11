<h1>FLCounter</h1>

<h2>Author's Note:</h2>

FilesLinesCounter is a form of exercise to gain practical coding skills and knowledge in the field of C ++.

M.K.

<h2>Overview</h2>

FLCounter is a program written in C++ that helps count the number of files, empty and non-empty lines in provided paths on your hard drive and their subfolders.
The library program uses Boost.Filesystem to search files on disk and calculate lines in each file.

<h2>Additional library added</h2>

<boost/filesystem.hpp>: provides operations on files and directories, such as path resolution, iteration, and manipulation.
  
<h2>Namespace</h2>
The code defines the fs namespace, which is an alias for the boost::filesystem namespace. The boost::filesystem library provides facilities for working with files and directories.
  
<h2>Structs</h2>
DataInput holds the entered paths, which are provided as command-line arguments. The constructor of DataInput takes a vector of fs::path objects as input.

DataOutput holds the results of the program execution. It has three members:

1. files_number: the total number of files found in the specified paths
2. num_non_empty: the total number of non-empty lines found in the specified paths
3. num_empty: the total number of empty lines found in the specified paths
  
<h2>Functions</h2>
  
The code defines three functions: countFiles, countLines, and operator<<.

countFiles takes an fs::path object as input and returns the number of files found in the specified directory and its subdirectories. If the specified path is not a valid directory, the function throws an invalid_argument exception.

countLines takes an fs::path object as input and returns a tuple containing the number of empty and non-empty lines found in the specified directory and its subdirectories. If the specified path is not a valid directory, the function throws an invalid_argument exception. The function uses std::for_each to iterate over all files in the directory and its subdirectories, and uses an std::ifstream object to read the contents of each file. It counts the number of empty and non-empty lines in each file using a loop that reads each line of the file and checks whether it is empty or non-empty. If the file cannot be opened, the function throws a runtime_error exception.

operator<< takes an output stream (std::ostream) and a DataOutput object as input, and sends the program output to the output stream. The function returns the output stream.

<h2>Main</h2>

The main function first checks if at least one command-line argument was provided, and if not, it throws an invalid_argument exception. It then creates a DataInput object, which holds the entered paths, by constructing it with a vector of paths parsed from the command-line arguments.

The function then initializes a DataOutput object, which holds the result of the execution, and iterates through each path in the DataInput object. For each path, it calls the countFiles function to count the number of files and the countLines function to count the number of empty and non-empty lines. If an exception occurs during these calls, the function catches it and returns EXIT_FAILURE.

After iterating through all the paths, the main function outputs the results stored in the DataOutput object by overloading the << operator to print to the console.

If any exceptions are thrown during the execution of the program, the main function catches them and prints an error message to the console before exiting with a failure code.

<h2>Manual compilation:</h2>
  
Some Boost libraries like filesystem need to be linked separately. Manual compilation example:
g++ -g -Wall -o FLCounter FLcounter.cpp -L/insert/here/lib/path -lboost_filesystem
  
  
  
