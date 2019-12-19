#include <iostream>
#include <exception>

#include <boost/program_options.hpp>

#include "util.hpp"

int handle_cmdline_options(int argc, char *argv[])
{
    namespace po = boost::program_options;

    po::options_description cmdline_options;

    po::options_description general_options("GENERAL OPTIONS");
    po::options_description utility_options("UTILITY OPTIONS");
    po::options_description capture_options("CAPTURE OPTIONS");
    po::options_description screenshot_options("SCREENSHOT OPTIONS");
    po::options_description video_options("VIDEO OPTIONS");

    general_options.add_options()
        ("help,h",
            "Show the help menu.")
        ("version,v",
            "Show the current version.")
        ("list-displays,l",
            "List your current displays and their resolutions.")
        ("upload,u",
            "Upload after running the utility.")
        ("terminal",
            "Open interactive commands in a new terminal.\n"
            "SET THIS IF RUNNING FROM ANYTHING OTHER THAN A TERM, i.e. xbindkeys")
        ("hide",
            "Minimize the current window while capturing.\n"
            "This is useful when running with --terminal to hide the newly opened term.")
        ("notify",
            "Send a libnotify notification of the output.")
    ;

    utility_options.add_options()
        ("dmenu,r",
            "Enable dmenu or rofi integration.")
        ("screenshot,s",
            "Take a screenshot. (default)")
        ("video,m",
            "Record a video of the screen.")
        ("gif,g",
            "Record a video and convert it to the gif format.")
    ;

    capture_options.add_options()
        ("no-cursor,n",
            "Hide the cursor.")
        ("display,d",
            po::value<std::string>()->value_name("NUM|TYPE"),
            "Set the selection to a specific display.\n"
            "Can read from an argument or from stdin.\n"
            "Values: number of display, 'active', 'all' (default)")
    ;

    screenshot_options.add_options()
        ("no-opengl,o",
            "Disable OpenGL hardware-accelerated capture.")
    ;

    video_options.add_options()
        ("countdown,c",
            po::value<int>()->value_name("NUM"),
            "Count down before recording.")
    ;

    cmdline_options
        .add(general_options)
        .add(utility_options)
        .add(capture_options)
        .add(screenshot_options)
        .add(video_options)
    ;

    po::variables_map vm;

    try
    {
        po::store(po::parse_command_line(argc, argv, cmdline_options), vm);
        po::notify(vm);
    }
    catch (std::exception &e)
    {
        std::cerr << "gsu: " << e.what() << std::endl;
        return 1;
    }

    if (vm.count("help"))
    {
        util::print_help(cmdline_options);
        return 0;
    }

    return 0;
}

int main(int argc, char *argv[])
{
    int code = handle_cmdline_options(argc, argv);

    if (code > 0)
    {
        return code;
    }

    return 0;
}