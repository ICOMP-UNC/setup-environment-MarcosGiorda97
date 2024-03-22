#include <greetings.h>
#include <stdio.h>
#include <static.h>
#include <shared.h>

int main(int argc, char* argv[])
{
    printf("Hello OS II\n");
    greetings();

    printf("....\n");
    printf("Calling shared lib from main program. I get '%d'\n",shared_lib_function("Hello, OS II.."));
    printf("Calling static lib from main program. I get '%d'\n",static_lib_function("Bye bye, OS II.."));

    return 0;
}
