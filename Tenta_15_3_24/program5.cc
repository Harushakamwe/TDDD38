#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <fstream>
#include <set>

struct Process
{
    std::string name { };
    std::vector<std::string> resources { };
};

std::ostream& operator<<(std::ostream& os, Process const& process)
{
    os << process.name << ": ";
    std::copy(std::begin(process.resources), std::end(process.resources), std::ostream_iterator<std::string>(os, " "));

    return os;
} 

std::istream& operator>>(std::istream& is, Process& process)
{
    Process result{}; 
    std::string line { };
    std::getline(is, line);
    
    std::istringstream iss { line }; 
    std::getline(iss, result.name, ':');
    std::copy(std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>{}, std::back_inserter(result.resources));

    std::sort(std::begin(result.resources), std::end(result.resources));

    process = std::move(result);
    return is;

} 


int main()
{
    std::ifstream ifs{"processes.txt"};  
    std::vector<Process> processes{ std::istream_iterator<Process>{ifs}, std::istream_iterator<Process>{} }; 

    std::cout << "Enter resources that are busy: ";
    std::set<std::string> busy_resources{ std::istream_iterator<std::string>{std::cin}, std::istream_iterator<std::string>{} };


    processes.erase(
        std::remove_if(std::begin(processes), std::end(processes),
                        [&busy_resources](Process const& p) {   std::vector<std::string> overlap{}; 
                                                                std::set_intersection( std::begin(busy_resources), std::end(busy_resources),
                                                                                        std::begin(p.resources), std::end(p.resources), std::back_inserter(overlap));
                                                                return overlap.size() > 0;
                                                            }), std::end(processes) );

    std::cout << "Processs that can run unhindered:" << std::endl;
    std::copy(std::begin(processes), std::end(processes), std::ostream_iterator<Process>{std::cout, "\n"});
        
     
}


/* Example 1:

$ ./a.out
Enter resources that are busy: disk <ctrl+D>
Processs that can run unhindered:
Web Browser: network
Print Manager: network printer
Input Handler: keyboard
Image Processing: GPU display
Video Streaming: display network speakers
Print Driver Service: printer
Photo Viewer: display
Scientific Computation Module: GPU
Text Editor: display keyboard
Network Scanning Tool: USB network
Audio Playback: speakers
System Update Service: GPU USB network
Document Conversion Tool: display printer
Graphic Design Software: GPU display
Simulation Engine: GPU
E-Mail Client: network

Example 2:

$ ./a.out 
Enter resources that are busy: network display printer GPU <ctrl+D>
Processs that can run unhindered:
Input Handler: keyboard
File Management Tool: USB disk
Audio Playback: speakers
Disk Cleaning Utility: disk

Example 3:

$ ./a.out 
Enter resources that are busy: USB speakers keyboard <ctrl+D>
Processs that can run unhindered:
Data Analysis Tool: disk network
Web Browser: network
Print Manager: network printer
Image Processing: GPU display
Print Driver Service: printer
Photo Viewer: display
Database Management System: disk network
Scientific Computation Module: GPU
Document Conversion Tool: display printer
Disk Cleaning Utility: disk
Graphic Design Software: GPU display
Simulation Engine: GPU
E-Mail Client: network*/
