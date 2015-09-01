# Imports
import sys
import getopt
import random

# Constant
TXT_FLAGS = "-f [file_dir] -cl [number_of_columns] -t [number_of_tests] -z [exit_with_zero?]" 
FLAGS = "f= cl= t= z="

# Generate a random number between 'a' and 'b'
def gen_random(a, b):
    rand = random.uniform(a,b)
    return rand

# Main generation function
def gen(file, numof_column, numof_tests, input_exit):
    print "Opening file..."
    fl = open(file,"r+")

    # When stops with a input like 0 0 0 0
    if(input_exit):
        print "Stops with 0 0 0 0"
    else:
        print "Runs " + str(numof_tests) + " tests"

# Getting the inputs from terminal
def gets_opts():
    # Gets user inputs
    try:
        opts, args = getopt.getopt(sys.argv[1:],"", FLAGS.split())
    except getopt.GetoptError as error:
        print_error()
    return opts

# Print a input error
def print_error():
    print str("python randnum.py " + TXT_FLAGS)
    sys.exit(2)

# Generator main
def generator(): 
    opts = gets_opts()
    file = ""
    numof_column = ""
    numof_tests = ""
    input_exit = ""

    # Locate the inputs on var
    for option, attribute in opts:
        if(option == "-f"):
            file = attribute
        elif(option == "-cl"):
            numof_column = int(attribute)
        elif(option == "-t"):
            numof_tests = int(attribute)
        elif(option == "-z"):
            if(attribute.lower() == "true"):
                input_exit = True
            elif(attribute.lower() == "false"):
                input_exit = False
            else:
                print_error()

    print(file + numof_column + numof_tests + input_exit)

    if (file == ''):
        print_error()

    # Execute generator
    gen(file, numof_column, numof_tests, input_exit)

def main():
    generator()

if __name__ == '__main__':
    main()
