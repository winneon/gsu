#include <iostream>
#include <boost/program_options.hpp>

namespace util {
    void print_help(boost::program_options::options_description options)
    {
        std::cout <<
            "Usage: gsu [OPTION]... OUTPUT\n"
            "A general screenshot and upload utility for images, video, and gifs.\n\n"
            
            "OUTPUT defaults to $XDG_CONFIG_HOME/gsu/imgs if nothing is provided.\n"
            "The most common location for $XDG_CONFIG_HOME is ~/.config.\n" 
            
            << options << std::endl; // piping `options` to stdout automatically appends a newline beforehand
    }
}