#include <string>
#include <iostream>
#include <fstream>

static void read_and_replace(std::ifstream &infile, std::ofstream &outfile, std::string s1, std::string s2)
{
    std::string line;
    while (getline(infile, line))
    {
        std::string new_line;
        size_t pos = 0;
        size_t found = line.find(s1, pos);
        while (found != std::string::npos)
        {
            new_line.append(line, pos, found - pos);
            new_line.append(s2);
            pos = found + s1.length();
            found = line.find(s1, pos);
        }
        new_line.append(line, pos, line.length() - pos);
        outfile << new_line << "\n";
        // std::cout << new_line << "\n";
    }
}

int main(int argc, char **argv)
{
    if (argc < 4)
    {
        std::cerr << "Usage: " << argv[0] << " <input_file> <string_to_replace> <replacement_string>" << std::endl;
        return (1);
    }
    std::ifstream infile(argv[1]);
    if (!infile.is_open())
    {
        std::cerr << argv[1] << " couldn't be open" << std::endl;
        return (1);
    }
    std::ofstream outfile(std::string(argv[1]).append(".replace").c_str(), std::ios::trunc);
    if (!outfile.is_open())
    {
        std::cerr << argv[1] << ".replace couldn't be open" << std::endl;
        return (1);
    }
    read_and_replace(infile, outfile, argv[2], argv[3]);
    return (0);
}