#include <iostream>
#include <boost/filesystem.hpp>

uintmax_t get_directory_size(const boost::filesystem::path& dir_path) {
    uintmax_t size = 0;
    for (boost::filesystem::recursive_directory_iterator it(dir_path);
         it != boost::filesystem::recursive_directory_iterator(); ++it) {
        if (!boost::filesystem::is_directory(*it)) {
            size += boost::filesystem::file_size(*it);
        }
    }
    return size;
}

int main() {
    string path = "";
    std::cin>>path;
    boost::filesystem::path dir_path(path);
    uintmax_t size = get_directory_size(dir_path);
    std::cout << "Directory size: " << size << " bytes\n";
    return 0;
}
