#include <string>
namespace pex {
std::string get_home_directory () {
    // get home directory Unix
    const char* homeDir = getenv("HOME");
    // Get home directory on Windows (untested)
    const char* userProfile = getenv("USERPROFILE");
    std::string result = "";
    if (homeDir != nullptr) {
        result = homeDir;
    } else if (userProfile != nullptr) {
        result = userProfile;
    }
    return(result);
}
};
#ifdef PEXI
// to run this compile with:
// g++ -DPEXI pex.cpp -o pexi
int main() {
    std::cout << pex::LYELLOW << "file functions checks\n" << pex::RESET;
    std::cout << "PEX Home: " << pex::get_home_directory()
        << std::endl;
    return(0);
}
#endif



